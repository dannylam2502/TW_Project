// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterRunState.h"
#include "SourceCode/Character/BaseCharacter.h"
#include "SourceCode/MySystems/InputController.h"
#include "SourceCode/MySystems/GlobalInfo.h"

#include "SourceCode/MyState/BasicState.h"
#include "SourceCode/MyState/CharacterIdleState.h"
#include "SourceCode/MyState/CharacterWalkState.h"

CharacterRunState::CharacterRunState(ABaseCharacter* _parent, StateID _stateID)
{
	parent = _parent;
	stateID = _stateID;
}

CharacterRunState::~CharacterRunState()
{
}

void CharacterRunState::LoadData()
{

}

void CharacterRunState::EnterState()
{
	parent->maxWalkSpeed = 400.f;
}

void CharacterRunState::ExcuseState()
{
	AGlobalInfo::MoveForward(parent);
	AGlobalInfo::MoveRight(parent);
	AGlobalInfo::LookRight(parent);
	AGlobalInfo::LookUp(parent);
}

void CharacterRunState::CheckNextState()
{
	if (!parent->inputController->bSprint)
	{
		parent->ChangeState(parent->walkState);
	}
	else if (parent->inputController->fVertical == 0.f
		&& parent->inputController->fHorizontal == 0.f)
	{
		parent->ChangeState(parent->idleState);
	}
}

void CharacterRunState::ExitState()
{

}