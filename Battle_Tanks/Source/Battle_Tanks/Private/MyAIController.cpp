// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"


void AMyAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s is possesed by the AI controller"), *(ControlledTank->GetName()));
	}
	
}

//Get the tank that the AI is possesing
ATank* AMyAIController::GetControlledTank()
{
	//Return the cast to the tank and getting the pawn
	return Cast<ATank>(GetPawn());
}
