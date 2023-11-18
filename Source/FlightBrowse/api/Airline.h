#include "Flight.h"

class Airline
{
private:
    Flight** flights;

public:
    Airline();

    Flight** getFlights();
};
