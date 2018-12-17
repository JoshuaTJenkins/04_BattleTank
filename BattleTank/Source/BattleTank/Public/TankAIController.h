// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank; // forward declaration

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ATank * GetControlledTank() const;	

	ATank* GetPlayerTank() const;	

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	
};
