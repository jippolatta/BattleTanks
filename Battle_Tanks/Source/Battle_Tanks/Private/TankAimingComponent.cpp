// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"


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
	//Log where the barrel's location as long as we have a reference to it
	if (Barrel)
	{
		UE_LOG(LogTemp, Warning, TEXT("Launch speed: %f"), LaunchSpeed);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Barrel not found"));
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

