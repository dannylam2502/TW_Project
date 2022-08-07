// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterWalkState.h"
#include "SourceCode/Character/BaseCharacter.h"
#include "SourceCode/MySystems/InputController.h"
#include "SourceCode/MySystems/GlobalInfo.h"

#include "SourceCode/MyState/BasicState.h"
#include "SourceCode/MyState/CharacterIdleState.h"
#include "SourceCode/MyState/CharacterRunState.h"

CharacterWalkState::CharacterWalkState(ABaseCharacter* _parent, StateID _stateID)
{
	parent = _parent;
	stateID = _stateID;
}

CharacterWalkState::~CharacterWalkState()
{
}

void CharacterWalkState::LoadData()
{

}

void CharacterWalkState::EnterState()
{
	parent->maxWalkSpeed = 150.f;
}

void CharacterWalkState::ExcuseState()
{
	AGlobalInfo::MoveForward(parent);
	AGlobalInfo::MoveRight(parent);
	AGlobalInfo::LookRight(parent);
	AGlobalInfo::LookUp(parent);
}

void CharacterWalkState::CheckNextState()
{
	if (parent->inputController->bSprint)
	{
		parent->ChangeState(parent->runState);
	}
	else if (parent->inputController->fVertical == 0.f
		  && parent->inputController->fHorizontal == 0.f)
	{
		parent->ChangeState(parent->idleState);
	}
}

void CharacterWalkState::ExitState()
{

}
