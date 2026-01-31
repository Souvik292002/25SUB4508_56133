#include "alert_service.h"
#include <arpa/inet.h>
#include <unistd.h>

#define ALERT_PORT 9100

void AlertService::evaluate(const std::string& patientId, const VitalData& v) {
    if (v.heartRate > 120 || v.heartRate < 40 ||
        v.spo2 < 90 || v.temperature > 39) {

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) return;

        sockaddr_in addr{};
        addr.sin_family = AF_INET;
        addr.sin_port = htons(ALERT_PORT);
        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

        if (connect(sock, (sockaddr*)&addr, sizeof(addr)) == 0) {
            std::string alert = "ALERT: Patient " + patientId;
            send(sock, alert.c_str(), alert.size(), 0);
        }

        close(sock);
    }
}
