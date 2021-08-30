// Fill out your copyright notice in the Description page of Project Settings.


#include "SMenuWidget.h"
#include "Module5Proj/Module5ProjHUD.h"

#define LOCTEXT_NAMESPACE "Title"

void SMenuWidget::Construct(const FArguments& InArgs)
{

	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;

	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(500.f, 10.f);

	const FText TitleText = LOCTEXT("Title", "Menu");
	const FText PlayText = LOCTEXT("Play", "PlayGame");
	const FText QuitText = LOCTEXT("Quit", "QuitGame");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(850.f, 250.f)
			[
				SNew(SImage)
				.ColorAndOpacity(FLinearColor(0.f, 0.f, 0.f, 0.25f))
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Center)
			.Padding(ContentPadding)
			[
				SNew(SVerticalBox)
				
				//Title Text
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Font(TitleTextStyle)
					.Text(TitleText)
					.Justification(ETextJustify::Center)
				]

				//Play Button
				+SVerticalBox::Slot()
				.Padding(ButtonPadding)
				
				[
					SNew(SButton)
					.OnClicked(this, &SMenuWidget::OnPlayClicked)

					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(PlayText)
						.Justification(ETextJustify::Center)
					]
				]

				//Play Button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
						SNew(SButton)
						.OnClicked(this, &SMenuWidget::OnQuitClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(QuitText)
						.Justification(ETextJustify::Center)
					]
				]
			]
	];
}

FReply SMenuWidget::OnPlayClicked() const
{
	if(OwningHUD.IsValid())
	{
		OwningHUD->RemoveMenu();
	}

	return FReply::Handled();
}

FReply SMenuWidget::OnQuitClicked() const
{
	if(OwningHUD.IsValid())
	{
		if(APlayerController* PC = OwningHUD->PlayerOwner)
		{
			PC->ConsoleCommand("quit");
		}
	}

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE