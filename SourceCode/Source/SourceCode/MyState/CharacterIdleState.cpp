// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterIdleState.h"
#include "GameFramework/Controller.h"
#include "SourceCode/Character/BaseCharacter.h"
#include "SourceCode/MySystems/InputController.h"
#include "SourceCode/MySystems/GlobalInfo.h"

#include "SourceCode/MyState/BasicState.h"
#include "SourceCode/MyState/CharacterWalkState.h"
#include "SourceCode/MyState/CharacterRunState.h"

CharacterIdleState::CharacterIdleState(ABaseCharacter* _parent, StateID _stateID)
{
	parent = _parent;
	stateID = _stateID;
}

CharacterIdleState::~CharacterIdleState()
{
}

void CharacterIdleState::LoadData()
{

}

void CharacterIdleState::EnterState()
{

}

void CharacterIdleState::ExcuseState()
{
	AGlobalInfo::LookRight(parent);
	AGlobalInfo::LookUp(parent);
}

void CharacterIdleState::CheckNextState()
{
	if (parent->inputController->fVertical != 0.f
	 || parent->inputController->fHorizontal != 0.f)
	{
		if (parent->inputController->bSprint)
		{
			parent->ChangeState(parent->runState);
		}
		else
		{
			parent->ChangeState(parent->walkState);
		}
	}

}

void CharacterIdleState::ExitState()
{

}