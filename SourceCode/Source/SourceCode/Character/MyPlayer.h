// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SourceCode/Character/BaseCharacter.h"
#include "MyPlayer.generated.h"

/**
 * 
 */
UCLASS()
class SOURCECODE_API AMyPlayer : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AMyPlayer();

	virtual void InitCharacter() override;
	virtual void MakeFSM() override;
	virtual void ChangeState(class BasicState* state) override;

	virtual void Tick(float DeltaTime) override;

	/*UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* meshChar;*/

protected:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* input) override;

	void OnMoveVertical(float value) override;
	void OnMoveHorizontal(float value) override;
	void OnLookMouseZ(float rate) override;
	void OnLookMouseY(float rate) override;

	void PressedSprint() override;
	void ReleasedSprint()override;
};
