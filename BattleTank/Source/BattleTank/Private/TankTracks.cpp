// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTracks.h"

UTankTracks::UTankTracks() 
{
	PrimaryComponentTick.bCanEverTick = false;		
}

void UTankTracks::BeginPlay() 
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTracks::OnHit);
}

void UTankTracks::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//Drive the tracks
	DriveTracks();
	//Apply sideways force
	ApplySidewaysForce();
	// Reset Throttle
	CurrentThrottle = 0;
}


void UTankTracks::ApplySidewaysForce()
{
	// Calculate the slippage speed
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	// Work out required acceleration this frame to correct
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	// Calculate and apply sideways force (F = m*a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2;
	TankRoot->AddForce(CorrectionForce);
}
;

void UTankTracks::SetThrottle(float Throttle)
{	
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -2, 2);	
}
void UTankTracks::DriveTracks()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

