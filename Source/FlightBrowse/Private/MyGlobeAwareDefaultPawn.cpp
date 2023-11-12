// Fill out your copyright notice in the Description page of Project Settings.

#include "CesiumFlyToComponent.h"
#include "MyGlobeAwareDefaultPawn.h"

AMyGlobeAwareDefaultPawn::AMyGlobeAwareDefaultPawn()
{
	FlyToComponent = CreateDefaultSubobject<UCesiumFlyToComponent>(TEXT("FlyToComponent"));
}
