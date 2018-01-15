// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANKS_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;

	//Get the tank that the AI is controlling
	ATank* GetControlledTank() const;

	//Get the tank that the player is controlling
	ATank* GetPlayerTank() const;
	
	
};
