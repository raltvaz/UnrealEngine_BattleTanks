// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {

		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing: %s"),*(ControlledTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	AimTowardsCrossHair();
	//UE_LOG(LogTemp, Warning, TEXT("TICK IS WORKING"));

}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair() {

	if (!GetControlledTank()) {
		return;
	}

	FVector HitLocation; //Out parameter

	if (GetSightRayHitLocation(HitLocation)) { //Has side-effect, is going to line trace

		//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *(HitLocation.ToString()));

		//Tell controlled tank to aim at this point
	}


}

//Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(OUT FVector& HitLocation) const {

	//Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXPosition, ViewportSizeY * CrosshairYPosition);

	//"De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation,LookDirection)) {

		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *(LookDirection.ToString()));
	}

	//Line-trace along that look direction, and see what we hit (up to max range)
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const {

	FVector CameraWorldLocation; //To be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);

}

