#pragma once

class Flight
{
private:
    FString callsign;
    FString airline;
    double latitude;
    double longitude;
    double altitude;
    int32 heading;

public:
    Flight();
    Flight(FString callsign, FString airline, double latitude, double longitude, double altitude, int32 heading);
    
    FString getCallsign();
    FString getAirline();
    double getLatitude();
    double getLongitude();
    double getAltitude();
    int32 getHeading();
};