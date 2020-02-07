// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "TankAimingComponentCIWS.generated.h"

/**
 * 
 */
class USphereComponent;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponentCIWS : public UTankAimingComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Action)
	void Intercept();

protected:
};



