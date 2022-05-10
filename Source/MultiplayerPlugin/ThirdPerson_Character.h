// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "ThirdPerson_Character.generated.h"

UCLASS()
class MULTIPLAYERPLUGIN_API AThirdPerson_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThirdPerson_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void CreateGameSession();

	UFUNCTION(BlueprintCallable)
	void JoinGameSession();

	// callback function
	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	// callback function
	void OnFindSessionsComplete(bool bWasSuccessful);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Pointer to the online session interface
	IOnlineSessionPtr OnlineSessionInterface;

private:
	
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FOnFindSessionsCompleteDelegate FindSessionsCompleteDelegate;

	TSharedPtr<FOnlineSessionSearch> SessionSearch;
};
