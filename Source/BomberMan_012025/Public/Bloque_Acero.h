// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque_Acero.generated.h"

class UStaticMeshComponent;

UCLASS()
class BOMBERMAN_012025_API ABloque_Acero : public AActor
{
	GENERATED_BODY()

public:
	// Establece valores predeterminados para las propiedades de este actor
	ABloque_Acero();

protected:
	// Componente de malla estática para representar el bloque de acero
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UStaticMeshComponent* MallaBloque_Acero;

	// Se ejecuta al inicio del juego o cuando el actor es generado
	virtual void BeginPlay() override;

public:
	// Deshabilitamos Tick porque el bloque no necesita actualizarse cada frame
	virtual void Tick(float DeltaTime) override {}
};
