// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShipTechGameMode.generated.h"

UCLASS(minimalapi)
class AShipTechGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AShipTechGameMode();

	float GetTimeAlive() { return TimeAlive; }

protected:
	virtual void Tick(float deltaTime) override;
private:
	float TimeAlive = 0.0f;
};



