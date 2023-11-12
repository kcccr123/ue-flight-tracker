#pragma once

#include "sqlite/sqlite3.h"


class FlightLocation
{
private:
    double latitude;
    double longitude;
    double altitude;

public:
    FlightLocation();

    FlightLocation(double latitude, double longitude, double altitude);
    double getLatitude();
    double getLongitude();
    double getAltitude();
};




class SQLiteConverter
{
private:
    sqlite3 *db;

public:
    SQLiteConverter(sqlite3* db);

    FlightLocation* getFlightLocation(const char* callsign);
};



/* Usage example
int main(int argc, char *argv[])
{
    sqlite3 *db;

    if (sqlite3_open("test.db", &db) != SQLITE_OK)
        return 1;

    SQLiteConverter *converter = new SQLiteConverter(db);
    FlightLocation *location = converter->getFlightLocation("1499");

    printf("%lf, %lf, %lf\n", location->getLatitude(), location->getLongitude(), location->getAltitude());
    sqlite3_close(db);

    return 0;
}
*/
