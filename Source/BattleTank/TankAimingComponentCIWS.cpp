// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponentCIWS.h"
#include "Components/SphereComponent.h"


void UTankAimingComponentCIWS::Intercept() {
	TArray<AActor*> ActorList;
	CollisionSphere->GetOverlappingActors(ActorList);
	if (!ensure(CollisionSphere)) { return; }
	for (AActor* Actor : ActorList) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Actor->GetName());
	}
}