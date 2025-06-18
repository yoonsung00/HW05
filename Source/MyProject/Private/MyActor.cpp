// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	CurrentPosition = FVector2D(0, 0);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("이동 시작 : (% .0f, % .0f)"), CurrentPosition.X, CurrentPosition.Y);
	Move();
}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

void AMyActor::Move()
{
    for (int32 i = 1; i <= 10; ++i)
    {
        int32 x = Step();
        int32 y = Step();

        CurrentPosition.X += x;
        CurrentPosition.Y += y;

        UE_LOG(LogTemp, Warning, TEXT("Step %d: 현재 위치 = (%.0f, %.0f)"), i, CurrentPosition.X, CurrentPosition.Y);
    }

    UE_LOG(LogTemp, Warning, TEXT("이동 완료"));
}
