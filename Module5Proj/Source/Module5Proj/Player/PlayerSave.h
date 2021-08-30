// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlayerSave.generated.h"

UCLASS()
class MODULE5PROJ_API UPlayerSave : public USaveGame
{
	GENERATED_BODY()

public:

	UPlayerSave();

	UPROPERTY(EditAnywhere)
	FVector PlayerLocation;

	UPROPERTY(EditAnywhere)
	FRotator PlayerRotation;

	void SavePlayerPos(FVector loc, FRotator rot);

	//void SetPlayerLoc(FVector loc) { PlayerLocation = loc; }
	//void SetPlayerRot(FRotator rot) { PlayerRotation = rot; }

};
