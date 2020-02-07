// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CIWSTankController.generated.h"

/**
 * 
 */
class UTankAimingComponent;
class USphereComponent;


UCLASS()
class BATTLETANK_API ACIWSTankController : public AAIController
{
	GENERATED_BODY()

private:

	//how close the AI tank auto move to player
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UTankAimingComponent* AimingComponent;
	USphereComponent* CollisionSphere;
};
	
