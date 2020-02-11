// Fill out your copyright notice in the Description page of Project Settings.


#include "CIWSTankController.h"
#include "TankAimingComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "Components/SphereComponent.h"
#include "Tank.h"

#define OUT

void ACIWSTankController::BeginPlay() {
	Super::BeginPlay();
}

void ACIWSTankController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	/*AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	CollisionSphere = GetPawn()->FindComponentByClass<USphereComponent>();
	
	if (ensure(CollisionSphere) || ensure(AimingComponent)) {
		TArray<AActor*> OverlapActors;
		CollisionSphere->GetOverlappingActors(OUT OverlapActors);
		//UE_LOG(LogTemp, Warning, TEXT("%i"), OverlapActors.Num());
		if (OverlapActors.Num() != 0) {
			//UE_LOG(LogTemp, Warning, TEXT("%s"), *OverlapActors[0]->GetName());
			AimingComponent->AimAt(OverlapActors[0]->GetActorLocation());
			//AimingComponent->Intercept(OverlapActors[0]);
			//AimingComponent->AimAt(Prediction);
			//AimingComponent->Fire();
		}
	}*/

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (ensure(PlayerTank || AimingComponent)) {
		AimingComponent->AimAt(PlayerTank->GetActorLocation());
		AimingComponent->Fire();
	}
}
