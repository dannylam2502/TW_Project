// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GlobalInfo.generated.h"

UCLASS()
class SOURCECODE_API AGlobalInfo : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGlobalInfo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	static FVector GetUnitAxis(class ABaseCharacter* parent, EAxis::Type eAxis);

	static void MoveForward(class ABaseCharacter* parent);
	static void MoveRight(class ABaseCharacter* parent);
	static void LookUp(class ABaseCharacter* parent);
	static void LookRight(class ABaseCharacter* parent);

};
