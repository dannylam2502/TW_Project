// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM()
enum StateID
{
	None,
	Idle,
	Walk,
	Run
};

/**
 * 
 */
class SOURCECODE_API BasicState
{
public:
	BasicState();
	~BasicState();

	float runStateTime;
	StateID stateID;

	virtual void LoadData();

	class ABaseCharacter* parent;

	virtual void EnterState();
	virtual void ExcuseState();
	virtual void CheckNextState();
	virtual void ExitState();

};
