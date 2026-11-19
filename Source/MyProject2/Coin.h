// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstance.h" // Necesario para UMaterialInstance
#include "Coin.generated.h"  


UCLASS()
class MYPROJECT2_API ACoin : public AActor
{
    GENERATED_BODY()

public:
    ACoin();

    /** Indica si el lado visible es CARA (true) o SELLO (false). */
    UPROPERTY(EditAnywhere, Category = "Moneda")      // PISTA: especificador que permite EDITAR el valor en el panel Details.
        bool bEsCara = true;

    /** Número de veces que la moneda ha sido lanzada. */
    UPROPERTY(EditAnywhere, Category = "Moneda")
        int32 Lanzamientos = 0;                      // PISTA: tipo entero de 32 bits que utiliza Unreal.

    UPROPERTY(EditAnywhere, Category = "Moneda")
        int32 Puntos = 0;                      // PISTA: tipo entero de 32 bits que utiliza Unreal.

        /** Si es verdadero, la moneda elige un lado al azar al iniciar la partida. */
    UPROPERTY(EditAnywhere, Category = "Moneda")
        bool bLadoAleatorio = true;

    /** Componente raíz de la moneda. */
    UPROPERTY(VisibleDefaultsOnly, Category = "Moneda")
        class USceneComponent* DummyRoot;

    /** Malla visible de la moneda. */
    UPROPERTY(VisibleDefaultsOnly, Category = "Moneda")
        class UStaticMeshComponent* CoinMesh;

    /** Grilla dueña de la moneda. */
    UPROPERTY()
        class AMyProject2BlockGrid* OwningGrid;

    UFUNCTION()
        void CoinClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked);

    /** Aplica el material correspondiente al lado visible. */
    void MostrarLado();

protected:
    /** Declaración de BeginPlay (Añadido para solucionar los errores) */
    virtual void BeginPlay() override;

    /** Material para el lado CARA (naranja). */
    UPROPERTY()
        class UMaterialInstance* MatCara;

    /** Material para el lado SELLO (azul). */
    UPROPERTY()
        class UMaterialInstance* MatSello;
};