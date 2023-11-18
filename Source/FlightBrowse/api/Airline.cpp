#include "Airline.h"
#include "Flight.h"

Airline::Airline() 
{
    this->flights = nullptr;
};

Flight** Airline::getFlights()
{
    return this->flights;
};