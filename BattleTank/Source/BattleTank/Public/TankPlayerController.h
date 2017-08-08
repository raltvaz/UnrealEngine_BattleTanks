// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:

	UFUNCTION(BlueprintCallable, Category = "Setup")
	ATank* GetControlledTank() const;

private:

	bool GetSightRayHitLocation(OUT FVector& HitLocation) const;

	void AimTowardsCrossHair();

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXPosition = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYPosition = 0.3333;

};
