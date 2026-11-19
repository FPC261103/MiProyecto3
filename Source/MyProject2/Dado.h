// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Dado.generated.h"

class AMyProject2BlockGrid;

UCLASS()
class MYPROJECT2_API ADado : public AActor
{
	GENERATED_BODY()

public:
	/** Dummy root component */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* DummyRoot;

	/** StaticMesh component for the clickable block */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* BlockMesh;

	ADado();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dado")
		int32 ladoDado;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dado")
		int32 Value;

	// Puntero para saber quién es su Grid y avisarle para sumar puntos
	UPROPERTY()
		AMyProject2BlockGrid* OwningGrid;

	// --- NUEVAS VARIABLES Y FUNCIONES AÑADIDAS ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dado")
		bool bIsJumping;

	// Estas dos no necesitan UPROPERTY porque son de uso interno de la animación
	FVector StartLocation;
	float JumpTimer;

	UFUNCTION(BlueprintCallable, CallInEditor)
		void ladoCara();

	UFUNCTION()
		void BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked);

	UFUNCTION(BlueprintCallable, Category = "Dado")
		void ApplyVerticalImpulse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void NextFace();
};