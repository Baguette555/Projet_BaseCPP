// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "BoxComponent_Exo1.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent)) //Permet de l'appliquer sur un acteur
class PROJECT_BASECPP_API UBoxComponent_Exo1 : public UBoxComponent
{
	GENERATED_BODY()

	// public: //appel du constructor qui n'est pas là d'office, je le rajoute donc
	UBoxComponent_Exo1();

public:
	UPROPERTY(EditAnywhere, Category = "Trajectoire|Speed")
	float F_Speed = 50.0f;

	FVector vector_cible = FVector(0.0f, 0.0f, 1.0f);
	AActor* Actor_Owner = GetOwner();
	bool isOnIt = false;


	// public fonctions
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ActorMove(float deltatime);


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
