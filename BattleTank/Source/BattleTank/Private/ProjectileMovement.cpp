// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileMovement.h"


// Sets default values
AProjectileMovement::AProjectileMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectileMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectileMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

