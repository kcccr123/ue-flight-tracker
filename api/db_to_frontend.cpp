#include <stdio.h>
#include <iostream>
#include "sqlite/sqlite3.h"

using namespace std;

class FlightLocation
{
private:
    double longitude;
    double latitude;
    double altitude;

public:
    FlightLocation()
    {
        longitude, latitude, altitude = 0;
    }

    double getLongitude()
    {
        return longitude;
    }

    double getLatitude()
    {
        return latitude;
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

    FlightLocation *getFlightLocation()
    {
        // should take flight id as param
        // select long/lat/height from db
        return new FlightLocation();
    }
};

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql;
   const char* data = "Callback function called";

   /* Open database */
   rc = sqlite3_open("test.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "SELECT * from flight_data";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
   
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }
   sqlite3_close(db);
   return 0;
}

/*
int main(int argc, char *argv[])
{
    sqlite3*        db;
    sqlite3_stmt*   stmt;
    const char*     query = "SELECT * FROM flight_data WHERE index=1499\0";
    int             rc;

    rc = sqlite3_open("test.db", &db);
    if (rc != SQLITE_OK) return 1;

    printf("%d\n", sqlite3_prepare_v2(db, query, sizeof(query), &stmt, NULL));

    rc = sqlite3_finalize(stmt);
    if (rc != SQLITE_OK) return 4; // Error in finalize

    // SQLiteConverter* converter = new SQLiteConverter(db);
    // FlightLocation* location = converter->getFlightLocation();

    rc = sqlite3_close(db);
    if (rc != SQLITE_OK)
        return 5; // Error in close

    return 0;
}
*/