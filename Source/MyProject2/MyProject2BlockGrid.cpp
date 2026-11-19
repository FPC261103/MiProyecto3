// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProject2BlockGrid.h"
#include "MyProject2Block.h"
#include "Dado.h" 
#include "Components/TextRenderComponent.h"
#include "Coin.h" 
#include "Engine/World.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"

AMyProject2BlockGrid::AMyProject2BlockGrid()
{
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreText0"));

	
	ScoreText->SetRelativeLocation(FVector(-400.f, 0.f, -200.f));

	// Rotación para que mire a la cámara
	ScoreText->SetRelativeRotation(FRotator(90.f, 180.f, 0.f));
	ScoreText->SetWorldSize(80.f);
	ScoreText->SetTextRenderColor(FColor::Cyan);
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Puntuacion: {0}"), FText::AsNumber(0)));
	ScoreText->SetupAttachment(DummyRoot);

	Size = 3;
	BlockSpacing = 300.f; 
	BlockSize = 1.8f;

	Score = 0;
	Favoritos = 0;
}

void AMyProject2BlockGrid::BeginPlay()
{
	Super::BeginPlay();

	if (Rows <= 0) { Rows = 3; }
	if (Columns <= 0) { Columns = 4; }

	const int32 NumBlocks = Rows * Columns;

	// Bucle que crea los dados
	for (int32 BlockIndex = 0; BlockIndex < NumBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex / Columns) * BlockSpacing;
		const float YOffset = (BlockIndex % Columns) * BlockSpacing;

		const FVector BlockLocation = FVector(XOffset, YOffset, 50.f) + GetActorLocation();

		ADado* NewDado = GetWorld()->SpawnActor<ADado>(BlockLocation, FRotator(0, 0, 0));

		if (NewDado != nullptr)
		{
			NewDado->Value = FMath::RandRange(1, 6);
			NewDado->ladoCara();
			NewDado->SetActorLocation(BlockLocation);
			NewDado->StartLocation = BlockLocation;

			NewDado->SetActorScale3D(FVector(BlockSize, BlockSize, BlockSize));
			NewDado->OwningGrid = this;

			ListaDados.Add(NewDado);
		}
	}

	
	ACoin* NuevaMoneda = GetWorld()->SpawnActor<ACoin>(
		GetActorLocation() + FVector(-300.f, 0.f, 0.f), FRotator::ZeroRotator);

	if (NuevaMoneda)
	{
		NuevaMoneda->OwningGrid = this;
		NuevaMoneda->Puntos = points;
	}
}

void AMyProject2BlockGrid::AddScore(int32 PuntosASumar)
{
	Score = Score + PuntosASumar;

	// Actualizamos el texto en pantalla
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Puntuacion: {0}"), FText::AsNumber(Score)));
}

#undef LOCTEXT_NAMESPACE