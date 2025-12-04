// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent1.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECT_BASECPP_API UMyActorComponent1 : public UActorComponent
{
    GENERATED_BODY()

public:

    AActor* Actor_Owner = GetOwner();// me permet de recupérer avec un pointeur l'acteur qui utilise ce component.
    int TurnsNumber = 0;

    UPROPERTY(EditAnywhere, Category = "creation_trajectoire|Cible")
    AActor* Actor_cible0; // me permet de choisir un acteur cible           // METTRE LE EDIT ANYWHERE AU DESSOUS DE TOUS
    AActor* Actor_cible1; // me permet de choisir un acteur cible
    AActor* Actor_cible2; // me permet de choisir un acteur cible
    AActor* Actor_cible3; // me permet de choisir un acteur cible

    UPROPERTY(EditAnywhere, Category = "creation_trajectoire|Speed")
    float F_Speed = 50.0f;

    bool B_Destination_Reached = false;
    FVector Vector_cible = FVector(0.0f, 0.0f, 0.0f);

public:
    // Sets default values for this component's properties
    UMyActorComponent1();
    void ActorMove(float deltatime);
    void SetFocus(int FocusInt);

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
