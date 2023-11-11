// Fill out your copyright notice in the Description page of Project Settings.

#include "viewModelCesium.h"
#include "MenuPlayerController.h"

// For future referance, delegates are mostly used when you want to pass methods to other classes, potentially methods you don't know the exact signature off.
// Most of the time just use basic interfaces instead to communicate between classes.

UViewModelCesium::UViewModelCesium()
{
	viewCords.BindUObject(this, &UViewModelCesium::HandleIntInput);
}

void UViewModelCesium::setWorldInstance(AMenuPlayerController* worldPtr)
{
	worldInstance = worldPtr;
}


void UViewModelCesium::HandleIntInput(float longitude, float latitude, float altitude)
{
	UE_LOG(LogTemp, Log, TEXT("%f"), longitude);
	UE_LOG(LogTemp, Log, TEXT("%f"), latitude);
	UE_LOG(LogTemp, Log, TEXT("%f"), altitude);
	worldInstance->TeleportPlayer(longitude, latitude, altitude);


}

