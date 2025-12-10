// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorComponent1.h"

// Sets default values for this component's properties
UMyActorComponent1::UMyActorComponent1()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}


// Called when the game starts
void UMyActorComponent1::BeginPlay()
{
    Super::BeginPlay();

    Actor_Owner->GetRootComponent()->SetMobility(EComponentMobility::Movable);// passe le component en movable pour eviter qu'il reste statique je le fais direct dans le constructor.
    if (Actor_cible0)// attention ne pas oublier cette verif sinon risque de plantage si nul ptr.
    {
        Vector_cible = Actor_cible0->GetActorLocation();
    }

}


// Called every frame
void UMyActorComponent1::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!B_Destination_Reached)
    {
        ActorMove(DeltaTime);
    }
    else
    {
        SetFocus(TurnsNumber);
    }



    // ...
}

void UMyActorComponent1::ActorMove(float deltatime)
{
    FVector New_Location;
    New_Location = FMath::VInterpConstantTo(Actor_Owner->GetActorLocation(), Vector_cible, deltatime, F_Speed);

    Actor_Owner->SetActorLocation(New_Location);

    if (Actor_Owner->GetActorLocation().Equals(Vector_cible))
    {
        UE_LOG(LogTemp, Display, TEXT("on est a destination"));
        B_Destination_Reached = true;
        SetFocus(TurnsNumber);
    }
}

void UMyActorComponent1::SetFocus(int FocusInt)
{
    TurnsNumber++;
    B_Destination_Reached = false;
    if (FocusInt == 0 && Actor_cible1)
    {
        Vector_cible = Actor_cible1->GetActorLocation();
    }
    else if (FocusInt == 1 && Actor_cible2)
    {
        Vector_cible = Actor_cible2->GetActorLocation();
    }
    else if (FocusInt == 2 && Actor_cible3)
    {
        Vector_cible = Actor_cible3->GetActorLocation();
    }
    else if (FocusInt == 3 && Actor_cible0)
    {
        Vector_cible = Actor_cible0->GetActorLocation();
        TurnsNumber = 0;
    }
}