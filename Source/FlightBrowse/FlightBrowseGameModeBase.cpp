// Copyright Epic Games, Inc. All Rights Reserved.

#include "FlightBrowseGameModeBase.h"

void AFlightBrowseGameModeBase::StartPlay()
{
    Super::StartPlay();
    check(GEngine != nullptr);
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Running"));
    UE_LOG(LogTemp, Log, TEXT("Starting"));

}

void AFlightBrowseGameModeBase::InitGameState()
{
    Super::InitGameState();
    UE_LOG(LogTemp, Log, TEXT("Setting States"));
    DefaultPawnClass = AMyGlobeAwareDefaultPawn::StaticClass();
    PlayerControllerClass = AMenuPlayerController::StaticClass();
    HUDClass = AMyHUD::StaticClass();

}
