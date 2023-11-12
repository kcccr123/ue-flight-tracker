// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GlobeAwareDefaultPawn.h"
#include "MyGlobeAwareDefaultPawn.generated.h"

/**
 * 
 */
UCLASS()
class FLIGHTBROWSE_API AMyGlobeAwareDefaultPawn : public AGlobeAwareDefaultPawn
{
	GENERATED_BODY()
	AMyGlobeAwareDefaultPawn();
	class UCesiumFlyToComponent* FlyToComponent;
	
};
