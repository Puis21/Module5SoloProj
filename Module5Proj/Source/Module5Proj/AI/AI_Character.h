
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/TimelineComponent.h"
#include "AI_Character.generated.h"

class APlayerCharacter;
class ABaseWeapon;

UCLASS()
class MODULE5PROJ_API AAI_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI_Character();

	APlayerCharacter* m_pPlayerCharacter;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	APlayerCharacter* GetPlayerCharacter() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		class UParticleSystem* m_psBloodEffect;

	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere)
		USceneComponent* MuzzleComponent;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AModule5ProjProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
		bool bisDead;

	USceneComponent* GetMuzzleComponent();

	FTimerHandle DespawnTimer;

	void DestroyEnemy();

	void Shoot();

	void KillEnemy();

private:
	/*UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseWeapon> WeaponClass;

	UPROPERTY()
		ABaseWeapon* Weapon;*/

};