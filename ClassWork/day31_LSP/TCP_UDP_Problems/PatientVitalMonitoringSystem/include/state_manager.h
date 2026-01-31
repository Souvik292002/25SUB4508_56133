#pragma once
#include <unordered_map>
#include <mutex>
#include <string>
#include <ctime>
#include "thresholds.h"

struct VitalData {
    float heartRate;
    float spo2;
    float temperature;
    time_t timestamp;
};

struct PatientState {
    VitalData latestVitals;
    bool deviceConnected;
    time_t lastSeen;
};

class StateManager {
private:
    std::unordered_map<std::string, PatientState> patients;
    std::mutex mtx;
    Thresholds thresholds;

public:
    void processVitalMessage(const std::string& msg);
    bool getPatientSnapshot(const std::string& patientId, PatientState& out);
    void monitorTimeouts();
};
