// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "DrawDebugHelpers.h"

#define OUT


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet) {
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	//initialize LastFireTime
	LastFireTime = GetWorld()->GetTimeSeconds();
	AimDirection = FVector(0);
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
	if(GetWorld()->GetTimeSeconds() - LastFireTime < ReloadTime) {
		FiringState = EFiringState::Reloading;
	}
	else if (IsBarrelMoving()) {
		FiringState = EFiringState::Aiming;
	}
	else {
		FiringState = EFiringState::Locked;
	}
}

bool UTankAimingComponent::IsBarrelMoving() {
	if (!ensure(Barrel)) { return false; }
	auto BarrelForward = Barrel->GetForwardVector().GetSafeNormal();
	return !BarrelForward.FVector::Equals(AimDirection, 0.1);
}
void UTankAimingComponent::AimAt(FVector HitLocation) {
	if (!ensure(Barrel) || !ensure(Turret)) { return; }
	FVector LaunchVelocity = FVector(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUT LaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false ,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace); //comment this line to produce bugs

	if (bHaveAimSolution){
		AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
		//UE_LOG(LogTemp, Warning, TEXT("%s aims at the direction of %s"), *GetOwner()->GetName(), *AimDirection.ToString());
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("No solution found"));
	}
}

void UTankAimingComponent::Intercept(AActor* Projectile) {
	if (!ensure(Barrel) || !ensure(Turret) || !ensure(Projectile)) { return; }
	IncomingProjectile = Projectile;
	//AimAt(Projectile->GetActorLocation());
	/*FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	DrawDebugLine(GetWorld(),
		StartLocation,
		Projectile->GetActorLocation(),
		FColor(255, 0, 0),
		false);
	FVector Velocity = Projectile->GetVelocity();
	FVector Prediction = (GetWorld()->GetDeltaSeconds() + .5) * Velocity + Projectile->GetActorLocation();*/
	/*DrawDebugLine(GetWorld(),
		Projectile->GetActorLocation(),
		Prediction,
		FColor(0, 0, 255),
		false);
	DrawDebugSphere(
		GetWorld(),
		Prediction,
		100.,
		12,
		FColor(255, 0, 0),
		false
	);*/
	//AimAt(Prediction);
}

AActor* UTankAimingComponent::GetProjectile() {
	if (IncomingProjectile) {
		return IncomingProjectile;
	}
	else {
		return false;
	}
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection){
	if (!ensure(Barrel && Turret)) { return; }
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

void UTankAimingComponent::MoveTurret(FVector AimDirection){
}

void UTankAimingComponent::Fire()
{
	bool bIsReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTime;
	if (FiringState != EFiringState::Reloading) {
		if (!ensure(Barrel)) { return; }
		if (!ensure(ProjectileBlueprint)) { return; }
		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
}


