// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability_Shield.h"
#include "Module5Proj/Player/PlayerCharacter.h"
#include "Particles/ParticleSystemComponent.h"
#include "Module5Proj/Module5ProjHUD.h"
#include "Kismet/GameplayStatics.h"


UAbility_Shield::UAbility_Shield()
{
	
    PrimaryComponentTick.bCanEverTick = true;

    m_iMaxAbilityCharges = 3;
    m_iCurrentAbilityCharges = m_iMaxAbilityCharges;

    m_fMaxShieldDuration = 3.f;
    m_fCurrentShieldDuration = m_fMaxShieldDuration;
}

void UAbility_Shield::BeginPlay()
{
    Super::BeginPlay();

    m_ACPlayerCharacter = Cast<APlayerCharacter>(GetOwner());
    GameHUD = Cast<AModule5ProjHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
    //if (GameHUD)
    //{
    //    GameHUD->UpdateAbilityShieldBar(m_iCurrentAbilityCharges);
    //}

}

void UAbility_Shield::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    //if (GEngine)
    //{
    //    GEngine->AddOnScreenDebugMessage(-1, GetWorld()->GetDeltaSeconds(), FColor::Purple, FString::SanitizeFloat(m_fCurrentAbilitySize));
    //}

}


void UAbility_Shield::AbilityUsed()
{
	if(m_iCurrentAbilityCharges > 0 && m_bCanUseAbility && !m_bAbilityActive)
	{
        //if (GameHUD)
        //{
        //    GameHUD->UpdateAbilityShieldBar(m_iCurrentAbilityCharges);
        //}
		GetWorld()->GetTimerManager().SetTimer(TimerAbilityActive, this, &UAbility_Shield::ShieldDuration, 1.f, true);
        UGameplayStatics::PlaySound2D(GetWorld(), ShieldActivate, 0.75, 1);
		m_iCurrentAbilityCharges--;
		m_bAbilityActive = true;
		m_bCanUseAbility = false;

		FVector const ForwardVec = m_ACPlayerCharacter->GetActorLocation();
		FRotator const Rotation = m_ACPlayerCharacter->GetActorRotation();
        m_pShieldParticleComponent = UGameplayStatics::SpawnEmitterAttached(m_pShieldParticleSystem, 
        m_ACPlayerCharacter->GetMesh1P(), FName("ShieldSocket"), ForwardVec,
        Rotation, FVector(1.f, 1.f, 1.f), EAttachLocation::KeepWorldPosition, true);
    }
}

void UAbility_Shield::ShieldDuration()
{
    if (m_fCurrentShieldDuration <= m_fMaxShieldDuration && m_fCurrentShieldDuration != 0)
    {
        m_fCurrentShieldDuration--;
    }
    else
    {
        ShieldStop();
    }
}

void UAbility_Shield::ShieldStop()
{
    m_bAbilityActive = false;
    m_bCanUseAbility = true;
    m_fCurrentShieldDuration = m_fMaxShieldDuration;
    m_pShieldParticleComponent->Deactivate();
    GetWorld()->GetTimerManager().ClearTimer(TimerAbilityActive);
}