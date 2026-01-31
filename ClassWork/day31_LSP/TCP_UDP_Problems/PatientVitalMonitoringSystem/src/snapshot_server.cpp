#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include "state_manager.h"

#define SNAPSHOT_PORT 9200

void startSnapshotServer(StateManager& stateManager) {
    int serverSock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SNAPSHOT_PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSock, (sockaddr*)&addr, sizeof(addr));
    listen(serverSock, 5);

    while (true) {
        int client = accept(serverSock, nullptr, nullptr);

        char patientId[128];
        int n = recv(client, patientId, sizeof(patientId) - 1, 0);
        patientId[n] = '\0';

        PatientState state;
        std::string response;

        if (stateManager.getPatientSnapshot(patientId, state)) {
            response = "HR=" + std::to_string(state.latestVitals.heartRate) +
                       ", SPO2=" + std::to_string(state.latestVitals.spo2) +
                       ", TEMP=" + std::to_string(state.latestVitals.temperature);
        } else {
            response = "Patient not found";
        }

        send(client, response.c_str(), response.size(), 0);
        close(client);
    }
}
