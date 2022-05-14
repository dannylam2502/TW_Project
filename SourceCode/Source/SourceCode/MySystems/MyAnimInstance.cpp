// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "SourceCode/Character/MyPlayer.h"
#include "EngineUtils.h"

UMyAnimInstance::UMyAnimInstance() :
	canSprint (false),
	player (NULL)
{

}

void UMyAnimInstance::NativeUpdateAnimation(float deltaTime)
{
	Super::NativeUpdateAnimation(deltaTime);

	for (TActorIterator<AMyPlayer> Player(GetWorld()); Player; ++Player)
	{
		player = *Player;
		canSprint = player->canSprint;
		speed = player->GetVelocity().Size();

	}

}