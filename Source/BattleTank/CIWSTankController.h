// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/World.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "CIWSTankController.generated.h"

/**
 * 
 */
class UTankAimingComponent;
class USphereComponent;
class ATank;

UCLASS()
class BATTLETANK_API ACIWSTankController : public AAIController
{
	GENERATED_BODY()

private:

	//how close the AI tank auto move to player
	void BeginPlay() override;
	

	void Tick(float DeltaTime) override;

	//UTankAimingComponent* AimingComponent;
	USphereComponent* CollisionSphere;
};
