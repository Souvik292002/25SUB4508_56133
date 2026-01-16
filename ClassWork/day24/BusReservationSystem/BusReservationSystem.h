#ifndef BUS_RESERVATION_SYSTEM_H
#define BUS_RESERVATION_SYSTEM_H

#include <unordered_map>
#include <string>
#include "Route.h"
#include "Exceptions.h"

class BusReservationSystem {
private:
    std::unordered_map<std::string, Route> routes;

public:
    BusReservationSystem();

    void addRoute(const std::string& routeName, int seats);
    void bookSeats(const std::string& routeName, int travelers);
    void displayRoutes() const;
};

#endif
