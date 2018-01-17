// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Forward decleration
class UTankBarrel;
class UTankTurret;

//Holds barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	//Set the reference to the Barrel
	void SetBarrelRefernce(UTankBarrel* BarrelToSet);

	//Set the reference to the turret
	void SetTurretReference(UTankTurret* TurretToSet);

	//Tell the tank to aim at HitLocation
	void AimAt(FVector HitLocation, float LaunchSpeed);

	//TODO add set turret reference


private:
	//Reference to the barrel
	UTankBarrel * Barrel = nullptr;

	//Reference to the turret
	UTankTurret* Turret = nullptr;

	//Method to move the barrel component of the tank
	void MoveBarrelTowards(FVector AimDirection);


		
	
};
