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
    FVector2D PreviousPosition = CurrentPosition;
    float TotalDistance = 0.0f;
    int32 EventCount = 0;

    for (int32 i = 1; i <= 10; ++i)
    {
        int32 x = Step();
        int32 y = Step();

        CurrentPosition.X += x;
        CurrentPosition.Y += y;

        float StepDistance = FVector2D::Distance(CurrentPosition, PreviousPosition);
        TotalDistance += StepDistance;

        bool bEventOccurred = FMath::RandRange(0, 1) == 1;

        if (bEventOccurred)
        {
            ++EventCount;
        }

        UE_LOG(LogTemp, Warning, TEXT("Step %d: 현재 위치 = (%.0f, %.0f), 이동 거리 = %.2f, 이벤트 발생: %s"), i, CurrentPosition.X, CurrentPosition.Y, StepDistance, bEventOccurred ? TEXT("예") : TEXT("아니오"));

        PreviousPosition = CurrentPosition;
    }

    UE_LOG(LogTemp, Warning, TEXT("이동 완료 - 총 이동 거리: %.2f, 이벤트 발생 횟수: %d"), TotalDistance, EventCount);
}

