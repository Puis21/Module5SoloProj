// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Components/TimelineComponent.h>
#include "PlayerMovementComponent.generated.h"

class APlayerCharacter;
class UPlayerCameraComponent;
class UCameraComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	//Stopped		UMETA(DisplayName = "Stopped"),
	Walking		UMETA(DisplayName = "Walking"),
	Jumping		UMETA(DisplayName = "Jumping"),
	Sprinting	UMETA(DisplayName = "Sprinting"),
	Crouching	UMETA(DisplayName = "Crouching"),
	Sliding		UMETA(DisplayName = "Sliding"),
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MODULE5PROJ_API UPlayerMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPlayerMovementComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void StartSprinting();

	void StopSprinting();

	void StartCrouching();

	void UnCrouching();

	void Crouching();

	void StartSlide();

	void StopSlide();

	void ResolveMovement();

	void SetMovementState(EMovementState& eNewMovementState);

	//OnEnterMovementState
	void OnMovementStateChange(EMovementState& eNewMovementState);

	//SwitchMovementState
	void SwitchMovementState(EMovementState& eNewMovementState);

	//InitiateMovementStateSwitch
	void StartMovementStateSwitch(EMovementState eNewMovementState);

	bool CanSprint() const;

	bool CanStand() const;

	//check collision
	bool CheckCapsuleCollision(FVector Center, float HalfHeight, float Radius, bool DrawDebug)const;

	EMovementState GetMovementState() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Timeline for crouching
	FTimeline m_CrouchingTimeline;

	//Curve float for crouch
	UPROPERTY(EditAnywhere, Category = "Timeline | Capsule Scale Down")
		UCurveFloat* m_pCapsuleHalfHeightCurve;

public:

	UFUNCTION()
		void TimelineProgress(float fTransitionProgress);

	EMovementState eMovementState;

	bool bisSprinting;
	bool bisCrouching;

	float m_fStandingCapsuleHalfHeight;
	float m_fStandingCameraZOffSet;

	float SetSpeed() const;

	APlayerCharacter* m_pPlayerCharacter;
	UPlayerCameraComponent* m_pCameraComponent;

private:

	UPROPERTY(Category = "Player Capsule Size", EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "10.0", ClampMax = "60.0", AllowPrivateAccess = "true"))
		float m_fCrouchingCapsuleHalfHeight;

	UPROPERTY(Category = "Player Camera", EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "10.0", ClampMax = "100.0", AllowPrivateAccess = "true"))
		float m_fCrouchingCameraZOffset;

	UPROPERTY(Category = "Movement | Sprint | Speed", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), DisplayName = "Sprint Speed")
		float m_fSprindSpeed;

	UPROPERTY(Category = "Movement | Crouch | Speed", EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), DisplayName = "Sprint Speed")
		float m_fCrouchSpeed;

};