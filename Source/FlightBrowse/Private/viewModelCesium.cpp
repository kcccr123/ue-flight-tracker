// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuPlayerController.h"
#include "../api/SQLiteConverter.h"
// #include "../api/sqlite/sqlite3.h"
#include "../api/Airline.h"
#include "viewModelCesium.h"


// For future referance, delegates are mostly used when you want to pass methods to other classes, potentially methods you don't know the exact signature off.
// Most of the time just use basic interfaces instead to communicate between classes.

UViewModelCesium::UViewModelCesium()
{
	viewCords.BindUObject(this, &UViewModelCesium::HandleIntInput);
    converter = new SQLiteConverter("test.db");
}

void UViewModelCesium::setWorldInstance(AMenuPlayerController* worldPtr)
{
	worldInstance = worldPtr;
}

Airline * UViewModelCesium::GetFlights(FString airline)
{
   return converter->buildAirline(airline);
}


void UViewModelCesium::HandleIntInput(double longitude, double latitude, double altitude, int32 heading)
{
	UE_LOG(LogTemp, Log, TEXT("%f"), longitude);
	UE_LOG(LogTemp, Log, TEXT("%f"), latitude);
	UE_LOG(LogTemp, Log, TEXT("%f"), altitude);
	worldInstance->TeleportPlayer(longitude, latitude, altitude, heading);


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