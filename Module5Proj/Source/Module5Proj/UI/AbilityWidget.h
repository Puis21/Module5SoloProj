// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/UMG.h"

#include "AbilityWidget.generated.h"

/**
 * 
 */
UCLASS()
class MODULE5PROJ_API UAbilityWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UAbilityWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	void UpdateAbilitySwapBar(class UAbility_PositionSwap* AbilityComp);

	void UpdateAbilityShieldBar(class UAbility_Shield* AbilityComp);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UProgressBar* AbilitySwapBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* AbilitySwapImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCheckBox* AbilityShieldFillOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCheckBox* AbilityShieldFillTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UCheckBox* AbilityShieldFillThree;
};
