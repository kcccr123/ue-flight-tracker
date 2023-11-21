// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "viewModelCesium.h"
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class FLIGHTBROWSE_API SFlightListView : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SFlightListView)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMyHUD>, HUDPtr)
	SLATE_ARGUMENT(UViewModelCesium*, instance)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	TArray<TSharedPtr<Flight>> FlightsListing;
protected:
	//ptr to view model
	UViewModelCesium* ViewModelInstance;

	//Factory Class
	TWeakObjectPtr<class AMyHUD> HUDPtr;

	

	TSharedRef<ITableRow> GenerateRow(TSharedPtr<Flight> Item, const TSharedRef<STableViewBase>& OwnerTable);
	FReply getValues(double lata, double longta, double alta);

	virtual bool SupportsKeyboardFocus() const override { return true; };
};
