 // Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "TankMovementComponent.h"

UTankMovementComponent::UTankMovementComponent() {
    PrimaryComponentTick.bCanEverTick = true;
}

void UTankMovementComponent::BeginPlay() {
    Super::BeginPlay();
}

void UTankMovementComponent::IntentMoveForward(float Throw) {
    UE_LOG(LogTemp, Warning, TEXT("Intend move forward: %f"), Throw);
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
    if (!LeftTrackToSet || !RightTrackToSet) { return; }
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}