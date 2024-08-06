// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabLocation.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"




// Sets default values for this component's properties
UGrabLocation::UGrabLocation()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabLocation::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UGrabLocation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (GetPhysicsHandle()&& GetPhysicsHandle()->GetGrabbedComponent()) {
	
	
		GetPhysicsHandle()->SetTargetLocationAndRotation(GetComponentLocation()+GetForwardVector()*200, GetComponentRotation());
	}	
}
void UGrabLocation::Grab() {

	UPhysicsHandleComponent* PhysicsHandleComp = GetPhysicsHandle();

	if (PhysicsHandleComp) {

		FHitResult OutHitResult;

		bool HasHit = PerformSphereTrace(OutHitResult);

		if (HasHit) {
			AActor* HitActor = OutHitResult.GetActor();
			UPrimitiveComponent* HitComponent = OutHitResult.GetComponent();
			//DrawDebugSphere(GetWorld(), OutHitResult.Location, 10, 10, FColor::Red, false, 5);
			//DrawDebugSphere(GetWorld(), OutHitResult.ImpactPoint, 10, 10, FColor::Blue, false, 5);

			HitComponent->WakeAllRigidBodies();
			HitComponent->SetSimulatePhysics(true);
			HitActor->Tags.Add("Held");
			HitActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

			PhysicsHandleComp->GrabComponentAtLocationWithRotation(OutHitResult.GetComponent(),
				NAME_None, 
				OutHitResult.ImpactPoint, GetComponentRotation());
		}	
	}	
}

void UGrabLocation::Release() {
	if (GetPhysicsHandle() && GetPhysicsHandle()->GetGrabbedComponent()) {

		GetPhysicsHandle()->GetGrabbedComponent()->GetOwner()->Tags.Remove("Held");
		GetPhysicsHandle()->GetGrabbedComponent()->WakeAllRigidBodies();

		GetPhysicsHandle()->ReleaseComponent();
	;
	}
}

UPhysicsHandleComponent* UGrabLocation::GetPhysicsHandle() const {

	return GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

};

bool UGrabLocation::PerformSphereTrace(FHitResult& OutHitResult)const {

	FVector StartLoc = GetComponentLocation();
	FVector EndLoc = StartLoc + GetForwardVector() * TraceDistance;

	//DrawDebugLine(GetWorld(), StartLoc, EndLoc, FColor::Red);
	
	FCollisionShape Sphere = FCollisionShape::MakeSphere(50);
    return GetWorld()->SweepSingleByChannel(
		OutHitResult, StartLoc, EndLoc,
		FQuat::Identity, ECC_GameTraceChannel2, Sphere);
}
