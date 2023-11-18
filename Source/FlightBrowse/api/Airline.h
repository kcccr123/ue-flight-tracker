#include "Flight.h"

class Airline
{
private:
    TArray<Flight*> flights;
    const char* icao;

public:
    Airline(const char* icao);

    int addFlight(Flight *flight); 

    TArray<Flight*> getFlights();
};
