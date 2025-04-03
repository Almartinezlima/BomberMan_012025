// Fill out your copyright notice in the Description page of Project Settings.

#include "Bloque_Acero.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/Texture2D.h"

// Establece valores predeterminados
ABloque_Acero::ABloque_Acero()
{
    PrimaryActorTick.bCanEverTick = false;

    MallaBloque_Acero = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloque_Acero"));
    SetRootComponent(MallaBloque_Acero);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloque_Acero(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

    if (ObjetoMallaBloque_Acero.Succeeded())
    {
        MallaBloque_Acero->SetStaticMesh(ObjetoMallaBloque_Acero.Object);
        MallaBloque_Acero->SetRelativeScale3D(FVector(1.0f, 1.0f, 2.0f));

        // Cargar el nuevo material M_Metal_Burnished_Steel
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialFinder(TEXT("/Game/StarterContent/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel"));
        if (MaterialFinder.Succeeded())
        {
            // Mensaje de depuración para confirmar que el material se cargó
            UE_LOG(LogTemp, Warning, TEXT("Material M_Metal_Burnished_Steel cargado correctamente"));

            // Aplicar el material directamente (ya tiene su textura asociada)
            MallaBloque_Acero->SetMaterial(0, MaterialFinder.Object);
        }
        else
        {
            // Mensaje de depuración si falla la carga del material
            UE_LOG(LogTemp, Error, TEXT("No se pudo cargar el material M_Metal_Burnished_Steel"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("No se pudo cargar la malla Shape_Cube"));
    }
}

// Se ejecuta al inicio del juego o cuando el actor es generado
void ABloque_Acero::BeginPlay()
{
    Super::BeginPlay();
    AjustarAlSuelo();
}

// Función para ajustar el bloque al suelo usando un raycast
void ABloque_Acero::AjustarAlSuelo()
{
    FVector StartLocation = GetActorLocation();
    FVector EndLocation = StartLocation + FVector(0.0f, 0.0f, -2000.0f);
    FHitResult HitResult;
    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(this);

    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, QueryParams);

    if (bHit)
    {
        FVector NewLocation = HitResult.Location + FVector(0.0f, 0.0f, 1.0f);
        SetActorLocation(NewLocation);
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Bloque de Acero ajustado al suelo en Z: %f"), NewLocation.Z));
        }
    }
    else
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("No se detectó el suelo para el Bloque de Acero"));
        }
    }
}