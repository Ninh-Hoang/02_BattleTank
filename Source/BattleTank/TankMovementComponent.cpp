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
    if (!ensure (LeftTrack && RightTrack)) { return; }
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntentTurnRight(float Throw) {
    if (!ensure(LeftTrack && RightTrack)) { return; }
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
    if (!ensure(LeftTrackToSet && RightTrackToSet)) { return; }
    LeftTrack = LeftTrackToSet;
    RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed){
    //No need Super, only need the MoveVelocity
    FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
    FVector AIForwardIntention = MoveVelocity.GetSafeNormal();
    float ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
    float RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
    IntentMoveForward(ForwardThrow);
    IntentTurnRight(RightThrow);
}