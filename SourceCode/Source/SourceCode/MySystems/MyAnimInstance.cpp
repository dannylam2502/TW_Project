// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "SourceCode/Character/BaseCharacter.h"
#include "SourceCode/Character/MyPlayer.h"
#include "EngineUtils.h"

UMyAnimInstance::UMyAnimInstance() :
	player (NULL)
{

}

void UMyAnimInstance::NativeUpdateAnimation(float deltaTime)
{
	Super::NativeUpdateAnimation(deltaTime);

	for (TActorIterator<ABaseCharacter> Player(GetWorld()); Player; ++Player)
	{
		player = *Player;
		speed = player->GetVelocity().Size();

	}

}