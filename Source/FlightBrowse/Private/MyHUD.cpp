// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "SSSlateUI.h"
#include "Engine/Engine.h"
#include "viewModelCesium.h"
#include "Widgets/SWeakWidget.h"
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

}


void AMyHUD::ShowMenu()
{
    if (GEngine && GEngine->GameViewport) {
        //pass referance to ViewModelInstance from here
        MenuWidget = SNew(SSlateUI).HUDPtr(this).instance(ViewModelInstance);
        GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));
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

