#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>

#define PORT 9090

using namespace std;

struct TelemetryPacket {
    int vehicleId;
    int speed;
    int rpm;
    float temperature;
    long timestamp;
    int priority;
};

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        cerr << "ERROR: Failed to create UDP socket\n";
        return 1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) <= 0) {
        cerr << "ERROR: Invalid server IP address\n";
        close(sockfd);
        return 1;
    }

    TelemetryPacket pkt{};
    cout << "Enter Vehicle ID: ";
    cin >> pkt.vehicleId;

    if (pkt.vehicleId <= 0) {
        cerr << "ERROR: Vehicle ID must be positive\n";
        close(sockfd);
        return 1;
    }

    srand(time(nullptr));

    while (true) {
        pkt.speed = rand() % 200;
        pkt.rpm = rand() % 8000;
        pkt.temperature = 60 + rand() % 50;
        pkt.timestamp = time(nullptr);
        pkt.priority = (pkt.temperature > 95) ? 1 : 0;

        ssize_t sent = sendto(sockfd, &pkt, sizeof(pkt), 0,
                              (sockaddr*)&serverAddr, sizeof(serverAddr));

        if (sent != sizeof(pkt)) {
            cerr << "ERROR: Failed to send telemetry packet\n";
        } else {
            cout << "Sent | Speed=" << pkt.speed
                 << " RPM=" << pkt.rpm
                 << " Temp=" << pkt.temperature
                 << (pkt.priority ? " [CRITICAL]" : "") << endl;
        }

        sleep(1);
    }

    close(sockfd);
    return 0;
}
