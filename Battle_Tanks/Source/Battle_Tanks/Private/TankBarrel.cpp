// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Clamp the relative speed
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	//Elevation change this frame
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	//What is the new elevation, ignoring the max and minimum elevation limitations
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	//Clamp the elevation
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegress);
	//Update the elevation
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}


