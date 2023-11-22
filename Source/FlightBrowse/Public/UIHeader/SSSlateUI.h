// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Widgets/SCompoundWidget.h"
#include "viewModelCesium.h"

/**
 *
 */
class SSlateUI : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlateUI)
		{}
		SLATE_ARGUMENT(TWeakObjectPtr<class AMyHUD>, HUDPtr)
		SLATE_ARGUMENT(UViewModelCesium*, instance)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

protected:
	// PTRs to textfields
	// These are shared Ptr's because when added to the view port, unreal logic will assign pointers to them as well.
	TSharedPtr<SEditableTextBox> LongCord;
	TSharedPtr<SEditableTextBox> LatCord;
	TSharedPtr<SEditableTextBox> AltCord;
	TSharedPtr<SEditableTextBox> ICAOCords;

	//ptr to view model
	UViewModelCesium* ViewModelInstance;

	//Get Values
	float stringConversion(TSharedPtr<SEditableTextBox> box);

	//Factory Class
	TWeakObjectPtr<class AMyHUD> HUDPtr;

	virtual bool SupportsKeyboardFocus() const override { return true; };
public:
	// Teleport to specified location
	FReply getValues();

	//Switch to view list of airlines (main logic)
	FReply SwitchToListView();

};
