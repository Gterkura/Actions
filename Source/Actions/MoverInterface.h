// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MoverInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMoverInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONS_API IMoverInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// All movers must implement these functions
	// Function to tell the mover whether it should be moving or not
	virtual void ShouldItMove(bool ShouldMove) = 0;
	// Function to actually move the object
	virtual void Move(float DeltaTime) = 0;
};
