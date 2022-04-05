// Copyright Epic Games, Inc. All Rights Reserved.

#include "principalGameMode.h"
#include "principalPlayerController.h"
#include "principalPawn.h"

AprincipalGameMode::AprincipalGameMode()
{
	// no pawn by default
	DefaultPawnClass = AprincipalPawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = AprincipalPlayerController::StaticClass();
}
