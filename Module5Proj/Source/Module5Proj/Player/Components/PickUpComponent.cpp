// Fill out your copyright notice in the Description page of Project Settings.


#include "Module5Proj//Player/Components/PickUpComponent.h"
#include "Module5Proj/Player/Interactables/AbilityPickUp.h"
#include "Module5Proj/Player/PlayerCharacter.h"

// Sets default values for this component's properties
UPickUpComponent::UPickUpComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UPickUpComponent::OnOverLap(AActor* OtherActor)
{
	AbilityPickUp = Cast<AAbilityPickUp>(OtherActor);

	if(AbilityPickUp)
	{
		APlayerCharacter* PlayerChar = Cast<APlayerCharacter>(GetOwner());
		AbilityPickUp->Interact(PlayerChar);
	}
}
