// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "MenuPlayerController.h"
#include "../api/SQLiteConverter.h"
#include "../api/Airline.h"
#include "../api/SQLiteConverter.h"
#include "SQLiteDatabase.h"
#include "viewModelCesium.generated.h"


DECLARE_DELEGATE_FourParams(FCordsDelegate, double, double, double, int32);
/**
 *
 */
UCLASS()
class UViewModelCesium : public UObject
{
	GENERATED_BODY()
	//call constructor
	UViewModelCesium();

	//Using raw pointer because UnrealEngine has ownership over set playerController.
	AMenuPlayerController* worldInstance;
private:
	// sqlite3 * db;
	SQLiteConverter * converter;
public:
	FCordsDelegate viewCords;
	//FPlayerCords playerCords;
	void HandleIntInput(double longitude, double latitude, double altitude, int32 heading);
	void setWorldInstance(AMenuPlayerController* worldPtr);
	Airline * GetFlights(FString Airline);

};
