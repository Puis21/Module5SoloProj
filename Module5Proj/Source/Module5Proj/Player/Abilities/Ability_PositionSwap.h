// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Module5Proj/Player/Components/AbilityComponent.h"
#include "Ability_PositionSwap.generated.h"

class APlayerCharacter;
class AModule5ProjHUD;

UCLASS()
class MODULE5PROJ_API UAbility_PositionSwap : public UAbilityComponent
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UAbility_PositionSwap();

	void AbilityActivated();

	void AbilityCancelled();

	void AbilityUsed();

	UPROPERTY(BlueprintReadOnly)
		FTimerHandle Timer;

	bool GetAbilityActive() const { return m_bAbilityActive; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sounds)
	USoundBase* BeginTimeStop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sounds)
	USoundBase* FinishTimeStop;

	void SetAbilitySize(float size)	{ m_fCurrentAbilitySize = size; }

	float GetMaxAbilitySize() { return m_fMaxAbilitySize; }

	float GetCurrentAbilitySize() { return m_fCurrentAbilitySize; }

protected:

	UPROPERTY()
		APlayerCharacter* m_ACPlayerCharacter;

private:

	UFUNCTION()
		void DecreaseAbilitySize();

	AModule5ProjHUD* GameHUD;

};