#ifndef ROUTE_H
#define ROUTE_H

#include <string>

class Route {
private:
    std::string routeName;
    int totalSeats;
    int availableSeats;

public:
    Route(const std::string& name, int seats)
        : routeName(name), totalSeats(seats), availableSeats(seats) {}

    const std::string& getRouteName() const {
        return routeName;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    void reserveSeats(int count) {
        availableSeats -= count;
    }
};

#endif
