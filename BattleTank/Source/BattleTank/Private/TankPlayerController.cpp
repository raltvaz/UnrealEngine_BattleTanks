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
	UE_LOG(LogTemp, Warning, TEXT("TICK IS WORKING"));

}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair() {

	if (!GetControlledTank()) {
		return;
	}

	//Get world location if linetrace through crosshair
	//If it hits the landscape
		//Tll controlled tank to aim at this point
}

