// Fill out your copyright notice in the Description page of Project Settings.


#include "HullBreach.h"
#include "Components/BoxComponent.h"
#include "ShipTech/ShipTechCharacter.h"
#include "ShipTech/ShipTechGameMode.h"

void AHullBreach::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AHullBreach::OverlapBegin);
}

// Sets default values
AHullBreach::AHullBreach()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	Integrity = 100.0f;
}

void AHullBreach::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AShipTechCharacter* Character = Cast<AShipTechCharacter>(OtherActor);

	if (GEngine && Character)
	{
		// GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("yelllo!"));
	}

	AShipTechGameMode* GameMode = Cast<AShipTechGameMode>(GetWorld()->GetAuthGameMode());
	/*if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("Time alive: %f"), GameMode->GetTimeAlive()));*/
}

