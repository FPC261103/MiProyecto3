// Fill out your copyright notice in the Description page of Project Settings.

#include "Dado.h"
#include "MyProject2BlockGrid.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "InputCoreTypes.h"
#include "UObject/ConstructorHelpers.h"

ADado::ADado()
{
	PrimaryActorTick.bCanEverTick = true;

	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PlaneMesh(TEXT("StaticMesh'/Game/Puzzle/Meshes/dice.dice'"));
	BlockMesh->SetStaticMesh(PlaneMesh.Get());
	BlockMesh->SetupAttachment(DummyRoot);

	BlockMesh->SetSimulatePhysics(false);
	BlockMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BlockMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	BlockMesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	BlockMesh->OnClicked.AddDynamic(this, &ADado::BlockClicked);

	bIsJumping = false;
	JumpTimer = 0.f;
}

void ADado::BeginPlay()
{
	Super::BeginPlay();

	if (Value == 0)
	{
		Value = FMath::RandRange(1, 6);
	}

	ladoCara();
	StartLocation = GetActorLocation();
}

void ADado::BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked)
{
	if (OwningGrid != nullptr)
	{
		// 1. Establecemos el Número Favorito (solo la primera vez)
		if (OwningGrid->Favoritos == 0)
		{
			OwningGrid->Favoritos = this->Value;
			UE_LOG(LogTemp, Warning, TEXT("¡Número Favorito establecido en: %d!"), OwningGrid->Favoritos);
		}

		int32 ValorBuscado = this->Value;
		int32 DadosEncontrados = 0;

		// 2. Recorremos la lista para hacer saltar a TODOS los del mismo número
		for (ADado* dadoEnLista : OwningGrid->ListaDados)
		{
			if (dadoEnLista != nullptr && dadoEnLista->Value == ValorBuscado)
			{
				// Hacemos que salte
				dadoEnLista->ApplyVerticalImpulse();
				DadosEncontrados++;

				// 3. Solo si el número es el Favorito, lo registramos y sumamos
				if (ValorBuscado == OwningGrid->Favoritos)
				{
					if (!OwningGrid->ListaFavoritos.Contains(dadoEnLista))
					{
						OwningGrid->ListaFavoritos.Add(dadoEnLista);
					}
				}
			}
		}

		// 4. Sumar puntos solo si es el Favorito
		if (ValorBuscado == OwningGrid->Favoritos && DadosEncontrados > 0)
		{
			int32 PuntosASumar = ValorBuscado * DadosEncontrados;
			OwningGrid->AddScore(PuntosASumar);

			UE_LOG(LogTemp, Warning, TEXT("¡Acertaste el favorito %d! Encontraste %d dados. Puntos: %d. Total: %d"),
				ValorBuscado, DadosEncontrados, PuntosASumar, OwningGrid->Score);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Tocaste un %d. Saltaron %d dados, pero no sumas puntos porque el Favorito es %d."),
				ValorBuscado, DadosEncontrados, OwningGrid->Favoritos);
		}
	}
}

void ADado::ApplyVerticalImpulse()
{
	if (bIsJumping) return;
	bIsJumping = true;
	JumpTimer = 0.f;
}

void ADado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsJumping)
	{
		JumpTimer += DeltaTime * 3.0f;
		float AlturaSalto = FMath::Sin(JumpTimer * PI) * 150.0f;

		SetActorLocation(StartLocation + FVector(0.f, 0.f, AlturaSalto));

		FRotator RotacionActual = BlockMesh->GetRelativeRotation();
		RotacionActual.Pitch = 0.f;
		RotacionActual.Yaw = 0.f;
		RotacionActual.Roll += DeltaTime * 720.f;
		BlockMesh->SetRelativeRotation(RotacionActual);

		if (JumpTimer >= 1.0f)
		{
			JumpTimer = 0.f;
			bIsJumping = false;

			SetActorLocation(StartLocation);

			Value = FMath::RandRange(1, 6);
			ladoCara();
		}
	}
}

void ADado::ladoCara()
{
	BlockMesh->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));

	switch (Value)
	{
	case 1: BlockMesh->AddRelativeRotation(FRotator(-90, 0, 0)); break;
	case 2: BlockMesh->AddRelativeRotation(FRotator(0, 0, -90)); break;
	case 3: BlockMesh->AddRelativeRotation(FRotator(0, 0, 0)); break;
	case 4: BlockMesh->AddRelativeRotation(FRotator(0, 0, -180)); break;
	case 5: BlockMesh->AddRelativeRotation(FRotator(0, 0, 90)); break;
	case 6: BlockMesh->AddRelativeRotation(FRotator(90, 0, 0)); break;
	}
}

void ADado::NextFace()
{
}