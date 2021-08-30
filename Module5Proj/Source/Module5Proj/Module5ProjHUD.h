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
	void UpdateAbilitySwapBar(float currentValue, float maxValue);

	UFUNCTION()
	void UpdateAbilityShieldBar(int value);

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> AbilityWidgetClass;

	void ShowMenu();
	void RemoveMenu();

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	UAbilityWidget* AbilityWidget;

protected:

	TSharedPtr<class SMenuWidget> MenuWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;
};

