// Fill out your copyright notice in the Description page of Project Settings.


#include "SSSlateUI.h"
#include "SlateOptMacros.h"
#include "Widgets/Input/SEditableTextBox.h"
//#include "CesiumController.h"

#define LOCTEXT_NAMESPACE "Mainmenu"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSlateUI::Construct(const FArguments& InArgs)
{

	bCanSupportFocus = true;

	HUDPtr = InArgs._HUDPtr;

	//Margins
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);

	//Text constants
	const FText Longtitude = LOCTEXT("Long", "Longtitude");
	const FText Latititude = LOCTEXT("Lat", "Laititude");
	const FText Altitude = LOCTEXT("Alt", "Altitude");
	const FText Start = LOCTEXT("Start", "Start");

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
	// Malloc
	//const TCHAR* MyTCHARPtr = (TCHAR*)(malloc( sizeof(TCHAR) * (len + 1) ));
	// Cpy to ptr.
	//FCString::Strcpy((TCHAR*)MyTCHARPtr, len + 1, *MyFString);
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

	/*
	UE_LOG(LogTemp, Log, TEXT("ButtonClick"));
	int longta = stringConversion(LongCord);
	int lata = stringConversion(LatCord);
	int alta = stringConversion(AltCord);
	UE_LOG(LogTemp, Log, TEXT("%d"), longta);
	UE_LOG(LogTemp, Log, TEXT("%d"), lata);
	UE_LOG(LogTemp, Log, TEXT("%d"), alta);
	//Allocates memory to hold cords
	int* arr = (int*) malloc(sizeof(int) * 3);
	arr[0] = longta;
	arr[1] = lata;
	arr[2] = alta;
	//CordArr now holds cords
	*cordArr = arr;
	return FReply::Handled();

	*/
}




/*
FReply SSlateUI::OnPlayClicked() const
{
	return FReply();

FReply SSlateUI::OnQuitClicked() const
{
	return FReply();
}*/

END_SLATE_FUNCTION_BUILD_OPTIMIZATION


