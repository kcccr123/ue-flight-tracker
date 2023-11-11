// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CesiumGeoreference.h"
#include "GlobeAwareDefaultPawn.h"
//#include "PlaneActor.h"
#include "MenuPlayerController.generated.h"


/**
 *
 */
UCLASS()
class AMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	AMenuPlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	void OpenMenu();
	AGlobeAwareDefaultPawn* player;
	//APlaneActor* plane;
	ACesiumGeoreference* CesiumGeoreference;


public:
	void TeleportPlayer(float longta, float lata, float alta);
	//void setPlane(APlaneActor*);

};
