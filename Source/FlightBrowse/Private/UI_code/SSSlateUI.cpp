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

	HUDPtr = InArgs._HUDPtr;

	//Margins
	const FMargin ContentPadding = FMargin(300.f, 200.f);
	const FMargin ButtonPadding = FMargin(10.f);

	//Text constants
	const FText Longtitude = LOCTEXT("Long", "Longtitude");
	const FText Latititude = LOCTEXT("Lat", "Laititude");
	const FText Altitude = LOCTEXT("Alt", "Altitude");
	const FText Start = LOCTEXT("Start", "Start");
	const FText ListViewText = LOCTEXT("Enter", "Enter");
	const FText EnterAirline = LOCTEXT("IACO", "IACO");

	//Referanace to Controller
	ViewModelInstance = InArgs._instance;

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;
	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	;
	TitleTextStyle.Size = 60.f;


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
							SNew(STextBlock).Font(TitleTextStyle)
								.Text(NSLOCTEXT("Ex", "key1", "Fuck you kid")).Justification(ETextJustify::Center)
						]
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						[
							SAssignNew(LongCord, SEditableTextBox)
								.Font(ButtonTextStyle)
								.Text(Longtitude).Justification(ETextJustify::Center)

						]
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						[

							SAssignNew(LatCord, SEditableTextBox).Font(ButtonTextStyle)
								.Text(Latititude).Justification(ETextJustify::Center)

						]
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						[
							SAssignNew(AltCord, SEditableTextBox).Font(ButtonTextStyle)
								.Text(Altitude).Justification(ETextJustify::Center)

						]
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						[
							SNew(SButton).OnClicked(this, &SSlateUI::getValues)
								[
									SNew(STextBlock).Font(ButtonTextStyle)
										.Text(Start).Justification(ETextJustify::Center)
								]
						]
						+ SVerticalBox::Slot()
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



		];

}

float SSlateUI::stringConversion(TSharedPtr<SEditableTextBox> box)
{
	// Get Box text
	FText temp = box->GetText();
	// Convert to FString
	FString MyFString = temp.ToString();
	// Get cord in integer
	float result = FCString::Atof(*MyFString);
	return result;
}

//FMemory::Memcpy((void*)MyTCHARPtr, (void*)*MyFString, len * sizeof(TCHAR));
FReply SSlateUI::getValues()
{
	float longta = stringConversion(LongCord);
	float lata = stringConversion(LatCord);
	float alta = stringConversion(AltCord);	
	ViewModelInstance->viewCords.ExecuteIfBound(longta, lata, alta);
	return FReply::Handled();
}

FReply SSlateUI::SwitchToListView()
{
	FText temp = ICAOCords->GetText();
	FString MyFString = temp.ToString();
	/*
	const char* code = (const char*)malloc(sizeof(char) * (MyFString.Len() + 1));
	strcpy((char*) code, TCHAR_TO_UTF8(*MyFString));
	UE_LOG(LogTemp, Log, TEXT("%s"), code);
	UE_LOG(LogTemp, Log, TEXT("%s"), TCHAR_TO_ANSI(*MyFString));
	UE_LOG(LogTemp, Log, TEXT("Converted String: %s"), ANSI_TO_TCHAR(code));
	*/
	//HUDPtr->OpenList(code);	
	HUDPtr->OpenList(TCHAR_TO_UTF8(*MyFString));
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION


