// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HullBreach.generated.h"

class UBoxComponent;

UCLASS()
class SHIPTECH_API AHullBreach : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly)
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* StaticMesh;
	
protected:
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AHullBreach();

	UBoxComponent* GetBoxComponent() const { return BoxComponent; }
	float GetIntegrity() const { return Integrity; }

	UFUNCTION()
		void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	/** Measures the integrity of this hull section, with 100 being fully intact. Any number besides 100 means that there is a breach. */
	float Integrity;
};
