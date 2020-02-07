// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "TankAimingComponentIronDome.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponentIronDome : public UTankAimingComponent
{
	GENERATED_BODY()
	
private:
	//UTankAimingComponentIronDome();

	//virtual void BeginPlay() override;

	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	//virtual void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet) override;

	UFUNCTION(BlueprintCallable, Category = Action)
	void Launch();
};
