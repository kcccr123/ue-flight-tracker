// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CesiumGlobeAnchorComponent.h"
#include "GameFramework/Actor.h"
#include "CesiumGeospatial/Ellipsoid.h"
#include "CesiumGeospatial/Cartographic.h"
#include "PlaneActor.generated.h"

UCLASS()
class APlaneActor : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	APlaneActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UStaticMeshComponent* PlaneMeshComponent;
	UCesiumGlobeAnchorComponent* CesiumGlobeAnchor;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
