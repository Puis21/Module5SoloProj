// Fill out your copyright notice in the Description page of Project Settings.


#include "Checkpoint.h"
#include "Components/BoxComponent.h"
#include "Module5Proj/Player/PlayerCharacter.h"
#include "Module5Proj/Player/PlayerSave.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACheckpoint::ACheckpoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneComp"));
	RootComponent = SceneComp;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->InitBoxExtent(FVector(40.f, 40.f, 40.f));
	BoxCollision->SetCollisionProfileName("Trigger");
	BoxCollision->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ACheckpoint::OnOverLapBegin);

}

// Called every frame
void ACheckpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckpoint::OnOverLapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
		if(Player)
		{
			UPlayerSave* SaveGameInstance = Cast<UPlayerSave>(UGameplayStatics::CreateSaveGameObject(UPlayerSave::StaticClass()));
			SaveGameInstance->SavePlayerPos(Player->GetActorLocation(), Player->GetActorRotation());
			UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Save Slot"), 0);
			UE_LOG(LogTemp, Warning, TEXT("Checkpoint Set"));
			Destroy();
		}
	}

}