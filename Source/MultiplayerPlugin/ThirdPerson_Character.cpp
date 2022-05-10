// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPerson_Character.h"
#include "OnlineSubsystem.h"

// Sets default values
AThirdPerson_Character::AThirdPerson_Character():
	CreateSessionCompleteDelegate(FOnCreateSessionCompleteDelegate::CreateUObject(this, &ThisClass::OnCreateSessionComplete))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();

	if (OnlineSubsystem)
	{
		OnlineSessionInterface = OnlineSubsystem->GetSessionInterface();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				15.f,
				FColor::Blue,
				FString::Printf(TEXT("Found subsystem %s"), *OnlineSubsystem->GetSubsystemName().ToString())
			);
		}
	}
}

// Called when the game starts or when spawned
void AThirdPerson_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AThirdPerson_Character::CreateGameSession()
{
	// Called when pressing the one key
}

void AThirdPerson_Character::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
}

// Called every frame
void AThirdPerson_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AThirdPerson_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

