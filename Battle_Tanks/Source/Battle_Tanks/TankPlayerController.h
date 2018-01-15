// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" ///Has to be last

/**
 * 
 */
UCLASS()
class BATTLE_TANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;
	
	//Overwrite the begin play from parent (AActor) - can be overridden as parent has it as virtual void 
	void BeginPlay() override;

	//Tick
	virtual void Tick(float DeltaTime) override;


	

private:
	//Return an out parameter, true if hit landscape
	//Passes a reference of the FVector - it is how out parameters work
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	//Aim towards the onscreen crosshair/aim reticle
	void AimTowardsCrosshair();

	//Get the look direction. Returns true if it worked. Outputs the LookDirection
	//Const becuase getting the direction should not change any variables
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	//Get the location that are ray cast hits up to a max distance
	//Returns true if we hit something. Also returns that HitLocation
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	//How far the line trace can reach. Defaults to 10km (10 000 00)
	UPROPERTY(EditAnywhere)
		float LineTraceReach = 1000000;
	

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AimReticle)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AimReticle)
		float CrosshairYLocation = .3333;

	
	
};
