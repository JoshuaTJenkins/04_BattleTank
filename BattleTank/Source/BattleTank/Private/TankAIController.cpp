// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();		
}	

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
	// TODO Move towards Player
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO Check Radius is in cm
	// Aim towards Player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	
	AimingComponent->Fire(); // TODO limit fire rate
	
}

