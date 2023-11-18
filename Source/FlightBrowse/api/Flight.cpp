#include "Flight.h"

Flight::Flight()
{
    this->callsign = "";
    this->latitude, this->longitude, this->altitude, this->heading = 0;
}

Flight::Flight(const char *callsign, const unsigned char *airline, double latitude, double longitude, double altitude, int heading)
{
    this->callsign = callsign;
    this->airline = airline;
    this->latitude = latitude;
    this->longitude = longitude;
    this->altitude = altitude;
    this->heading = heading;
};

const char *Flight::getCallsign()
{
    return this->callsign;
};

const unsigned char *Flight::getAirline()
{
    return this->airline;
};

double Flight::getLatitude()
{
    return this->latitude;
};

double Flight::getLongitude()
{
    return this->longitude;
};

double Flight::getAltitude()
{
    return this->altitude;
};

int Flight::getHeading()
{
    return this->heading;
};