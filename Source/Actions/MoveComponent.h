// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoverInterface.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONS_API UMoveComponent : public UActorComponent, public IMoverInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveComponent();

	// Function to tell the mover whether it should be moving or not
	virtual void ShouldItMove(bool ShouldMove) override;
	// Function to actually move the object
	virtual void Move(float DeltaTime) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	FVector DefaultLocation;

	UPROPERTY(EditAnywhere)
	FVector DistanceToMove;

	float Speed;

	float Time=6;

private:
	// Whether the door should be moving
	bool ShouldTheComponentMove;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	// All movers must implement these functions
	

	
	
};
