// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class InputController;
class BasicState;
class CharacterIdleState;
class CharacterWalkState;

UCLASS()
class SOURCECODE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	virtual void InitCharacter();
	virtual void MakeFSM();
	virtual void ChangeState(class BasicState* state);

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* camera;

	class InputController* inputController;

	float turnRateGamepad;
	float maxWalkSpeed;

	class BasicState* currentState;
	class CharacterIdleState* idleState;
	class CharacterWalkState* walkState;
	class CharacterRunState* runState;

	bool bPause = false;

protected:
	virtual void OnMoveVertical(float value);
	virtual void OnMoveHorizontal(float value);
	virtual void OnLookMouseZ(float rate);
	virtual void OnLookMouseY(float rate);

	virtual void PressedSprint();
	virtual void ReleasedSprint();

};
