// Copyright Epic Games, Inc. All Rights Reserved.

#include "TDS53GameMode.h"
#include "TDS53PlayerController.h"
#include "TDS53Character.h"
#include "UObject/ConstructorHelpers.h"

ATDS53GameMode::ATDS53GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATDS53PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprint/Character/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/Blueprint/Character/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}