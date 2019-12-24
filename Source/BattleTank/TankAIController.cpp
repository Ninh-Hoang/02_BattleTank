// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankPlayerController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	ATank* tank = GetTank();
	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("No Tank Found"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank found %s"), *PlayerTank->GetName())
	}
}

ATank* ATankAIController::GetTank() const{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {
	APawn* PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) {
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}
