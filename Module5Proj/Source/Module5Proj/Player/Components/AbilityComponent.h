// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MODULE5PROJ_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAbilityComponent();

	//Max Ability CD
	UPROPERTY(EditAnywhere)
		float m_fMaxAbilitySize;

	//Current CD
	UPROPERTY(VisibleAnywhere)
		float m_fCurrentAbilitySize;

	//Decrease CD rate
	UPROPERTY(VisibleAnywhere)
		float m_fAbilityDecreaseRate;

	//Increase CD rate
	UPROPERTY(EditAnywhere)
		float m_fAbilityIncreaseRate;

	//Max Ability Charges
	UPROPERTY(EditAnywhere)
		int m_iMaxAbilityCharges;

	//Current Ability Charges
	UPROPERTY(VisibleAnywhere)
		int m_iCurrentAbilityCharges;

	//bool ability active
	UPROPERTY(VisibleAnywhere)
		bool m_bAbilityActive;

	//bool can use ability
	UPROPERTY(VisibleAnywhere)
		bool m_bCanUseAbility;

	//timer ability decrease
	UPROPERTY(BlueprintReadOnly)
		FTimerHandle TimerAbilityDecreaseRate;
};