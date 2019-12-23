// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* tank = GetControlledTank();
	if (!tank){
		UE_LOG(LogTemp, Warning, TEXT("No tank found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("ATank name is %s"), *tank->GetName());
	}
}

