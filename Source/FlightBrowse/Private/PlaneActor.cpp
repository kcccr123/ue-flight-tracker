// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaneActor.h"

// Sets default values
APlaneActor::APlaneActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	// Set plane mesh
	PlaneMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneMeshComponent"));
	RootComponent = PlaneMeshComponent;
	PlaneMeshComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/B_787_8.B_787_8'"));
	if (MeshAsset.Succeeded())
	{
		UE_LOG(LogTemp, Log, TEXT("Spawned Plane"));
		PlaneMeshComponent->SetStaticMesh(MeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void APlaneActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlaneActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

