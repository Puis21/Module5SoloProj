// Fill out your copyright notice in the Description page of Project Settings.


#include "ProximityDoor.h"
#include "Components/TimelineComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AProximityDoor::AProximityDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CanMove = false;

	VBoxRadius = FVector(32.0f, 32.0f, 32.0f);

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Comp"));
	RootComponent = SceneComponent;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	BoxCollision->SetBoxExtent(VBoxRadius);
	BoxCollision->SetCollisionProfileName("Trigger");
	BoxCollision->SetupAttachment(RootComponent);
	//RootComponent = BoxCollision;

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AProximityDoor::OnOverlapBegin);

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MY MESH"));
	MyMesh->SetupAttachment(RootComponent);

	m_fTimerDelay = 0.f;
}

// Called when the game starts or when spawned
void AProximityDoor::BeginPlay()
{
	Super::BeginPlay();

	if (CurveVector)
	{
		FOnTimelineVector TimelineProgress;
		TimelineProgress.BindUFunction(this, FName("TimelineProgress"));
		CurveTimeline.AddInterpVector(CurveVector, TimelineProgress);
		CurveTimeline.SetLooping(false);

		StartLoc = EndLoc = MyMesh->GetRelativeLocation();
		EndLoc += LocOffset;

	}

}

// Called every frame
void AProximityDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CanMove)
	{
		CurveTimeline.TickTimeline(DeltaTime);
	}

}

void AProximityDoor::TimelineProgress(float value)
{
	FVector NewLocation = FMath::Lerp(StartLoc, EndLoc, value);
	MyMesh->SetRelativeLocation(NewLocation);
}

void AProximityDoor::SetBool()
{
	if (!CanMove)
	{
		CanMove = true;
	}

	CurveTimeline.Play();
}

void AProximityDoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		//Destroy();
		UGameplayStatics::PlaySound2D(GetWorld(), VoiceSound, 1.f, 1.f);
		GetWorld()->GetTimerManager().SetTimer(TimerVoice, this, &AProximityDoor::SetBool, m_fTimerDelay, false);
		BoxCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	}
}

