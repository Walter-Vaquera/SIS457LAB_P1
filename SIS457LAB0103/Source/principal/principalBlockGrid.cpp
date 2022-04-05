// Copyright Epic Games, Inc. All Rights Reserved.

#include "principalBlockGrid.h"
#include "principalBlock.h"
#include "Components/TextRenderComponent.h"
#include "Engine/World.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"

AprincipalBlockGrid::AprincipalBlockGrid()
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreText0"));
	ScoreText->SetRelativeLocation(FVector(200.f,0.f,0.f));
	ScoreText->SetRelativeRotation(FRotator(90.f,0.f,0.f));
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Buenas tardes inge, me llamo Walter Benjamín Vaquera Reyes y estoy cursando el tercer semestre de la carrera 'ingeniería en tecnologías de la informacíon y seguridad'. nací el 17 de junio del 2003 en Sucre, fuí criado por una familia cariñosa de cuatro integrantes, actualmente vivo con mi madre y mi hermano. Comencé a estudiar en el kinder Vaca Guzman a una edad de 3 años (creo), lo único que recuerdo es haberme mordido la lengua y ser mordido en la mano por un perro, aunque según mi madre, aveces era castigado por quitarles el cuaderno a mis compañeros y hacerles las tareas que no entendian. Más adelante ingresé al colegio Don Bosco, el mismo lugar donde estudió mi hermano. Al principio alcancé buenas notas gracias al apoyo de mi madre, no hice muchas amistades y me daba miedo lo grande que era el colegio en comparación a mi kinder; años más tarde conocí a varios amigos, siempre jugábamos y reíamos mucho, fue desde ahí que empecé a relacionarme más con mis compañeros, descubrir nuevos intereses y nuevos problemas. Los últimos años de mi vida colegial participé en varias actividades y viajes, conocí muchas personas importantes para mí, desarrollé algo de ansiedad, bajaron mis notas, tube algunas relaciones románticas y todas salieron mal, muchas cosas cambiaron y continuan cambiando en mi entorno, pero a pesar del distanciamiento social y el cambio de etapa entre el colegio y la universidad, siempre he contado con la compañía de mis amigos y mi familia.: {0}"), FText::AsNumber(0)));
	ScoreText->SetupAttachment(DummyRoot);

	// Set defaults
	Size = 3;
	BlockSpacing = 300.f;
}


void AprincipalBlockGrid::BeginPlay()
{
	Super::BeginPlay();

	// Number of blocks
	const int32 NumBlocks = Size * Size;

	// Loop to spawn each block
	for(int32 BlockIndex=0; BlockIndex<NumBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex/Size) * BlockSpacing; // Divide by dimension
		const float YOffset = (BlockIndex%Size) * BlockSpacing; // Modulo gives remainder

		// Make position vector, offset from Grid location
		const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

		// Spawn a block
		AprincipalBlock* NewBlock = GetWorld()->SpawnActor<AprincipalBlock>(BlockLocation, FRotator(0,0,0));

		// Tell the block about its owner
		if (NewBlock != nullptr)
		{
			NewBlock->OwningGrid = this;
		}
	}
}


void AprincipalBlockGrid::AddScore()
{
	// Increment score
	Score++;

	// Update text
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(Score)));
}

#undef LOCTEXT_NAMESPACE
