// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"

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
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
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
	
	//Get the look direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}

	


	return true;
}

//"De-project" the screen position of the crosshair to a world direction
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	//Discarded but must be passed in
	FVector CameraWorldLocation;
	//Return whether the method worked
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	//Hit result variable. Outputs what the trace hits(if anything)
	FHitResult HitResult;
	//Start the cast at the location of our camera
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	//End the cast at the LineTraceRange in the look direction
	auto EndLocation = StartLocation + (LookDirection * LineTraceReach);

	//Line trace that will hit anything visible(does not hit skybox)
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		//Return saying that we hit something and where that something is
		OutHitLocation = HitResult.Location;
		return true;
	}
	//Else, we must not of hit anything
	OutHitLocation = FVector(0);
	return false;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	//Cast to ATank and get the pawn - should return the tank that is being possesed
	return Cast<ATank>(GetPawn());

}


