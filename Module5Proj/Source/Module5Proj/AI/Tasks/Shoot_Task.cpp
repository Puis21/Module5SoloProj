// Fill out your copyright notice in the Description page of Project Settings.


#include "Shoot_Task.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Module5Proj/AI/AI_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Module5Proj/Blackboard_Keys.h"
#include "Module5Proj/AI/AI_Character.h"


UShoot_Task::UShoot_Task()
{
	NodeName = "AI_Shooting";
}

EBTNodeResult::Type UShoot_Task::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	Super::ExecuteTask(owner_comp, node_memory);

	ACharacter* const player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	auto const cont =  Cast<AAI_Controller>(owner_comp.GetAIOwner());

	//FVector const playerloc = player->GetActorLocation();
	if(search_random)
	{
		AAI_Character* AIChar = Cast<AAI_Character>(cont->GetPawn());
		//FNavLocation loc;
		//UNavigationSystemV1* const nav_sys = UNavigationSystemV1::GetCurrent(GetWorld());
		//if(nav_sys->GetRandomPointInNavigableRadius(playerloc, search_radius, loc, nullptr))
		//{
			//cont->getBlackboard()->SetValueAsVector(bb_keys::target_location, loc.Location);
			cont->SetFocus(player);
			AIChar->Shoot();
		//}
	}
	else
	{
		//cont->getBlackboard()->SetValueAsVector(bb_keys::target_location, playerloc);
	}

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;

}