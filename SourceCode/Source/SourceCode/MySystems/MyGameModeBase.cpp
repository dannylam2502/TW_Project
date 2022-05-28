// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "SourceCode/Character/BaseCharacter.h"
#include "SourceCode/Character/MyPlayer.h"
#include "UObject/ConstructorHelpers.h"

AMyGameModeBase::AMyGameModeBase()
{
	static ConstructorHelpers::FClassFinder<AMyPlayer> player(TEXT("/Script/SourceCode.MyPlayer"));
	if (player.Class != NULL)
	{
		this->DefaultPawnClass = player.Class;

	}

}