// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorComponent_3.h"

// Sets default values for this component's properties
UMyActorComponent_3::UMyActorComponent_3()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}


// Called when the game starts
void UMyActorComponent_3::BeginPlay()
{
    Super::BeginPlay();
    Actor_Owner->GetRootComponent()->SetMobility(EComponentMobility::Movable);
    // ...

}

// Called every frame
void UMyActorComponent_3::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    Move_Actor(My_Bool);

}





//Functions

void UMyActorComponent_3::Move_Actor(bool Actor_move)
{
    if (Actor_Owner && Actor_move)
    {
        Actor_Owner->AddActorLocalOffset(FVector(0.0f, 0.0f, 4.0f));
    }
}

bool UMyActorComponent_3::Getter_My_Bool()
{
    return My_Bool;
}

void UMyActorComponent_3::Setter_My_Bool(bool B_Value)
{
    My_Bool = B_Value;
}