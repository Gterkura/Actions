// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();

	DefaultLocation = GetOwner()->GetActorLocation();

	// ...
	
}


// Called every frame
void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...


	FVector TargetLocation = ShouldTheComponentMove? DefaultLocation + DistanceToMove : DefaultLocation;

	AActor* Owner = GetOwner();
	if (!Owner) return;
	FVector CurrentLocation = GetOwner()->GetActorLocation();

	Speed = DistanceToMove.Length() / Time;

	Owner->SetActorLocation(FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed));
	
}

void UMoveComponent::ShouldItMove(bool ShouldMove) {

	ShouldTheComponentMove = ShouldMove;

}


