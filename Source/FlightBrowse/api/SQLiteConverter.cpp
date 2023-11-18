#include <cstring>
#include "sqlite/sqlite3.h"
#include "Flight.h"
#include "Airline.h"
/*
* SQlite converter methods
*/
SQLiteConverter::SQLiteConverter(sqlite3* db)
{
	this->db = db;
}

Flight* SQLiteConverter::getFlight(const char* callsign)
{
	char sql[100] = "SELECT airline, lat, lng, atd, heading from flight_data where callsign=";
	strcat_s(sql, callsign);

	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	sqlite3_step(stmt);

	const unsigned char* airline = sqlite3_column_text(stmt, 0);
	double latitude = sqlite3_column_double(stmt, 1);
	double longitude = sqlite3_column_double(stmt, 2);
	double altitude = sqlite3_column_double(stmt, 3);
	int heading = sqlite3_column_int(stmt, 4);

	sqlite3_finalize(stmt);

	return new Flight(callsign, airline, latitude, longitude, altitude, heading);
}

Airline* SQLiteConverter::buildAirline(const unsigned char* icao)
{

}

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