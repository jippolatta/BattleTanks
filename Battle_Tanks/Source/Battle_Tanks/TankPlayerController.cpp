// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const
{
	//Cast to ATank and get the pawn - should return the tank that is being possessed
	return Cast<ATank>(GetPawn());
}


