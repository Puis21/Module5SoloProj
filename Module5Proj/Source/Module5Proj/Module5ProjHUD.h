// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "Components/WidgetComponent.h"
#include "Module5Proj/UI/AbilityWidget.h"

#include "Module5ProjHUD.generated.h"

UCLASS()
class AModule5ProjHUD : public AHUD
{
	GENERATED_BODY()

public:
	AModule5ProjHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void UpdateAbilitySwapBar(class UAbility_PositionSwap* AbilityComp);

	UFUNCTION()
	void UpdateAbilityShieldBar(class UAbility_Shield* AbilityComp);

	UFUNCTION()
	void UpdateHUD();

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> AbilityWidgetClass;

	void ShowMenu();
	void RemoveMenu();

	class APlayerCharacter* PlayerChar;

	class UAbility_PositionSwap* AbilityPosSwapComp;

	class UAbility_Shield* AbilityShieldComp;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	UAbilityWidget* AbilityWidget;

protected:

	TSharedPtr<class SMenuWidget> MenuWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;
};

