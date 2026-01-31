#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

// Base class for all reservation-related exceptions
class ReservationException : public std::exception {
protected:
    std::string message;

public:
    explicit ReservationException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Thrown when a route does not exist
class RouteUnavailableException : public ReservationException {
public:
    explicit RouteUnavailableException(const std::string& route)
        : ReservationException("Route unavailable: " + route) {}
};

// Thrown when requested seats exceed available seats
class SeatCapacityExceededException : public ReservationException {
public:
    SeatCapacityExceededException(int requested, int available)
        : ReservationException(
              "Seat capacity exceeded. Requested: " +
              std::to_string(requested) +
              ", Available: " +
              std::to_string(available)) {}
};

#endif
