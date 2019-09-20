// Fill out your copyright notice in the Description page of Project Settings.



#include "Public/MyActor.h"
#include "../../ThirdParty/include/Mylib.h"
#include "Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void* v_dllHandle;
typedef int(*dlladd)(int a,int b);
dlladd m_dlladd;
// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	FString filePath = "D://Users//veyvi//Documents//Unreal Projects//GIMUE//ThirdParty//bin//Mylib.dll";
	v_dllHandle = FPlatformProcess::GetDllHandle(*filePath);
	FString procName = "ADDUE";
	m_dlladd =static_cast<dlladd>(FPlatformProcess::GetDllExport(v_dllHandle, *procName));
	int y= m_dlladd(5,5);
	UE_LOG(LogTemp, Warning, TEXT("dll %d"), y);

	int z = ADDUE(10, 10);
	UE_LOG(LogTemp, Warning, TEXT("lib %d"),z);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

