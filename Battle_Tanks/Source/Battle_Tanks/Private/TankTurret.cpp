// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//Clamp the relative speed
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	//Calculate the rotation this frame/second
	auto RotationChange = RelativeSpeed * MaxRotationDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	//Calculate the new rotation - Turret can move 360 so does not need to be clamped
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	//Set the new relative Rotation
	SetRelativeRotation(FRotator(0, NewRotation, 0));

	UE_LOG(LogTemp, Warning, TEXT("Got here %f"), NewRotation)
}



