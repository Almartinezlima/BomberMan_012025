// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Bloque.h"
#include "Muro.h"
#include "Luna.h"
#include "Bloque_Acero.h"

ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
    // Set default pawn class to our Blueprinted character
    static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
    if (PlayerPawnBPClass.Class != NULL)
    {
        DefaultPawnClass = PlayerPawnBPClass.Class;
    }
}

void ABomberMan_012025GameMode::BeginPlay()
{
    Super::BeginPlay();

    // Mensajes de depuración en pantalla
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Spawn de Bloques, Muros, Bloques de Acero y Luna iniciado"));
    }

    // 🔹 Spawning de Bloques Normales
    int numeroBloqueConMovimiento = 0;
    for (int i = 0; i < 10; i++)
    {
        ABloque* bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), FVector(500.0f + i * 100, 2500.0f - i * 100, 20.0f), FRotator(0.0f, 0.0f, 0.0f));

        if (bloque && bloque->bPuedeMoverse)
        {
            numeroBloqueConMovimiento++;
        }

        if (numeroBloqueConMovimiento >= 2 && bloque)
        {
            bloque->bPuedeMoverse = false;
        }
    }

    // 🔹 Spawning de Muros
    int numeroMuroConMovimiento = 0;
    for (int i = 0; i < 20; i++)
    {
        AMuro* muro = GetWorld()->SpawnActor<AMuro>(AMuro::StaticClass(), FVector(800.0f + i * 100, 3000.0f - i * 100, 40.0f), FRotator(0.0f, 0.0f, 0.0f));

        if (muro && muro->bPuedeMoverse)
        {
            numeroMuroConMovimiento++;
        }

        if (numeroMuroConMovimiento >= 4 && muro)
        {
            muro->bPuedeMoverse = false;
        }
    }

    // 🔹 Spawning de Bloques de Acero (Indestructibles) en el suelo, sobre el nivel del piso
    // Cambié la posición Z para que estén al nivel del suelo (Z=0, ajusta según sea necesario).
    int cantidadBloquesAcero = 5;
    float posicionXInicial = 1500.0f; // Nueva ubicación X de inicio
    float posicionY = 1000.0f;       // Nueva ubicación Y de inicio
    float espacioEntreBloques = 150.0f;
    float posicionZ = 0.0f;          // Nivel de piso en Z

    for (int i = 0; i < cantidadBloquesAcero; i++)
    {
        float posicionX = posicionXInicial + (i * espacioEntreBloques * 2); // Intercalado dejando espacio
        ABloque_Acero* bloqueAcero = GetWorld()->SpawnActor<ABloque_Acero>(ABloque_Acero::StaticClass(), FVector(posicionX, posicionY, posicionZ), FRotator(0.0f, 0.0f, 0.0f));

        if (bloqueAcero)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Bloque de Acero %d creado en X: %f, Y: %f, Z: %f"), i + 1, posicionX, posicionY, posicionZ));
        }
    }

    // 🔹 Spawning de una Luna
    ALuna* luna = GetWorld()->SpawnActor<ALuna>(ALuna::StaticClass(), FVector(1000.0f, 1000.0f, 300.0f), FRotator(0.0f, 0.0f, 0.0f));
    if (luna)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Luna creada exitosamente"));
    }
}
