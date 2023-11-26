// Fill out your copyright notice in the Description page of Project Settings.

#include "MyHUD.h"
#include "UIHeader/SSSlateUI.h"
#include "UIHeader/SFlightListView.h"
#include "Engine/Engine.h"
#include "viewModelCesium.h"
#include "Widgets/SWeakWidget.h"
#include "../api/Flight.h"
#include "../api/Airline.h"
#include "GameFramework/PlayerController.h"


void AMyHUD::BeginPlay() {

    Super::BeginPlay();
    isOpen = false;
    UE_LOG(LogTemp, Log, TEXT("Menu working"));

    // create ViewModel instance here.
    // Inject player controller into ViewModel
    // Inject ViewModel into SlateUI.
    // View -> ViewModel -> PlayerController
    ViewModelInstance = NewObject<UViewModelCesium>();
    ViewModelInstance->setWorldInstance(Cast<AMenuPlayerController>(GetWorld()->GetFirstPlayerController()));

    SearchMenu = SNew(SSlateUI).HUDPtr(this).instance(ViewModelInstance);
    ListMenu = SNew(SFlightListView).HUDPtr(this).instance(ViewModelInstance);
}


void AMyHUD::QuitProject()
{
    FGenericPlatformMisc::RequestExit(false);
}

void AMyHUD::ShowMenu()
{
    if (GEngine && GEngine->GameViewport) {
        //pass referance to ViewModelInstance from here
        GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuContainer, SWeakWidget).PossiblyNullContent(SearchMenu.ToSharedRef()));
        isOpen = true;
        if (PlayerOwner) {
            PlayerOwner->bShowMouseCursor = true;
            //PlayerOwner->SetInputMode(FInputModeUIOnly());
        }
    }
}

void AMyHUD::CloseMenu()
{
    if (GEngine && GEngine->GameViewport && MenuContainer.IsValid()) {
        GEngine->GameViewport->RemoveViewportWidgetContent(MenuContainer.ToSharedRef());
        isOpen = false;
        if (PlayerOwner) {
            PlayerOwner->bShowMouseCursor = false;
            //PlayerOwner->SetInputMode(FInputModeGameOnly());
        }
    }

}

void AMyHUD::OpenList(const char * AirlineCode)
{

    // GET TARRAY FROM VIEWMODEL
    Airline * resultAirline = ViewModelInstance->GetFlights(AirlineCode);
    
    // SET TARRAY 
    ListMenu->FlightsListing = resultAirline->getFlights();
    UE_LOG(LogTemp, Log, TEXT("Array Length: %d"), ListMenu->FlightsListing.Num());

    GEngine->GameViewport->RemoveViewportWidgetContent(MenuContainer.ToSharedRef());
    GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuContainer, SWeakWidget).PossiblyNullContent(ListMenu.ToSharedRef()));
}

