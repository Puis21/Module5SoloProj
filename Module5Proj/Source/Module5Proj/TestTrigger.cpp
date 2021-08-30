// Fill out your copyright notice in the Description page of Project Settings.


#include "TestTrigger.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATestTrigger::ATestTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CombatCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Combat Collision"));
	CombatCollision->InitBoxExtent(FVector(40.f, 40.f, 40.f));
	CombatCollision->SetCollisionProfileName("Trigger");
	RootComponent = CombatCollision;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Collision"));
	MyMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ATestTrigger::BeginPlay()
{
	Super::BeginPlay();

	CombatCollision->OnComponentBeginOverlap.AddDynamic(this, &ATestTrigger::OnOverLapBegin);
	CombatCollision->OnComponentEndOverlap.AddDynamic(this, &ATestTrigger::OnOverlapEnd);


}

// Called every frame
void ATestTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATestTrigger::OnOverLapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("ORICE"));
	}

}

void ATestTrigger::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{

	}
}
