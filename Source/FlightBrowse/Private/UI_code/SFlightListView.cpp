// Fill out your copyright notice in the Description page of Project Settings.

#include "Widgets/Views/SListView.h"
#include "UIHeader/SFlightListView.h"
#include "UIHeader/SAirlineButton.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SFlightListView::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	//Margins
	const FMargin ContentPadding = FMargin(200.f, 30.f);
	const FMargin ButtonPadding = FMargin(10.f);

	//Referance to HUD
	HUDPtr = InArgs._HUDPtr;

	//Referanace to Controller
	ViewModelInstance = InArgs._instance;

	/*
	for (int32 i = 0; i < 10; ++i)
	{
		FlightsListing.Add(MakeShared<int32>(i));
	}*/

	ChildSlot
	[
		SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
					.ColorAndOpacity(FColor::Black)
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)
			[
				SNew(SVerticalBox)		
				+ SVerticalBox::Slot()
				[

					SNew(SListView< TSharedPtr<Flight>>)
					.ListItemsSource(&FlightsListing)
					.OnGenerateRow(this, &SFlightListView::GenerateRow)
				]
			]
	];
	
}


FReply SFlightListView::getValues(double lata, double longta, double alta)
{
	ViewModelInstance->viewCords.ExecuteIfBound(longta, lata, alta);
	return FReply::Handled();
}

TSharedRef<ITableRow> SFlightListView::GenerateRow(TSharedPtr<Flight> Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;
	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	;
	TitleTextStyle.Size = 60.f;
	return SNew(STableRow<TSharedPtr<Flight>>, OwnerTable)
		[
				SNew(SButton)
				.OnClicked_Lambda([this, Item] { return getValues(Item->getLatitude(), Item->getLongitude(), Item->getAltitude()); })
				.ContentPadding(40)
				.Content()
				[
					SNew(STextBlock)
						.Text(FText::FromString(FString::Printf(TEXT("%s Latitude: %f Longitude: %f Altitude: %f"), 
							*Item->getCallsign(), Item->getLatitude(), Item->getLongitude(), Item->getAltitude())))
						.Justification(ETextJustify::Center)
						.Font(ButtonTextStyle)
				]
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

//.OnClicked(this, &SFlightListView::getValues(Item->getLatitude(), Item->getLongitude(), Item->getAltitude()))