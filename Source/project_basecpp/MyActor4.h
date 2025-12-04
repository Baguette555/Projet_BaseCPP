// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor4.generated.h"

UCLASS()
class PROJECT_BASECPP_API AMyActor4 : public AActor
{
	GENERATED_BODY()

	// mes fonctions
	void My_Member_Function1();
	void My_Member_Function2(int My_int1, int My_int2);
	int My_Member_Function3(int My_int1, int My_int2);

	// mes variables
	int My_Menber_Int = 1;
	bool My_Bool = true;
	
public:	
	// Sets default values for this actor's properties
	AMyActor4();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
