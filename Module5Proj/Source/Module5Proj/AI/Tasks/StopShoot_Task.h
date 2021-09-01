// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "StopShoot_Task.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MODULE5PROJ_API UStopShoot_Task : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UStopShoot_Task(FObjectInitializer const& object_initializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory) override;

};
