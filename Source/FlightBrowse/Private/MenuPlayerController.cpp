// Fill out your copyright notice in the Description page of Project Settings.

#include "CesiumGeoreference.h"
#include "MenuPlayerController.h"
#include "MyGlobeAwareDefaultPawn.h"
#include "PlaneActor.h"
#include "MyHUD.h"

AMenuPlayerController::AMenuPlayerController()
{
	UE_LOG(LogTemp, Log, TEXT("Player controller constructor"));
	//CesiumGeoreference = CreateDefaultSubobject<ACesiumGeoreference>(TEXT("CesiumGeoreference"));
	//CesiumGeoreference = CesiumGeoreference->GetDefaultGeoreference(GetWorld());
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


void AMenuPlayerController::TeleportPlayer(float longta, float lata, float alta)
{
	UE_LOG(LogTemp, Log, TEXT("%f player"), longta);
	UE_LOG(LogTemp, Log, TEXT("%f player"), lata);
	UE_LOG(LogTemp, Log, TEXT("%f player"), alta);


	// Set player position
	player->FlyToLocationLongitudeLatitudeHeight(FVector(longta, lata, 2250 + alta), 0, 0, false);

	// Set plane position
	FVector temp2 = CesiumGeoreference->TransformLongitudeLatitudeHeightPositionToUnreal(FVector(longta, lata, 2250 + alta));
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
