#pragma once

#include "sqlite/sqlite3.h"

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

class SQLiteConverter
{
private:
    sqlite3 *db;

public:
    SQLiteConverter(sqlite3* db);

    Flight* getFlight(const char* callsign);
};

/* Usage example
int main(int argc, char *argv[])
{
    sqlite3 *db;

    if (sqlite3_open("test.db", &db) != SQLITE_OK)
        return 1;

    SQLiteConverter *converter = new SQLiteConverter(db);
    Flight *location = converter->getFlight("1499");

    printf("%lf, %lf, %lf\n", location->getLatitude(), location->getLongitude(), location->getAltitude());
    sqlite3_close(db);

    return 0;
}
*/