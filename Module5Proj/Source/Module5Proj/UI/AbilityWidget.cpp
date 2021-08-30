// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityWidget.h"

UAbilityWidget::UAbilityWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

void UAbilityWidget::NativeConstruct()
{
	Super::NativeConstruct();
}


void UAbilityWidget::UpdateAbilitySwapBar(float currentValue, float maxValue)
{
	if(AbilitySwapBar && AbilitySwapImage)
	{
		AbilitySwapImage->SetVisibility(ESlateVisibility::Visible);
		AbilitySwapBar->SetVisibility(ESlateVisibility::Visible);
		AbilitySwapBar->SetPercent(currentValue / maxValue);
	}
}

void UAbilityWidget::UpdateAbilityShieldBar(int value)
{
	if(AbilityShieldFillOne && AbilityShieldFillTwo && AbilityShieldFillThree)
	{
		AbilityShieldFillOne->SetVisibility(ESlateVisibility::Visible);
		AbilityShieldFillTwo->SetVisibility(ESlateVisibility::Visible);
		AbilityShieldFillThree->SetVisibility(ESlateVisibility::Visible);
	}

	if(value == 3)
	{
		AbilityShieldFillThree->SetCheckedState(ECheckBoxState::Unchecked);
	}

	if (value == 2)
	{
		AbilityShieldFillTwo->SetCheckedState(ECheckBoxState::Unchecked);
	}

	if (value == 1)
	{
		AbilityShieldFillOne->SetCheckedState(ECheckBoxState::Unchecked);
	}

}


void UAbilityWidget::ResetAbilitySwapBar()
{
	
}
