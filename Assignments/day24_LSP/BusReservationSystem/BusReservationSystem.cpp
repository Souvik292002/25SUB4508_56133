#include "BusReservationSystem.h"
#include <iostream>

BusReservationSystem::BusReservationSystem() {
    // Preload routes (real systems load from DB or config)
    addRoute("Kolkata-Durgapur", 40);
    addRoute("Kolkata-Siliguri", 30);
    addRoute("Delhi-Jaipur", 25);
}

void BusReservationSystem::addRoute(const std::string& routeName, int seats) {
    routes.emplace(routeName, Route(routeName, seats));
}

void BusReservationSystem::bookSeats(const std::string& routeName, int travelers) {
    auto it = routes.find(routeName);

    if (it == routes.end()) {
        throw RouteUnavailableException(routeName);
    }

    Route& route = it->second;

    if (travelers > route.getAvailableSeats()) {
        throw SeatCapacityExceededException(
            travelers, route.getAvailableSeats());
    }

    route.reserveSeats(travelers);

    std::cout << "✅ Booking successful on route: " << routeName
              << " | Seats booked: " << travelers << "\n";
}

void BusReservationSystem::displayRoutes() const {
    std::cout << "\nAvailable Routes:\n";
    for (const auto& pair : routes) {
        std::cout << "Route: " << pair.first
                  << " | Available Seats: "
                  << pair.second.getAvailableSeats() << "\n";
    }
}
