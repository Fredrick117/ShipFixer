// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShipTechGameMode.h"
#include "ShipTechCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShipTechGameMode::AShipTechGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	PrimaryActorTick.bCanEverTick = true;

}

void AShipTechGameMode::Tick(float deltaTime)
{
	TimeAlive += deltaTime;
	/*if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, FString::Printf(TEXT("Time alive: %f"), TimeAlive));*/
}
