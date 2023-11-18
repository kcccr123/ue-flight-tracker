#include "Airline.h"
#include "Flight.h"

Airline::Airline(const char* icao)
{
    this->icao = icao;
    this->flights = nullptr;
};

int Airline::addFlight(Flight *flight)
{
    try
    {
        this->flights.Emplace(flight);
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}

TArray<Flight*> Airline::getFlights()
{
    return this->flights;
};
