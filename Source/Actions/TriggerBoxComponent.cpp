// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerBoxComponent.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MoverInterface.h"

// Sets default values for this component's properties
UTriggerBoxComponent::UTriggerBoxComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTriggerBoxComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}
// Called every frame
void UTriggerBoxComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

		TArray < AActor* >OverlappingActors;

		GetOverlappingActors(OverlappingActors);

		for (AActor* Actor : OverlappingActors) {
			if (Actor->ActorHasTag(DoorTag) && !Actor->ActorHasTag("Held"))
			{
				UPrimitiveComponent* ActorRoot = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
				if (ActorRoot) {
					ActorRoot->SetSimulatePhysics(false);
				}
				Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
				//Actor->Destroy();
				MoverComponent->ShouldItMove(true);
				//QuitGame();	
			}
			else
			{
				MoverComponent->ShouldItMove(false);
			}
		}	
}

void UTriggerBoxComponent::SetTheMover(TScriptInterface<IMoverInterface> Mover) {

	MoverComponent = Mover;
}
void UTriggerBoxComponent::QuitGame() 
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(),EQuitPreference::Quit, false);
}
