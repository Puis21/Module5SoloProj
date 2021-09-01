// Fill out your copyright notice in the Description page of Project Settings.


#include "StopShoot_Task.h"
#include "Module5Proj/AI/AI_Controller.h"

UStopShoot_Task::UStopShoot_Task(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("AI_StopShoot");
}

EBTNodeResult::Type UStopShoot_Task::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	auto const cont = Cast<AAI_Controller>(owner_comp.GetAIOwner());

	cont->ClearFocus(EAIFocusPriority::Gameplay);

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
