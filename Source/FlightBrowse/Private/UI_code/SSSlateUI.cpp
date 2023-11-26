// Fill out your copyright notice in the Description page of Project Settings.


#include "UIHeader/SSSlateUI.h"
#include "SlateOptMacros.h"
#include "MyHUD.h"
#include "Widgets/Input/SEditableTextBox.h"
//#include "CesiumController.h"

#define LOCTEXT_NAMESPACE "Mainmenu"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlateUI::Construct(const FArguments& InArgs)
{

	bCanSupportFocus = true;

	//Referance to HUD
	HUDPtr = InArgs._HUDPtr;

	//Referanace to Controller
	ViewModelInstance = InArgs._instance;

	// View Margin
	const FMargin ContentPadding = FMargin(300.f, 150.f, 300.f, 10.f);

	// Upper Box Margins
	const FMargin TeleportPadding = FMargin(200.f, 10.f);
	const FMargin ButtonPaddingInner = FMargin(5.f, 8.f);
	const FMargin ButtonPadding2 = FMargin(5.f, 10.f);

	// Lower Box Margins
	const FMargin ListPadding = FMargin(200.f, 5.f);
	const FMargin ButtonPadding = FMargin(300.f, 5.f);

	// Exit Box
	const FMargin ExitButton = FMargin(500.0f, 50.0f, 500.0f, 400.0f);
	const FText ExitText = LOCTEXT("Quit To Desktop", "Quit To Desktop");

	// Text constants Upper Box
	const FText Longtitude = LOCTEXT("Long", "Longtitude");
	const FText Latititude = LOCTEXT("Lat", "Laititude");
	const FText Altitude = LOCTEXT("Alt", "Altitude");
	const FText Start = LOCTEXT("Teleport To Coordinates", "Teleport To Coordinates");

	// Text constants Lower Box
	const FText ListViewText = LOCTEXT("Search Airline", "Search Airline");
	const FText EnterAirline = LOCTEXT("ICAO Code", "ICAO Code");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 20.f;


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
						.Padding(TeleportPadding)
						[
							SNew(SVerticalBox)
								+ SVerticalBox::Slot()
								[
									SNew(SHorizontalBox)
										+ SHorizontalBox::Slot()
										.Padding(ButtonPaddingInner)
										[
											SAssignNew(LongCord, SEditableTextBox)
												.Font(ButtonTextStyle)
												.Text(Longtitude).Justification(ETextJustify::Center)

										]
										+ SHorizontalBox::Slot()
										.Padding(ButtonPaddingInner)
										[

											SAssignNew(LatCord, SEditableTextBox).Font(ButtonTextStyle)
												.Text(Latititude).Justification(ETextJustify::Center)

										]
										+ SHorizontalBox::Slot()
										.Padding(ButtonPaddingInner)
										[
											SAssignNew(AltCord, SEditableTextBox).Font(ButtonTextStyle)
												.Text(Altitude).Justification(ETextJustify::Center)

										]
								]

								+ SVerticalBox::Slot()
								.Padding(ButtonPadding2)
								[
									SNew(SButton).OnClicked(this, &SSlateUI::getValues)
										[
											SNew(STextBlock).Font(ButtonTextStyle)
												.Text(Start).Justification(ETextJustify::Center)
										]
								]

						]
						+ SVerticalBox::Slot()
						.Padding(ListPadding)
						[	
							SNew(SVerticalBox)
							+SVerticalBox::Slot()
								.Padding(ButtonPadding)
								[
									SAssignNew(ICAOCords, SEditableTextBox).Font(ButtonTextStyle)
									.Text(EnterAirline).Justification(ETextJustify::Center)

								]
								+ SVerticalBox::Slot()	
								.Padding(ButtonPadding)
								[
									SNew(SButton).OnClicked(this, &SSlateUI::SwitchToListView)
										[
											SNew(STextBlock).Font(ButtonTextStyle)
											.Text(ListViewText).Justification(ETextJustify::Center)
										]
								]
						
						]
						+ SVerticalBox::Slot()
						.Padding(ExitButton)
						[
							SNew(SButton).OnClicked(this, &SSlateUI::ExitProject)
								.HAlign(HAlign_Center)
								.VAlign(VAlign_Center)
								[
									SNew(STextBlock).Font(ButtonTextStyle)
										.Text(ExitText).Justification(ETextJustify::Center)
								]
						]
				]



		];

}


float SSlateUI::stringConversion(TSharedPtr<SEditableTextBox> box)
{
	// Get Box text
	FText temp = box->GetText();
	// Convert to FString
	FString MyFString = temp.ToString();
	// Get cord in integer
	double result = FCString::Atof(*MyFString);
	return result;
}

FReply SSlateUI::ExitProject()
{
	HUDPtr->QuitProject();
	return FReply::Handled();
}


FReply SSlateUI::getValues()
{
	double longta = stringConversion(LongCord);
	double lata = stringConversion(LatCord);
	double alta = stringConversion(AltCord);
	ViewModelInstance->viewCords.ExecuteIfBound(longta, lata, alta, 0);
	return FReply::Handled();
}


FReply SSlateUI::SwitchToListView()
{
	FText temp = ICAOCords->GetText();
	FString MyFString = temp.ToString();
	HUDPtr->OpenList(TCHAR_TO_UTF8(*MyFString));
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

