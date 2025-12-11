// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

#include "PlatformExo_JumpPad.generated.h"

UCLASS()
class PROJECT_BASECPP_API APlatformExo_JumpPad : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlatformExo_JumpPad();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* RootComp; // je déclare le root scene component qui me servira de root pour la création de mon objet

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* TriggerComp; // je déclare mon box component qui me sert de trigger

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MyMesh; // je déclare ici le mesh

	// Fonctions
	UFUNCTION()// = UFunction = fonction utilisée par unreal
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
