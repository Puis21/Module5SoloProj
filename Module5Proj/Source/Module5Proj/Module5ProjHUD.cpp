// Copyright Epic Games, Inc. All Rights Reserved.

#include "Module5ProjHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "Module5Proj/UI/SMenuWidget.h"
#include "Widgets/SWeakWidget.h"
#include "GameFramework/PlayerController.h"

AModule5ProjHUD::AModule5ProjHUD()
{
	// Set the crosshair texture
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("/Game/FirstPerson/Textures/FirstPersonCrosshair"));
	CrosshairTex = CrosshairTexObj.Object;

}

void AModule5ProjHUD::BeginPlay()
{
	Super::BeginPlay();

	if(AbilityWidgetClass)
	{
		AbilityWidget = CreateWidget<UAbilityWidget>(GetWorld(), AbilityWidgetClass);
		if(AbilityWidget)
		{
			AbilityWidget->AddToViewport();
		}
	}
}

void AModule5ProjHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void AModule5ProjHUD::DrawHUD()
{
	Super::DrawHUD();

	// Draw very simple crosshair

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition( (Center.X),
										   (Center.Y + 20.0f));

	// draw the crosshair
	FCanvasTileItem TileItem( CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem( TileItem );
}

void AModule5ProjHUD::UpdateAbilitySwapBar(float currentValue, float maxValue)
{
	if(AbilityWidget)
	{
		AbilityWidget->UpdateAbilitySwapBar(currentValue, maxValue);
	}
}

void AModule5ProjHUD::UpdateAbilityShieldBar(int value)
{
	if(AbilityWidget)
	{
		AbilityWidget->UpdateAbilityShieldBar(value);
	}
}

void AModule5ProjHUD::ShowMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		MenuWidget = SNew(SMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget).PossiblyNullContent(MenuWidget.ToSharedRef()));
		UGameplayStatics::SetGamePaused(GetWorld(),true);
	}

	if(PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = true;
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
}

void AModule5ProjHUD::RemoveMenu()
{
	if (GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
		UGameplayStatics::SetGamePaused(GetWorld(), false);

		if(PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

