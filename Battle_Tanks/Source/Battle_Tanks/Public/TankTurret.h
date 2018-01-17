// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLE_TANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//Rotate the turret
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere)
		//Maximum amount the barrel can move per second
		float MaxRotationDegreesPerSecond = 5;
	
	
	
	
};
