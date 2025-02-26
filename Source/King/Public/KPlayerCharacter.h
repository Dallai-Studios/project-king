#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EKAttackDirection.h"
#include "KPlayerCharacter.generated.h"

UCLASS()
class KING_API AKPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// =================================================
	// Components:
	// =================================================
	UPROPERTY(EditAnywhere, Category="Components")
	class UPaperFlipbookComponent* flipbookComponent;

	UPROPERTY(EditAnywhere, Category="Components")
	class USpringArmComponent* cameraSpringArm;

	UPROPERTY(EditAnywhere, Category="Components")
	class UCameraComponent* playerCamera;


	
	// =================================================
	// Configuração do Player:
	// =================================================
	UPROPERTY(EditAnywhere, Category="Character Config")
	float positiveMovementXScale;

	UPROPERTY(EditAnywhere, Category="Character Config")
	float negativeMovementXScale;	

	UPROPERTY(EditAnywhere, Category="Character Config")
	class UPaperFlipbook* idleFlipbook;

	UPROPERTY(EditAnywhere, Category="Character Config")
	UPaperFlipbook* runFlipbook;

	UPROPERTY(EditAnywhere, Category="Character Config")
	UPaperFlipbook* attack1Flipbook;

	UPROPERTY(EditAnywhere, Category="Character Config")
	UPaperFlipbook* attack2Flipbook;

	UPROPERTY(EditAnywhere, Category="Character Config")
	UPaperFlipbook* attack3Flipbook;

	UPROPERTY(EditAnywhere, Category="Character Config")
	UPaperFlipbook* takeHitFlipbook;

	UPROPERTY(EditAnywhere, Category="Character Config")
	UPaperFlipbook* deathFlipbook;


	
	// =================================================
	// Ataques do Player:
	// =================================================
	int currentAttack = 1;
	

public:
	// =================================================
	// Ciclo de Vida:
	// =================================================
	AKPlayerCharacter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	
	// =================================================
	// Movimento do Player:
	// =================================================
	UFUNCTION(BlueprintCallable, Category="Player Movement")
	void StartMoving();
	
	UFUNCTION(BlueprintCallable, Category="Player Movement")
	void MovePlayer(float axisValue);

	UFUNCTION(BlueprintCallable, Category="Player Movement")
	void StopMoving();



	// =================================================
	// Ataques do Player:
	// =================================================
	UFUNCTION(BlueprintCallable, Category="Player Attack")
	void Attack(EKAttackDirection attackDirection);
};
