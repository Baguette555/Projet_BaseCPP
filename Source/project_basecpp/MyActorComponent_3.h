// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent_3.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECT_BASECPP_API UMyActorComponent_3 : public UActorComponent
{
    GENERATED_BODY()

public:

    // functions
    UMyActorComponent_3();
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    bool Getter_My_Bool();
    void Setter_My_Bool(bool B_Value);


protected:
    // Called when the game starts
    virtual void BeginPlay() override;


private:
    // variables
    bool My_Bool = false;
    AActor* Actor_Owner = GetOwner();


    // Functions
    void Move_Actor(bool Actor_move);

};