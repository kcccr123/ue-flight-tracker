// Fill out your copyright notice in the Description page of Project Settings.

#include "viewModelCesium.h"
#include "MenuPlayerController.h"
#include "../api/db_to_frontend.h"
#include "../api/sqlite/sqlite3.h"

// For future referance, delegates are mostly used when you want to pass methods to other classes, potentially methods you don't know the exact signature off.
// Most of the time just use basic interfaces instead to communicate between classes.

UViewModelCesium::UViewModelCesium()
{
	viewCords.BindUObject(this, &UViewModelCesium::HandleIntInput);
    sqlite3_open("test.db", &(db));
    converter = new SQLiteConverter(db);
}

void UViewModelCesium::setWorldInstance(AMenuPlayerController* worldPtr)
{
	worldInstance = worldPtr;
}


void UViewModelCesium::HandleIntInput(float longitude, float latitude, float altitude)
{
	UE_LOG(LogTemp, Log, TEXT("%f"), longitude);
	UE_LOG(LogTemp, Log, TEXT("%f"), latitude);
	UE_LOG(LogTemp, Log, TEXT("%f"), altitude);
	worldInstance->TeleportPlayer(longitude, latitude, altitude);


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