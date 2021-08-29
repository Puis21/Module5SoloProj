// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCameraShake.h"

UPlayerCameraShake::UPlayerCameraShake()
{
	OscillationDuration = 0.2f;
	OscillationBlendInTime = 0.1f;
	OscillationBlendOutTime = 0.2f;

	RotOscillation.Pitch.Amplitude = 0.5f;
	RotOscillation.Pitch.Frequency = 5.0f;

	RotOscillation.Yaw.Amplitude = 0.f;
	RotOscillation.Yaw.Frequency = 0.f;

	RotOscillation.Roll.Amplitude = 0.f;
	RotOscillation.Roll.Frequency = 0.f;
}
