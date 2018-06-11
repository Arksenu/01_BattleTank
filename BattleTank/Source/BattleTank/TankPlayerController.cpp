// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AimTowardsCrosshair();
	UE_LOG(LogTemp, Log, TEXT("PlayerController ticking..."));
}


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Possessing tank %s"), *GetControlledTank()->GetName());
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("NOT POSSESSING TANK"))
	}

}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

