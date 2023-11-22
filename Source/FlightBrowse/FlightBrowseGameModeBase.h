// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MyHUD.h"
#include "MenuPlayerController.h"
#include "CesiumGeoreference.h"
#include "MyGlobeAwareDefaultPawn.h"
#include "viewModelCesium.h"
#include "api/SQLiteConverter.h"
#include "api/Airline.h"
#include "Engine/Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FlightBrowseGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class AFlightBrowseGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	virtual void StartPlay() override;
	void InitGameState() override;

};

