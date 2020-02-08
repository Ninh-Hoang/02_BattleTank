// Fill out your copyright notice in the Description page of Project Settings.


#include "CIWSTankController.h"
#include "TankAimingComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "Components/SphereComponent.h"

#define OUT

ACIWSTankController::ACIWSTankController() {
}

void ACIWSTankController::BeginPlay() {
	Super::BeginPlay();
}

void ACIWSTankController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	DrawDebugSphere(
		GetWorld(),
		GetPawn()->GetActorLocation(),
		1000.,
		12,
		FColor(255, 0, 0),
		false
	);
	CollisionSphere = GetPawn()->FindComponentByClass<USphereComponent>();

	if (ensure(CollisionSphere || AimingComponent)) {
		TArray<AActor*> OverlapActors;
		CollisionSphere->GetOverlappingActors(OUT OverlapActors);
		//UE_LOG(LogTemp, Warning, TEXT("%i"), OverlapActors.Num());
		if (OverlapActors.Num() != 0) {
			//UE_LOG(LogTemp, Warning, TEXT("%s"), *OverlapActors[0]->GetName());
			AimingComponent->Intercept(OverlapActors[0]);
			//AimingComponent->AimAt(Prediction);
			//AimingComponent->Fire();
		}
	}
}
