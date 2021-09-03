// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityWidget.h"

#include "Module5Proj/Player/Abilities/Ability_PositionSwap.h"
#include "Module5Proj/Player/Abilities/Ability_Shield.h"

UAbilityWidget::UAbilityWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UAbilityWidget::NativeConstruct()
{
	Super::NativeConstruct();
}


void UAbilityWidget::UpdateAbilitySwapBar(class UAbility_PositionSwap* AbilityComp)
{
	if(AbilitySwapBar && AbilitySwapImage)
	{
		AbilitySwapImage->SetVisibility(ESlateVisibility::Visible);
		AbilitySwapBar->SetVisibility(ESlateVisibility::Visible);
		float currentValue = AbilityComp->GetCurrentAbilitySize();
		float maxValue = AbilityComp->GetMaxAbilitySize();
		AbilitySwapBar->SetPercent(currentValue / maxValue);
	}
}

void UAbilityWidget::UpdateAbilityShieldBar(class UAbility_Shield* AbilityComp)
{
	if(AbilityShieldFillOne && AbilityShieldFillTwo && AbilityShieldFillThree)
	{
		AbilityShieldFillOne->SetVisibility(ESlateVisibility::Visible);
		AbilityShieldFillTwo->SetVisibility(ESlateVisibility::Visible);
		AbilityShieldFillThree->SetVisibility(ESlateVisibility::Visible);
	}

	int value = AbilityComp->GetCurrentShieldCharges();

	if(value >= 3)
	{
		AbilityShieldFillThree->SetCheckedState(ECheckBoxState::Checked);
		AbilityShieldFillTwo->SetCheckedState(ECheckBoxState::Checked);
		AbilityShieldFillOne->SetCheckedState(ECheckBoxState::Checked);
	}

	if (value == 2)
	{

		AbilityShieldFillThree->SetCheckedState(ECheckBoxState::Unchecked);
	}

	if (value == 1)
	{
		AbilityShieldFillTwo->SetCheckedState(ECheckBoxState::Unchecked);
	}

	if(value == 0)
	{
		AbilityShieldFillOne->SetCheckedState(ECheckBoxState::Unchecked);
	}

}
