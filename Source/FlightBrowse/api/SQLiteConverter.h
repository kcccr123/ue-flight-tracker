#pragma once

#include "sqlite/sqlite3.h"
#include "Flight.h"
#include "Airline.h"

class SQLiteConverter
{
private:
    sqlite3 *db;

public:
    SQLiteConverter(sqlite3* db);

    Flight* getFlight(const char* callsign);

    Airline* buildAirline(const unsigned char* icao);
};