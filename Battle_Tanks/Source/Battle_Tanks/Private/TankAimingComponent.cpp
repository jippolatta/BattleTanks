// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelRefernce(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
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
	if (UGameplayStatics::SuggestProjectileVelocity(this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace)
		)
	{
		//Turn velocity into a unit vector
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//Tank name
		auto TankName = GetOwner()->GetName();
		//Log the aim unit vector
		UE_LOG(LogTemp, Warning, TEXT("%s is aiming at: %s"), *TankName, *AimDirection.ToString());
	}

	
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

