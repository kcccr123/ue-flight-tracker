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

/*
* Flight location class methods
*/
Flight::Flight()
{
	this->callsign = "";
	this->latitude, this->longitude, this->altitude, this->heading = 0;
}

Flight::Flight(const char* callsign, const unsigned char* airline, double latitude, double longitude, double altitude, int heading)
{
	this->callsign = callsign;
	this->airline = airline;
	this->latitude = latitude;
	this->longitude = longitude;
	this->altitude = altitude;
	this->heading = heading;
}

const char* Flight::getCallsign()
{
	return this->callsign;
}

const unsigned char* Flight::getAirline()
{
	return this->airline;
}

double Flight::getLatitude()
{
	return this->latitude;
}

double Flight::getLongitude()
{
	return this->longitude;
}

double Flight::getAltitude()
{
	return this->altitude;
}

int Flight::getHeading()
{
	return this->heading;
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