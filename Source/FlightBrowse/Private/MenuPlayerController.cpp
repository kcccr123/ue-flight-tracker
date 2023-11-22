// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "CesiumGeoreference.h"
#include "CesiumGeoreference.h"
#include "MyGlobeAwareDefaultPawn.h"
#include "MyHUD.h"
#include "PlaneActor.h"

AMenuPlayerController::AMenuPlayerController()
{
	UE_LOG(LogTemp, Log, TEXT("Player controller constructor"));
}

void AMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("Player controller begin play"));
	CesiumGeoreference = ACesiumGeoreference::GetDefaultGeoreference(GetWorld());
	player = Cast<AMyGlobeAwareDefaultPawn>(GetPawn());
	plane = GetWorld()->SpawnActor<APlaneActor>(APlaneActor::StaticClass());

}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (InputComponent) {
		UE_LOG(LogTemp, Log, TEXT("Set up input"));
		InputComponent->BindAction("Menu", IE_Pressed, this, &AMenuPlayerController::OpenMenu);
	}
}


void AMenuPlayerController::TeleportPlayer(double longta, double lata, double alta, int32 heading)
{
	UE_LOG(LogTemp, Log, TEXT("%f player"), longta);
	UE_LOG(LogTemp, Log, TEXT("%f player"), lata);
	UE_LOG(LogTemp, Log, TEXT("%f player"), alta);

	// Convert heading to rotation
	FRotator AircraftRotation = FRotator(0.0f, heading, 0.0f);

	// Set the rotation of the aircraft mesh
	plane->SetActorRotation(AircraftRotation);

	// Set player position
	player->FlyToLocationLongitudeLatitudeHeight(FVector(longta, lata, 2050 + alta), 0, 0, false);

	// Set plane position
	FVector temp2 = CesiumGeoreference->TransformLongitudeLatitudeHeightPositionToUnreal(FVector(longta, lata, 2000 + alta));
	plane->SetActorLocation(temp2);

}


void AMenuPlayerController::OpenMenu()
{
	UE_LOG(LogTemp, Log, TEXT("Calling"));
	if (AMyHUD* MenuHUD = Cast<AMyHUD>(GetHUD())) {
		if (MenuHUD->isOpen == true) {
			MenuHUD->CloseMenu();
		}
		else {
			MenuHUD->ShowMenu();
		}
	}

}
