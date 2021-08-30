// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"
#include "Module5Proj/Module5ProjHUD.h"

AMenuPlayerController::AMenuPlayerController()
{
	m_bIsPaused = false;
}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if(InputComponent)
	{
		InputComponent->BindAction("OpenMenu", IE_Pressed, this, &AMenuPlayerController::OpenMenu).bExecuteWhenPaused = true;
	}
}

void AMenuPlayerController::OpenMenu()
{
	if(AModule5ProjHUD* MenuHUD = Cast<AModule5ProjHUD>(GetHUD()))
	{
		if(!m_bIsPaused)
		{
			MenuHUD->ShowMenu();
			m_bIsPaused = true;
		}
		else
		{
			MenuHUD->RemoveMenu();
			m_bIsPaused = false;
		}
	}
}
