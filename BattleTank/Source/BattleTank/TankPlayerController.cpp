// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"




void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
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

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) {return;}

	FVector OutHitLocation; //Out parameter
	if (GetSightRayHitLocation(OutHitLocation)) // side-effect, line trace
	{
		//UE_LOG(LogTemp, Log, TEXT("Looking at: %s"), *OutHitLocation.ToString());

		//TODO controlled tank to aim at point
	}
	

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D((ViewportSizeX*CrosshairXLocation), (ViewportSizeY*CrosshairYLocation));

	FVector LookDirection;
	//deproject screen position of the crosshair to a world direction
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Log, TEXT("Looking at: %s"), *LookDirection.ToString());
	}

	//line trace along that look direction (up to max range)
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; //To discard
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection);
}
