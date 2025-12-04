// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor5.generated.h"

UCLASS()
class PROJECT_BASECPP_API AMyActor5 : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "My_parameter")
	float Rotation_Velocity = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "My_parameter")//variable visible uniquement
		FRotator Rotator_vitesse = FRotator(0.0f, 1.0f, 0.0f); // attention Frotator fonctionne en Pitch (x)/Yaw (z)/Roll (y) donc ici x = 0, z = 1, y=0

	UPROPERTY(VisibleAnywhere, Category = "My_parameter")
	FRotator rotator_To_Apply;
	
public:	
	// Sets default values for this actor's properties
	AMyActor5();

	void Rotation_Calcul(float Speed_Rotation, FRotator Axe_Rotation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
