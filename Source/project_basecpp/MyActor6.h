// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor6.generated.h"

UCLASS()
class PROJECT_BASECPP_API AMyActor6 : public AActor
{
	GENERATED_BODY()

//variables	
public:	

	UPROPERTY(EditAnywhere, Category = "Platform Parameters")
	float Distance_to_go = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Platform Parameters")
	FVector Direction_vector = FVector(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = "Platform Parameters")
	float platform_speed = 0.0f;

	FVector Start_point = FVector(0.0f, 0.0f, 0.0f);
	float My_Distance = 0.0;
	bool B_Fall_Back = false;

//fonctions 	
public:
	// Sets default values for this actor's properties
	AMyActor6();

	void distance_resolution();
	void Actor_Move();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
