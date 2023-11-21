#include "Airline.h"
#include "Flight.h"

Airline::Airline(FString icao)
{
    this->icao = icao;
    this->flights.Init(0, 0);
};

int Airline::addFlight(TSharedPtr<Flight> flight)
{
     this->flights.Emplace(flight);
     return 0;

}

TArray<TSharedPtr<Flight>> Airline::getFlights()
{
    return this->flights;
};
