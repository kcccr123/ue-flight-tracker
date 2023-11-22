// Fill out your copyright notice in the Description page of Project Settings.


#include "UIHeader/SAirlineButton.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SAirlineButton::Construct(const FArguments& InArgs)
{
	/*
	ChildSlot
	[
		// Populate the widget
	];*/
	
}
TSharedRef<ITableRow> SAirlineButton::GenerateRow(TSharedPtr<int32> Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	return SNew(STableRow<TSharedPtr<int32>>, OwnerTable)
		.Padding(5)
		[
			SNew(STextBlock)
				.Text(FText::FromString(FString::Printf(TEXT("Item %d")))).Justification(ETextJustify::Center)
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
