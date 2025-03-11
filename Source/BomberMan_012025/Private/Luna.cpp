// Fill out your copyright notice in the Description page of Project Settings.


#include "Luna.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ALuna::ALuna()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaLuna = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaLuna"));
	//RootComponent = MeshComp;
	MallaLuna->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaLuna(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	if (ObjetoMallaLuna.Succeeded())
	{
		MallaLuna->SetStaticMesh(ObjetoMallaLuna.Object);

		MallaLuna->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
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