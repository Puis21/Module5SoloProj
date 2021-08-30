// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerSave.h"

UPlayerSave::UPlayerSave()
{
	PlayerLocation = FVector::ZeroVector;
	PlayerRotation = FRotator::ZeroRotator;
}

void UPlayerSave::SavePlayerPos(FVector loc, FRotator rot)
{
	PlayerLocation = loc;
	PlayerRotation = rot;
}
