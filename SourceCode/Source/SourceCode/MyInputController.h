// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlayer.h"

/**
 * 
 */
class SOURCECODE_API MyInputController
{
public:
	MyInputController();
	~MyInputController();

	float moveHorizontal = 0.f;
	float moveVertical = 0.f;
	float lookHorizontal = 0.f;
	float lookVertical = 0.f;

	

};
