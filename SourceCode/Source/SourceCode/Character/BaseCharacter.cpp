// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter() :
	bPause(false),
	turnRateGamepad (50.f),
	maxWalkSpeed (250.f),
	springArm (NULL),
	camera (NULL),
	inputController (NULL),
	currentState(NULL),
	idleState(NULL),
	walkState(NULL),
	runState(NULL)
{
 	
}

void ABaseCharacter::InitCharacter()
{
}

void ABaseCharacter::MakeFSM()
{
}

void ABaseCharacter::ChangeState(BasicState* state)
{
}

void ABaseCharacter::OnMoveVertical(float value)
{
}

void ABaseCharacter::OnMoveHorizontal(float value)
{
}

void ABaseCharacter::OnLookMouseZ(float rate)
{
}

void ABaseCharacter::OnLookMouseY(float rate)
{
}

void ABaseCharacter::PressedSprint()
{
}

void ABaseCharacter::ReleasedSprint()
{
}


