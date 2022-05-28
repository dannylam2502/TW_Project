// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SourceCode/MyState/BasicState.h"

/**
 * 
 */
class SOURCECODE_API CharacterWalkState : public BasicState
{
public:
	CharacterWalkState(ABaseCharacter* _parent, StateID _stateID);
	~CharacterWalkState();

	virtual void LoadData() override;

	virtual void EnterState() override;
	virtual void ExcuseState() override;
	virtual void CheckNextState() override;
	virtual void ExitState() override;

};
