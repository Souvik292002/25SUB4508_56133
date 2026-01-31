#pragma once
#include <string>
#include "state_manager.h"

class AlertService {
public:
    static void evaluate(const std::string& patientId, const VitalData& vitals);
};
