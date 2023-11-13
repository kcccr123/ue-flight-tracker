#include <cstring>
#include "sqlite/sqlite3.h"
#include "db_to_frontend.h"


/*
* SQlite converter methods
*/
SQLiteConverter::SQLiteConverter(sqlite3* db)
{
	this->db = db;
}

FlightLocation* SQLiteConverter::getFlightLocation(const char* callsign)
{
	if (this->db == NULL)
		return NULL;

	// char sql[100] = "SELECT lat, lng, atd from flight_data where callsign=";
	char sql[100] = "SELECT lat, lng, atd from flight_data where `index`=";
	strcat_s(sql, callsign);

	sqlite3_stmt* stmt;
	sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	sqlite3_step(stmt);

	double latitude = sqlite3_column_double(stmt, 0);
	double longitude = sqlite3_column_double(stmt, 1);
	double altitude = sqlite3_column_double(stmt, 2);

	sqlite3_finalize(stmt);

	return new FlightLocation(latitude, longitude, altitude);
}




/*
* Flight location class methods
*/
FlightLocation::FlightLocation()
{
	this->latitude, this->longitude, this->altitude = 0;
}

FlightLocation::FlightLocation(double latitude, double longitude, double altitude)
{
	this->latitude = latitude;
	this->longitude = longitude;
	this->altitude = altitude;
}

double FlightLocation::getLatitude()
{
	return this->latitude;
}

double FlightLocation::getLongitude()
{
	return this->longitude;
}

double FlightLocation::getAltitude()
{
	return this->altitude;
}


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