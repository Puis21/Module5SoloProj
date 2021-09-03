// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Controller.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Module5Proj/Player/PlayerCharacter.h"
#include "Module5Proj/AI/AI_Character.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h" //wait
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Module5Proj/Blackboard_Keys.h"
#include "Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

AAI_Controller::AAI_Controller(FObjectInitializer const& object_initialiazer)
{
	//Initialize behavior tree and blackboard
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/AI/BP_BT.BP_BT'"));
	if (obj.Succeeded())
	{
		Behaviortree = obj.Object;
	}

	BehaviortreeComponent = object_initialiazer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviortreeComponent"));
	BlacboardComponent = object_initialiazer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComponent"));
	SetUpPeceptionSystem();

}

void AAI_Controller::BeginPlay()
{

	Super::BeginPlay();

	//Run Tree
	RunBehaviorTree(Behaviortree);
	BehaviortreeComponent->StartTree(*Behaviortree);

}

void AAI_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAI_Controller::OnPossess(APawn* const pawn)
{
	Super::OnPossess(pawn);

	//Initializse blackboard onposses
	if (BlacboardComponent)
	{
		BlacboardComponent->InitializeBlackboard(*Behaviortree->BlackboardAsset);
	}
}

UBlackboardComponent* AAI_Controller::getBlackboard() const
{
	return BlacboardComponent;
}

void AAI_Controller::OnTargetDetected(AActor* actor, FAIStimulus const stimulus)
{
	//if player detected
	if (auto const ch = Cast<APlayerCharacter>(actor))
	{
		getBlackboard()->SetValueAsBool(bb_keys::can_see_player, stimulus.WasSuccessfullySensed());
	}
}

void AAI_Controller::SetUpPeceptionSystem()
{
	sightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight_Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception_Component")));
	sightConfig->SightRadius = 1250.f;
	sightConfig->LoseSightRadius = sightConfig->SightRadius + 50.f;
	sightConfig->PeripheralVisionAngleDegrees = 90.f;
	sightConfig->SetMaxAge(5.f);
	sightConfig->AutoSuccessRangeFromLastSeenLocation = 900.f;
	sightConfig->DetectionByAffiliation.bDetectEnemies = true;
	sightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	sightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*sightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AAI_Controller::OnTargetDetected);
	GetPerceptionComponent()->ConfigureSense(*sightConfig);
}