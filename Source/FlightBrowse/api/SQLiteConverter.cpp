#pragma once

#include "SQLiteConverter.h"
#include <cstring>
#include "Flight.h"
#include "Airline.h"
#include "SQLiteDatabase.h"
/*
 * SQlite converter methods
 */
SQLiteConverter::SQLiteConverter(FString db)
{
	this->dbName = db;
}

Flight *SQLiteConverter::getFlight(FString callsign)
{
	/*
	char sql[100] = "SELECT airline, lat, lng, atd, heading from flight_data where callsign=";
	strcat_s(sql, callsign);

	sqlite3_stmt *stmt;
	sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	sqlite3_step(stmt);

	const char *airline = (char*) sqlite3_column_text(stmt, 0);
	double latitude = sqlite3_column_double(stmt, 1);
	double longitude = sqlite3_column_double(stmt, 2);
	double altitude = sqlite3_column_double(stmt, 3);
	int heading = sqlite3_column_int(stmt, 4);

	sqlite3_finalize(stmt);

	return new Flight(callsign, airline, latitude, longitude, altitude, heading);
	*/
	return NULL;
}


Airline* SQLiteConverter::buildAirline(FString icao)
{
	const FString FilePath = FPaths::ProjectContentDir() + "Database/test.db";
	Airline* company = new Airline(icao);
	if (FSQLiteDatabase* MyDb = new FSQLiteDatabase(); 
		MyDb->Open(*FilePath, ESQLiteDatabaseOpenMode::ReadOnly)) {

		FString Query = TEXT("SELECT callsign, lat, lng, atd, heading from flight_data where airline='") + icao + TEXT("';");

		if (FSQLitePreparedStatement* stmt = new FSQLitePreparedStatement();
			stmt->Create(*MyDb, *Query, ESQLitePreparedStatementFlags::Persistent)) {
			//stmt->SetBindingValueByName(TEXT("@ID"), icao);

			while (stmt->Step() == ESQLitePreparedStatementStepResult::Row) {
				FString callsign;
				double latitude;
				double longitude;
				double altitude;
				int32 heading;
				stmt->GetColumnValueByIndex(0, callsign);
				stmt->GetColumnValueByIndex(1, latitude);
				stmt->GetColumnValueByIndex(2, longitude);
				stmt->GetColumnValueByIndex(3, altitude);
				stmt->GetColumnValueByIndex(4, heading);
				UE_LOG(LogTemp, Log, TEXT("%s"), *callsign);
				UE_LOG(LogTemp, Log, TEXT("%f"), latitude);
				UE_LOG(LogTemp, Log, TEXT("%f"), longitude);
				UE_LOG(LogTemp, Log, TEXT("%f"), altitude);
				UE_LOG(LogTemp, Log, TEXT("%d"), heading);
				company->addFlight(MakeShared<Flight>(callsign, icao, latitude, longitude, altitude, heading));

			}
			stmt->Destroy();
			delete stmt;
		}

		MyDb->Close();
		delete MyDb;
	}


	return company;

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