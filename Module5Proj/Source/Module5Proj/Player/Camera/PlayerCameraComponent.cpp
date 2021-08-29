// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCameraComponent.h"
#include "Components/TimelineComponent.h"
#include "Module5Proj/Player/PlayerCharacter.h"
#include "Module5Proj/Player/Components/PlayerMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

UPlayerCameraComponent::UPlayerCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	m_fWalkFOV = 90.f;
	m_fSprintFOV = 105.f;
	m_fChangedFOV = FieldOfView;

}

void UPlayerCameraComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* OwnerCharacter = GetOwner();
	if(OwnerCharacter)
	{
		m_pAPlayerCharacter = Cast<APlayerCharacter>(GetOwner());
		if(m_pAPlayerCharacter)
		{
			UPlayerMovementComponent* OwnerMovementComponent = m_pAPlayerCharacter->GetPlayerMovementComponent();
			if(OwnerMovementComponent)
			{
				m_pPlayerMovementComponent = OwnerMovementComponent;
			}
		}
	}

	

	if(m_pCameraFOVCurve)
	{
		FOnTimelineFloat FOVTimelineProgress;
		FOVTimelineProgress.BindUFunction(this, FName("FOVTimelineProgress"));
		FOVTimeline.AddInterpFloat(m_pCameraFOVCurve, FOVTimelineProgress);
	}
}

void UPlayerCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (FOVTimeline.IsPlaying())
	{
		FOVTimeline.TickTimeline(DeltaTime);
	}
}


void UPlayerCameraComponent::FOVTimelineProgress(float fFOVProgress)
{
	float FOV = FieldOfView;
	FOV = FMath::Lerp(FieldOfView, m_fChangedFOV, fFOVProgress);
	FieldOfView = FOV;
}

void UPlayerCameraComponent::UpdateFOV(EMovementState eMovementState)
{
	if(eMovementState == EMovementState::Sprinting)
	{
		m_fChangedFOV = m_fSprintFOV;
	}
	else
	{
		m_fChangedFOV = m_fWalkFOV;
	}

	if (FOVTimeline.IsPlaying())
	{
		FOVTimeline.Stop();
	}

	FOVTimeline.PlayFromStart();

}