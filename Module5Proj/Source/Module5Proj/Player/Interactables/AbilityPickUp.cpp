// Fill out your copyright notice in the Description page of Project Settings.


#include "Module5Proj//Player/Interactables/AbilityPickUp.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Module5Proj/Player/PlayerCharacter.h"
#include "Module5Proj/Player/Abilities/Ability_PositionSwap.h"
#include "Module5Proj/Player/Abilities/Ability_Shield.h"
#include "Module5Proj/Module5ProjHUD.h"

// Sets default values
AAbilityPickUp::AAbilityPickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxCollision->SetBoxExtent(m_VBoxRadius);
	BoxCollision->SetCollisionProfileName("Trigger");
	RootComponent = BoxCollision;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MY MESH"));
	MyMesh->SetupAttachment(RootComponent);

}

void AAbilityPickUp::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FQuat QuatRotation = FQuat(FRotator(0.f, m_fYawRotation, 0.f));

	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
}


void AAbilityPickUp::Interact(APlayerCharacter* pPlayer)
{
	if(pPlayer)
	{
		pPlayer->GetAbilityPosSwap()->SetAbilitySize(pPlayer->GetAbilityPosSwap()->GetMaxAbilitySize());
		pPlayer->GetAbilityShield()->SetAbilityCharges(pPlayer->GetAbilityShield()->GetMaxShieldCharges());
		AModule5ProjHUD* GameHUD = Cast<AModule5ProjHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
		GameHUD->UpdateHUD();
		MyMesh->SetStaticMesh(nullptr);
		BoxCollision->SetBoxExtent(FVector(0.f, 0.f, 0.f));
	}
}
