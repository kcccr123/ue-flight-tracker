// Copyright Epic Games, Inc. All Rights Reserved.


#include "FlightBrowseGameModeBase.h"
#include "MyHUD.h"
#include "MenuPlayerController.h"
#include "SSSlateUI.h"
#include "CesiumGeoreference.h"
#include "GlobeAwareDefaultPawn.h"
#include "viewModelCesium.h"
#include "Engine/Engine.h"

void AFlightBrowserGameModeBase::StartPlay()
{
    Super::StartPlay();
    check(GEngine != nullptr);
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Running"));
    UE_LOG(LogTemp, Log, TEXT("GameMode Runs"));
    //AMenuPlayerController* PlayerController = GetWorld()->SpawnActor<AMenuPlayerController>(AMenuPlayerController::StaticClass());
    //AMyHUD* MyHUD = GetWorld()->SpawnActor<AMyHUD>(AMyHUD::StaticClass());
    //plane = GetWorld()->SpawnActor<APlaneActor>(APlaneActor::StaticClass());
    //AMenuPlayerController* temp = Cast<AMenuPlayerController>(PlayerControllerClass);
    //temp->setPlane(plane);
}

void AFlightBrowserGameModeBase::InitGameState()
{
    Super::InitGameState();
    //ViewModelInstance = MakeShared<UViewModelCesium>();
    DefaultPawnClass = AGlobeAwareDefaultPawn::StaticClass();
    PlayerControllerClass = AMenuPlayerController::StaticClass();
    HUDClass = AMyHUD::StaticClass();
    // HUDClass->setViewModel(ViewModelInstance);
    // AMenuPlayerController* temp = Cast<AMenuPlayerController>(PlayerControllerClass);
    // temp->TeleportPlayer(5, 5, 5);

}
