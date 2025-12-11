// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "PlatformExo_TrigBox1.generated.h"

/**
*
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)) //Permet de l'appliquer sur un acteur
class PROJECT_BASECPP_API UPlatformExo_TrigBox1 : public UBoxComponent
{
	GENERATED_BODY()

	// public: //appel du constructor qui n'est pas là d'office, je le rajoute donc
	UPlatformExo_TrigBox1();

public:
	UPROPERTY(EditAnywhere, Category = "Checkpoint")
	AActor* Checkpoint_Cible;

	AActor* SelfActor = GetOwner();


	// public fonctions
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


protected:

	virtual void BeginPlay() override;


private:

	/** called when something enters the box component */
	UFUNCTION()// = UFunction = fonction utilisée par unreal
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves the box component */
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};