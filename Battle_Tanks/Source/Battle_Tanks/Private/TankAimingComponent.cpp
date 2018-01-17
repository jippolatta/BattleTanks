// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Engine/World.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelRefernce(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
}

//Tell the tank to aim at HitLocation
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//Make sure we have a reference to the barrel
	if (!Barrel) { return; }

	//Outparameter we get from the suggestprojectilevelocity
	FVector OutLaunchVelocity;
	//Start the launch from the end of the barrel - where we have the socket
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Only print if it was calculated
	//Calculate the out launch velocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace);

	if(bHaveAimSolution)
	{
		//Turn velocity into a unit vector
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();

		MoveBarrelTowards(AimDirection);

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f Aim Solution Found"), Time)
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f No Aim Solution Found"), Time)

	}

	
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//Work out the difference between the current barrel rotation and the AimDirection
	//Current barrel rotation (Pitch, roll, yaw)
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	//Current aim rotation
	auto AimAsARotator = AimDirection.Rotation();
	//Difference between the rotator of the aim and the rotator of the barrel
	auto DeltaRotator = AimAsARotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *AimAsARotator.ToString());

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}
