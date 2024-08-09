// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
//#include "MoveComponent.h"
#include "TriggerBoxComponent.generated.h"

//class IMoverInterface;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ACTIONS_API UTriggerBoxComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTriggerBoxComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void SetTheMover(TScriptInterface<IMoverInterface> Mover);

private:
	UPROPERTY(EditAnywhere)
		FName DoorTag;

	AActor* GetActorThatHasTag()const;

	TScriptInterface<IMoverInterface> MoverComponent;

public:
	UFUNCTION(BlueprintCallable, Category = "Game")
		void QuitGame();

	// Called every frame
virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
};
