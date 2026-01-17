#include <iostream>
#include "BusReservationSystem.h"

int main() {
    BusReservationSystem system;

    try {
        system.displayRoutes();

        system.bookSeats("Kolkata-Durgapur", 5);
        system.bookSeats("Delhi-Jaipur", 10);

        // Uncomment to test exceptions
        // system.bookSeats("Mumbai-Goa", 2);
        // system.bookSeats("Kolkata-Siliguri", 50);

        system.displayRoutes();
    }
    catch (const ReservationException& ex) {
        std::cerr << "❌ Reservation Error: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "❌ Unknown error occurred." << std::endl;
    }

    return 0;
}
