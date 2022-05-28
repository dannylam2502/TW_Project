// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SourceCode/MyState/BasicState.h"

/**
 * 
 */
class SOURCECODE_API CharacterIdleState : public BasicState
{
public:
	CharacterIdleState(class ABaseCharacter* _parent, StateID _stateID);
	~CharacterIdleState();

	virtual void LoadData() override;

	virtual void EnterState() override;
	virtual void ExcuseState() override;
	virtual void CheckNextState() override;
	virtual void ExitState() override;

};
