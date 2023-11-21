#include "Flight.h"

Flight::Flight()
{
    this->callsign = "";
    this->latitude, this->longitude, this->altitude, this->heading = 0;
}

Flight::Flight(FString callsign, FString airline, double latitude, double longitude, double altitude, int32 heading)
{
    this->callsign = callsign;
    this->airline = airline;
    this->latitude = latitude;
    this->longitude = longitude;
    this->altitude = altitude;
    this->heading = heading;
};

FString Flight::getCallsign()
{
    return this->callsign;
};

FString Flight::getAirline()
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

int32 Flight::getHeading()
{
    return this->heading;
};