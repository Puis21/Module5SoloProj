// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Module5Proj/Player/Components/AbilityComponent.h"
#include "Ability_Shield.generated.h"

class APlayerCharacter;
class AModule5ProjHUD;

UCLASS()
class MODULE5PROJ_API UAbility_Shield : public UAbilityComponent
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UAbility_Shield();

	void AbilityUsed();

	void ShieldDuration();

	void ShieldStop();

	bool GetShieldActive() const { return m_bAbilityActive; }
	
	void SetAbilityCharges(int size) { m_iCurrentAbilityCharges = size; }

	int GetCurrentShieldCharges() const { return m_iCurrentAbilityCharges; }

	int GetMaxShieldCharges() const { return m_iMaxAbilityCharges; }

protected:

	APlayerCharacter* m_ACPlayerCharacter;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shield)
	class UParticleSystem* m_pShieldParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shield)
	class UParticleSystemComponent* m_pShieldParticleComponent;

	UPROPERTY(BlueprintReadOnly)
	FTimerHandle TimerAbilityActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sounds)
	USoundBase* ShieldActivate;

private:

	UPROPERTY(EditAnywhere)
		FVector m_v3EmitterSpawnOffset;

	UPROPERTY(EditAnywhere)
		float m_fMaxShieldDuration;

	UPROPERTY(EditAnywhere)
		float m_fCurrentShieldDuration;

	AModule5ProjHUD* GameHUD;
};