// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityPickUp.generated.h"

class APlayerCharacter;

UCLASS()
class MODULE5PROJ_API AAbilityPickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbilityPickUp();

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Radius")
	FVector m_VBoxRadius;

	UPROPERTY(EditAnywhere, Category = "Rotate X")
	float m_fYawRotation;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MyMesh;

	void Interact(APlayerCharacter* pPlayer);
};
