#include "state_manager.h"
#include "alert_service.h"
#include <sstream>
#include <unistd.h>

void StateManager::processVitalMessage(const std::string& msg) {
    std::stringstream ss(msg);
    std::string patientId;
    float hr, spo2, temp;

    getline(ss, patientId, ',');
    ss >> hr; ss.ignore();
    ss >> spo2; ss.ignore();
    ss >> temp;

    std::lock_guard<std::mutex> lock(mtx);

    auto& state = patients[patientId];
    state.latestVitals = {hr, spo2, temp, time(nullptr)};
    state.deviceConnected = true;
    state.lastSeen = time(nullptr);

    AlertService::evaluate(patientId, state.latestVitals);
}

bool StateManager::getPatientSnapshot(const std::string& patientId, PatientState& out) {
    std::lock_guard<std::mutex> lock(mtx);
    if (patients.count(patientId) == 0) return false;
    out = patients[patientId];
    return true;
}

void StateManager::monitorTimeouts() {
    while (true) {
        sleep(5);
        time_t now = time(nullptr);

        std::lock_guard<std::mutex> lock(mtx);
        for (auto& [id, state] : patients) {
            if (now - state.lastSeen > 10)
                state.deviceConnected = false;
        }
    }
}
