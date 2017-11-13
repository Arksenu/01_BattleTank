// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



void ATankAIController::BeginPlay() 
{
	Super::BeginPlay();
		if (GetPlayerTank())
		{
			UE_LOG(LogTemp, Warning, TEXT("TankAIController detected player: %s"), *GetPlayerTank()->GetName())
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("AIController can't find player tank"));
		}
}

ATank* ATankAIController::GetAITank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);

}

