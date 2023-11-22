#pragma once

#include "Flight.h"
#include "Airline.h"

class SQLiteConverter
{
private:
    FString dbName;

public:
    SQLiteConverter(FString db);

    Flight* getFlight(FString callsign);

    Airline* buildAirline(FString icao);
};