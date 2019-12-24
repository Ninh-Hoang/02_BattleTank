// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:

    UPROPERTY(EditAnywhere)  
    float CrosshairXLocation = 0.5;

    UPROPERTY(EditAnywhere)
    float CrosshairYLocation = 0.3;

    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000.;

    ATank* GetControlledTank() const;

    void BeginPlay() override;

    void Tick(float DeltaSecond) override; 

    void CrosshairAim();

    bool GetSightRayHitLocation(FVector& HitLocation) const;

    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

    bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

};
