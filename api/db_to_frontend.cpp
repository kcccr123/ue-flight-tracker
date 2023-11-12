#include <stdio.h>
#include <cstring>
#include <iostream>
#include "sqlite/sqlite3.h"

using namespace std;

class FlightLocation
{
private:
    double latitude;
    double longitude;
    double altitude;

public:
    FlightLocation()
    {
        latitude, longitude, altitude = 0;
    }

    FlightLocation(double latitude, double longitude, double altitude)
    {
        this->latitude = latitude;
        this->longitude = longitude;
        this->altitude = altitude;
    }

    double getLatitude()
    {
        return latitude;
    }

    double getLongitude()
    {
        return longitude;
    }

    double getAltitude()
    {
        return altitude;
    }
};

class SQLiteConverter
{
private:
    sqlite3 *db;

public:
    SQLiteConverter(sqlite3 *db)
    {
        this->db = db;
    }

    FlightLocation *getFlightLocation(const char *callsign)
    {
        if (db == NULL)
            return NULL;

        // char sql[100] = "SELECT lat, lng, atd from flight_data where callsign=";
        char sql[100] = "SELECT lat, lng, atd from flight_data where `index`=";
        strcat(sql, callsign);

        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
        sqlite3_step(stmt);

        double latitude = sqlite3_column_double(stmt, 0);
        double longitude = sqlite3_column_double(stmt, 1);
        double altitude = sqlite3_column_double(stmt, 2);
        
        sqlite3_finalize(stmt);

        return new FlightLocation(latitude, longitude, altitude);
    }
};

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