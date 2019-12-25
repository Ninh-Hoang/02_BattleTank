// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION (BlueprintCallable, Category = Setup)
	void SetBarrelRefernce(UTankBarrel* Barrel);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void AimAt(FVector HitLocation);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

private:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 10000.;

};
