// Fill out your copyright notice in the Description page of Project Settings.

#include "Bloque_Acero.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Establece valores predeterminados
ABloque_Acero::ABloque_Acero()
{
	// Deshabilita Tick, ya que este actor es estático y no necesita actualizarse cada frame.
	PrimaryActorTick.bCanEverTick = false;

	// Crear y asignar la malla estática
	MallaBloque_Acero = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloque_Acero"));
	SetRootComponent(MallaBloque_Acero);

	// Cargar la malla de acero
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloque_Acero(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (ObjetoMallaBloque_Acero.Succeeded())
	{
		MallaBloque_Acero->SetStaticMesh(ObjetoMallaBloque_Acero.Object);

		// Ajustar la ubicación en el suelo
		MallaBloque_Acero->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));

		// Ajustar la apariencia de acero (si es necesario, se puede hacer en el editor)
		MallaBloque_Acero->SetMaterial(0, nullptr);
	}
}

// Se ejecuta al inicio del juego o cuando el actor es generado
void ABloque_Acero::BeginPlay()
{
	Super::BeginPlay();
}
