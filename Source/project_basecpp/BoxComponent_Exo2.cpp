// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxComponent_Exo2.h"

UBoxComponent_Exo2::UBoxComponent_Exo2()// le construtor n'est pas la d'office il faut le rajouter 
{
    PrimaryComponentTick.bCanEverTick = true;// la je rajoute le tick

    //
}

void UBoxComponent_Exo2::BeginPlay()
{
    Super::BeginPlay();

    OnComponentBeginOverlap.AddDynamic(this, &UBoxComponent_Exo2::OnOverlapBegin); //& devant la fonction permet de recuperer correctement l'adresse de la fonction (pointeur de fonction)
    OnComponentEndOverlap.AddDynamic(this, &UBoxComponent_Exo2::OnOverlapEnd);
    if (Actor_To_Control)
    {
        MyActorComponent = Actor_To_Control->FindComponentByClass<UMyActorComponent_3>();
    }
}


void UBoxComponent_Exo2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


//begin overlap
void UBoxComponent_Exo2::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor->ActorHasTag("Player"))
    {
        if (MyActorComponent)
        {
            MyActorComponent->Setter_My_Bool(true);
        }
    }
}

//end overlap
void UBoxComponent_Exo2::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor->ActorHasTag("Player"))
    {
        if (MyActorComponent)
        {
            MyActorComponent->Setter_My_Bool(false);
        }
    }
}