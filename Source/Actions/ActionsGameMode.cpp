// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActionsGameMode.h"
#include "ActionsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AActionsGameMode::AActionsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
