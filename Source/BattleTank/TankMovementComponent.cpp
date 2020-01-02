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
    if (!LeftTrack || !RightTrack) { return; }
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntentTurnRight(float Throw) {
    if (!LeftTrack || !RightTrack) { return; }
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
    if (!LeftTrackToSet || !RightTrackToSet) { return; }
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}