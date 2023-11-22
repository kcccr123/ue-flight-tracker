// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class FLIGHTBROWSE_API SAirlineButton : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAirlineButton)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	TSharedRef<ITableRow> GenerateRow(TSharedPtr<int32> Item, const TSharedRef<STableViewBase>& OwnerTable);
};
