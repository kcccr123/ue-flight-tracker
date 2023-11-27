// Copyright Epic Games, Inc. All Rights Reserved.

#include "FlightBrowseGameModeBase.h"

void AFlightBrowseGameModeBase::StartPlay()
{
    Super::StartPlay();
    check(GEngine != nullptr);
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Running"));
    UE_LOG(LogTemp, Log, TEXT("Starting"));

    // Run Python
    
    UWorld* World = GetWorld();
    FString FilePath = TEXT("py" + FPaths::ProjectContentDir() + "Database/api_to_sql.py");
    UE_LOG(LogTemp, Log, TEXT("Python"));
    const TCHAR* Path = *FilePath;
    World->Exec(NULL, Path);
    UE_LOG(LogTemp, Log, TEXT("Python2"));


}

void AFlightBrowseGameModeBase::InitGameState()
{
    Super::InitGameState();
    UE_LOG(LogTemp, Log, TEXT("Setting States"));
    DefaultPawnClass = AMyGlobeAwareDefaultPawn::StaticClass();
    PlayerControllerClass = AMenuPlayerController::StaticClass();
    HUDClass = AMyHUD::StaticClass();

}
