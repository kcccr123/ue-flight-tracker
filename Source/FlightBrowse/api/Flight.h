class Flight
{
private:
    const char* callsign;
    const unsigned char* airline;
    double latitude;
    double longitude;
    double altitude;
    int heading;

public:
    Flight();
    Flight(const char* callsign, const unsigned char* airline, double latitude, double longitude, double altitude, int heading);
    
    const char* getCallsign();
    const unsigned char* getAirline();
    double getLatitude();
    double getLongitude();
    double getAltitude();
    int getHeading();
};