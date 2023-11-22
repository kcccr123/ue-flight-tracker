// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGlobeAwareDefaultPawn.h"
#include "CesiumFlyToComponent.h"


AMyGlobeAwareDefaultPawn::AMyGlobeAwareDefaultPawn()
{
	FlyToComponent = CreateDefaultSubobject<UCesiumFlyToComponent>(TEXT("FlyToComponent"));
}
