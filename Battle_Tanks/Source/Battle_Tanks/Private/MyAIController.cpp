// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "Engine/World.h"


void AMyAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI cannot find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller found player: %s"), *(PlayerTank->GetName()));
	}
	
}

void AMyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Make sure there is a tank to aim at
	if (GetPlayerTank())
	{
		//TODO Move towards player

		//Aim at the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire when ready
	}
}

//Get the tank that the AI is possesing
ATank* AMyAIController::GetControlledTank() const
{
	//Return the cast to the tank by getting the pawn
	return Cast<ATank>(GetPawn());
}

ATank* AMyAIController::GetPlayerTank() const
{
	//Get the player pawn
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	//Break out of function if we did not find it
	if (!PlayerPawn) { return nullptr; }

	//Return the cast from player pawn to ATank
	return Cast<ATank>(PlayerPawn);
}



