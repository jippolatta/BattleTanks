// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

///Forward Declerations
class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;

UCLASS()
class BATTLE_TANKS_API ATank : public APawn
{
	GENERATED_BODY()



public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//The location that we want the tank to aim at
	void AimAt(FVector HitLocation);

	//Set the barrel reference in the aiming component
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	//Set the reference to the turret in the TankAimingComponent
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);


private:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Set the launch speed of the projectile
	UPROPERTY(EditAnywhere, Category = Firing)
		//TODO Find sensible default
		float LaunchSpeed = 100000;

protected:
	//Reference to the tank aiming component
	UTankAimingComponent * TankAimingComponent = nullptr;

	
	
};
