// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicState.h"
#include "SourceCode/Character/BaseCharacter.h"

BasicState::BasicState() :
	runStateTime (0),
	parent (NULL)
{
	stateID = StateID::None;
}

BasicState::~BasicState()
{
}

void BasicState::LoadData() {}

void BasicState::EnterState() {}

void BasicState::ExcuseState() {}

void BasicState::CheckNextState() {}

void BasicState::ExitState() {}
