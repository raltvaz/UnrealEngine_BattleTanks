// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	//if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
}

void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

/*	if (!ControlledTank) {

		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("AIController possesing: %s"), *(ControlledTank->GetName()));
	}*/

	if (!PlayerTank) {

		UE_LOG(LogTemp, Warning, TEXT("AIController not found Player Tank"));
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *(PlayerTank->GetName()));
	}

	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto Tank = GetControlledTank();
	FVector HitLocation;

	Tank->AimAt(HitLocation);

	if (GetPlayerTank()) {

		//Move towards the player

		//Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire at player
	}

}

