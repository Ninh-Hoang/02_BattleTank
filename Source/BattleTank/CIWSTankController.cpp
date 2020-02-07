// Fill out your copyright notice in the Description page of Project Settings.


#include "CIWSTankController.h"
#include "TankAimingComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"
#include "Components/SphereComponent.h"

#define OUT

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

	if (ensure(CollisionSphere)) {
		TArray<AActor*> OverlapActors;
		TSubclassOf<EObjectTypeQuery> Temp;
		CollisionSphere->GetOverlappingActors(OUT OverlapActors);
		for(const AActor* Actor : OverlapActors) {
			//UE_LOG(LogTemp, Warning, TEXT("%s"), *Actor->GetName());
		}
	}
	if (ensure(AimingComponent)) {
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *AimingComponent->GetName());
	}

}

