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
	AimTowardsCrosshair();
}


void ATankPlayerController::AimTowardsCrosshair()
{
	//Get out if there is no controlled tank
	if (!GetControlledTank()) { return; }

	//Out parameter
	FVector HitLocation; 
	//Side effect - ray trace
	//Checking to see if we are going to hit the landscape
	//Only passing a reference to HitLocation, not actually HitLocation
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
	}
	
}

//Get the world location of linetrace through crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	///Find the crosshair position
	//The size of the current viewport
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation); //Eg if x is 1000 wide then half way across is 1000*.5
	UE_LOG(LogTemp, Warning, TEXT("Screen location: %s"), *ScreenLocation.ToString())
	//"De-project" the screen position of the crosshair to a world direction

	//Line-trace along that look direction, and see what we hit(up to max range)


	return true;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	//Cast to ATank and get the pawn - should return the tank that is being possesed
	return Cast<ATank>(GetPawn());

}


