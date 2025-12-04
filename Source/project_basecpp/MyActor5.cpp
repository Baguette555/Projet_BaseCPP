// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor5.h"

// Sets default values
AMyActor5::AMyActor5()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


// Called when the game starts or when spawned
void AMyActor5::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor5::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Rotation_Calcul(Rotation_Velocity, Rotator_vitesse);
}


void AMyActor5::Rotation_Calcul(float Speed_Rotation, FRotator Axe_Rotation)
{
	rotator_To_Apply = Axe_Rotation * Speed_Rotation;
	UE_LOG(LogTemp, Display, TEXT("affichage frotator %s"), *rotator_To_Apply.ToCompactString());

	AddActorLocalRotation(rotator_To_Apply);
}

