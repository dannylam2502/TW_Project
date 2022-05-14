// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SOURCECODE_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

private:
	UMyAnimInstance();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "speed")
		float speed = 0.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "canSprint")
		bool canSprint;

	class AMyPlayer* player;


public:
	virtual void NativeUpdateAnimation(float deltaTime) override;

};
