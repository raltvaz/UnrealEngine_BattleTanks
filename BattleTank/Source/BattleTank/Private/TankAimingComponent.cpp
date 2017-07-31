// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {


	//UE_LOG(LogTemp, Warning, TEXT(" %s aiming at %s from %s"), *(GetOwner()->GetName()), *(HitLocation.ToString()), *(Barrel->GetComponentLocation().ToString()));
	//UE_LOG(LogTemp, Warning, TEXT("Firing at %f"),LaunchSpeed);

	if (!Barrel) {	return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculate the OutLaunchVelocity
	if ( UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed,ESuggestProjVelocityTraceOption::DoNotTrace)) {

		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		//auto TankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %f"),*(TankName), *(AimDirection.ToString()));

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);

	}
	else {

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), Time);

	}

	//If no solution found do nothing

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {

	// Work-out difference between current barrel rotation, and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	

	Barrel->Elevate(5); //TODO remove magic number

}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {

	//this->Barrel = BarrelToSet;
	Barrel = BarrelToSet;
}
