#include <iostream>
#include <unordered_map>
#include <deque>
#include <fstream>
#include <ctime>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORT 9090
#define MAX_BUFFER 50
#define ARCHIVE_LIMIT 100

using namespace std;

/* ================= LOGGER ================= */
ofstream logFile;

void logMsg(const string& msg) {
    time_t now = time(nullptr);
    logFile << ctime(&now) << " : " << msg << endl;
}

/* ================= PACKET ================= */
struct TelemetryPacket {
    int vehicleId;
    int speed;
    int rpm;
    float temperature;
    long timestamp;
    int priority;
};

/* ================= STORAGE ================= */
unordered_map<int, deque<TelemetryPacket>> vehicleBuffers;
unordered_map<int, int> packetCount;

/* ================= VALIDATION ================= */
bool validatePacket(const TelemetryPacket& pkt) {
    if (pkt.vehicleId <= 0) {
        logMsg("ERROR: Invalid vehicle ID received");
        return false;
    }
    if (pkt.speed < 0 || pkt.speed > 350) {
        logMsg("ERROR: Invalid speed value");
        return false;
    }
    if (pkt.rpm < 0 || pkt.rpm > 10000) {
        logMsg("ERROR: Invalid RPM value");
        return false;
    }
    if (pkt.temperature < -40 || pkt.temperature > 200) {
        logMsg("ERROR: Invalid temperature value");
        return false;
    }
    return true;
}

/* ================= FILE ARCHIVE ================= */
bool archiveToFile(int vehicleId) {
    string filename = "vehicle_" + to_string(vehicleId) + ".txt";
    ofstream file(filename, ios::app);

    if (!file.is_open()) {
        logMsg("FATAL: Unable to open archive file for vehicle " + to_string(vehicleId));
        return false;
    }

    for (auto& pkt : vehicleBuffers[vehicleId]) {
        file << pkt.timestamp << ", "
             << pkt.speed << ", "
             << pkt.rpm << ", "
             << pkt.temperature << ", "
             << (pkt.priority ? "CRITICAL" : "NORMAL") << endl;

        if (!file) {
            logMsg("ERROR: Failed writing telemetry to file for vehicle " + to_string(vehicleId));
            file.close();
            return false;
        }
    }

    file.close();
    vehicleBuffers[vehicleId].clear();
    logMsg("Archived telemetry to file for vehicle " + to_string(vehicleId));
    return true;
}

/* ================= MAIN ================= */
int main() {
    logFile.open("telemetry.log", ios::app);
    if (!logFile.is_open()) {
        cerr << "FATAL ERROR: Unable to open telemetry.log\n";
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        cerr << "FATAL ERROR: UDP socket creation failed\n";
        return 1;
    }

    if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0) {
        cerr << "ERROR: Failed to set non-blocking mode\n";
        close(sockfd);
        return 1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(sockfd, (sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        cerr << "FATAL ERROR: Port bind failed\n";
        close(sockfd);
        return 1;
    }

    cout << "Telemetry Server running on UDP port " << PORT << endl;
    logMsg("Telemetry Server Started");

    while (true) {
        TelemetryPacket pkt{};
        sockaddr_in clientAddr{};
        socklen_t len = sizeof(clientAddr);

        ssize_t bytes = recvfrom(sockfd, &pkt, sizeof(pkt), 0,
                                 (sockaddr*)&clientAddr, &len);

        if (bytes < 0) {
            if (errno != EAGAIN && errno != EWOULDBLOCK) {
                logMsg("ERROR: recvfrom failed unexpectedly");
            }
            usleep(50000);
            continue;
        }

        if (bytes != sizeof(pkt)) {
            logMsg("WARNING: Incomplete telemetry packet received");
            continue;
        }

        if (!validatePacket(pkt)) {
            logMsg("WARNING: Telemetry packet dropped due to validation failure");
            continue;
        }

        auto& buffer = vehicleBuffers[pkt.vehicleId];

        if (buffer.size() >= MAX_BUFFER) {
            buffer.pop_front();  // circular buffer behavior
        }

        buffer.push_back(pkt);
        packetCount[pkt.vehicleId]++;

        if (pkt.priority == 1) {
            logMsg("CRITICAL: High priority packet from vehicle " + to_string(pkt.vehicleId));
        }

        if (packetCount[pkt.vehicleId] >= ARCHIVE_LIMIT) {
            if (!archiveToFile(pkt.vehicleId)) {
                logMsg("ERROR: Archival failed for vehicle " + to_string(pkt.vehicleId));
            }
            packetCount[pkt.vehicleId] = 0;
        }
    }

    close(sockfd);
    logFile.close();
    return 0;
}
