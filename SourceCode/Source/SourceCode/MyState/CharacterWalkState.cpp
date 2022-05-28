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
	parent->maxWalkSpeed = 250.f;
}

void CharacterWalkState::ExcuseState()
{
	if (parent->Controller != nullptr && parent->inputController->fVertical != 0.f)
	{
		parent->AddMovementInput(AGlobalInfo::GetUnitAxis(parent, EAxis::X), parent->inputController->fVertical);

		// Test Debug.
		const FString strShow = parent->inputController->fVertical > 0 ? "Move Forward" : "Move Backward";
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Blue, strShow);
		//.
	}
	
	if (parent->Controller != nullptr && parent->inputController->fHorizontal != 0.f)
	{
		parent->AddMovementInput(AGlobalInfo::GetUnitAxis(parent, EAxis::Y), parent->inputController->fHorizontal);

		// Test Debug.
		const FString strShow = parent->inputController->fHorizontal > 0 ? "Move Right" : "Move Left";
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Blue, strShow);
		//.
	}

	if (parent->Controller != nullptr && parent->inputController->fMouseZ != 0.f)
	{
		parent->AddControllerYawInput(parent->inputController->fMouseZ * parent->turnRateGamepad * parent->GetWorld()->GetDeltaSeconds());
	}

	if (parent->Controller != nullptr && parent->inputController->fMouseY != 0.f)
	{
		parent->AddControllerPitchInput(parent->inputController->fMouseY * parent->turnRateGamepad * parent->GetWorld()->GetDeltaSeconds());
	}
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