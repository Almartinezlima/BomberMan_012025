// Fill out your copyright notice in the Description page of Project Settings.

#include "Luna.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ALuna::ALuna()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Crear el componente de malla y establecerlo como RootComponent
    MallaLuna = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaLuna"));
    SetRootComponent(MallaLuna); // Establecer MallaLuna como raíz en lugar de adjuntarlo a un RootComponent nulo

    // Cargar la malla de la esfera
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaLuna(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
    if (ObjetoMallaLuna.Succeeded())
    {
        MallaLuna->SetStaticMesh(ObjetoMallaLuna.Object);
        MallaLuna->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

        // Cargar el material M_Rock_Basalt
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialFinder(TEXT("/Game/StarterContent/Materials/M_Rock_Basalt.M_Rock_Basalt"));
        if (MaterialFinder.Succeeded())
        {
            UE_LOG(LogTemp, Warning, TEXT("Material M_Rock_Basalt cargado correctamente"));
            MallaLuna->SetMaterial(0, MaterialFinder.Object);
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("No se pudo cargar el material M_Rock_Basalt"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("No se pudo cargar la malla Shape_Sphere"));
    }

    FloatSpeed = 14.0f;
    RotationSpeed = 26.0f;

    bPuedeMoverse = FMath::RandBool();
}

// Called when the game starts or when spawned
void ALuna::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ALuna::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (bPuedeMoverse)
    {
        FVector NewLocation = GetActorLocation();
        FRotator NewRotation = GetActorRotation();
        float RunningTime = GetGameTimeSinceCreation();

        // Aleatoriedad en el desplazamiento en Z
        float DeltaHeight = FMath::FRandRange(-1.0f, 1.0f) * FloatSpeed;
        NewLocation.Z += DeltaHeight;

        // Aleatoriedad en la rotación
        float DeltaRotation = FMath::FRandRange(-1.0f, 1.0f) * RotationSpeed;
        NewRotation.Yaw += DeltaRotation;

        SetActorLocationAndRotation(NewLocation, NewRotation);
    }
}