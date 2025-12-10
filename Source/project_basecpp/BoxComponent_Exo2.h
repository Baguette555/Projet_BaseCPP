// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MyActorComponent_3.h"
#include "BoxComponent_Exo2.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))// me permet de l'appliquer sur un acteur
class PROJECT_BASECPP_API UBoxComponent_Exo2 : public UBoxComponent
{
    GENERATED_BODY()
    UBoxComponent_Exo2();

public:

    // public fonctions
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:

    virtual void BeginPlay() override;


private:

    UPROPERTY(EditAnywhere, Category = "configuration")
    AActor* Actor_To_Control;// selection acteur avec qui on va interragir
    UMyActorComponent_3* MyActorComponent;// attention ne pas oublier de le mettre dans l'include pour y avoir accés.



    /** called when something enters the box component */
    UFUNCTION()// = UFunction = fonction utilisée par unreal
        void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    /** called when something leaves the box component */
    UFUNCTION()
    void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};