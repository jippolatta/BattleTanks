// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	//Run the parent's begin play
	Super::BeginPlay();
	

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Player Controller not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair()
}


void ATankPlayerController::AimTowardsCrosshair()
{
	//Get out if there is no controlled tank
	if (!GetControlledTank()) { return; }
}

ATank* ATankPlayerController::GetControlledTank() const
{
	//Cast to ATank and get the pawn - should return the tank that is being possesed
	return Cast<ATank>(GetPawn());

}


