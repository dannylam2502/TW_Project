// Copyright Epic Games, Inc. All Rights Reserved.


#include "SourceCodeGameModeBase.h"
#include "SourceCode/MyPlayer.h"
#include "UObject/ConstructorHelpers.h"

ASourceCodeGameModeBase::ASourceCodeGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AMyPlayer> player(TEXT("/Script/SourceCode.MyPlayer"));

	this->DefaultPawnClass = player.Class;

}