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

        // Ajustar la escala para duplicar la altura (eje Z) sin cambiar la anchura (ejes X e Y)
        MallaBloque_Acero->SetRelativeScale3D(FVector(1.0f, 1.0f, 2.0f));

        // Ajustar la apariencia de acero (si es necesario, se puede hacer en el editor)
        MallaBloque_Acero->SetMaterial(0, nullptr);
    }
}

// Se ejecuta al inicio del juego o cuando el actor es generado
void ABloque_Acero::BeginPlay()
{
    Super::BeginPlay();

    // Ajustar el bloque al suelo
    AjustarAlSuelo();
}

// Función para ajustar el bloque al suelo usando un raycast
void ABloque_Acero::AjustarAlSuelo()
{
    // Obtener la posición actual del bloque
    FVector StartLocation = GetActorLocation();
    FVector EndLocation = StartLocation + FVector(0.0f, 0.0f, -2000.0f); // Hacia abajo

    FHitResult HitResult;
    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(this); // Ignorar el propio bloque

    // Realizar el raycast
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, QueryParams);

    if (bHit)
    {
        // Ajustar la posición del bloque al punto de impacto (agregamos un pequeño offset para evitar que quede bajo el suelo)
        FVector NewLocation = HitResult.Location + FVector(0.0f, 0.0f, 1.0f);
        SetActorLocation(NewLocation);

        // Mensaje de depuración para verificar la nueva posición
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Bloque de Acero ajustado al suelo en Z: %f"), NewLocation.Z));
        }
    }
    else
    {
        // Si no se detecta el suelo, dejar el bloque en su posición inicial
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("No se detectó el suelo para el Bloque de Acero"));
        }
    }
}