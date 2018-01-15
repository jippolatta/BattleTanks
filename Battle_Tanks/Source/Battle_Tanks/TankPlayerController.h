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

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = .3333;

	
	
};
