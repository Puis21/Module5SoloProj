// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/TimelineComponent.h"
#include "PlayerCameraComponent.generated.h"

enum class EMovementState : uint8;
class APlayerCharacter;
class UPlayerMovementComponent;

UCLASS()
class MODULE5PROJ_API UPlayerCameraComponent : public UCameraComponent
{
	GENERATED_BODY()

public:

	UPlayerCameraComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	APlayerCharacter* m_pAPlayerCharacter;

	UPlayerMovementComponent* m_pPlayerMovementComponent;

protected:

	UPROPERTY(EditDefaultsOnly, Category = FOV, DisplayName = "Walk FOV")
		float m_fWalkFOV;

	UPROPERTY(EditDefaultsOnly, Category = FOV, DisplayName = "Sprint FOV")
		float m_fSprintFOV;

	float m_fChangedFOV;

	UFUNCTION()
		void FOVTimelineProgress(float fFOVProgress);

	UPROPERTY(EditDefaultsOnly, Category = FOV, DisplayName = "Curve float")
		UCurveFloat* m_pCameraFOVCurve;

	FTimeline FOVTimeline;

public:

	void UpdateFOV(EMovementState eMovementState);
};
