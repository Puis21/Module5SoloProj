// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MODULE5PROJ_API AMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AMenuPlayerController();

	virtual void SetupInputComponent() override;

	void OpenMenu();

	bool m_bIsPaused;
};