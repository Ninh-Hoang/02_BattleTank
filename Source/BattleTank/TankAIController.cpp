// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "TankPlayerController.h"

class ATank;

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (ensure(PlayerTank || AimingComponent)) {
		MoveToActor(PlayerTank, AcceptanceRadius); 
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		AimingComponent->Fire();	
	}
}