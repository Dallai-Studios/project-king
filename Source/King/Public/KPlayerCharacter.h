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

	UPROPERTY(EditAnywhere, Category="Components")
	class UPaperZDAnimationComponent* animationComponent;


	
	// =================================================
	// Player Config:
	// =================================================
	UPROPERTY(EditAnywhere, Category="Character Config")
	float positiveMovementXScale;

	UPROPERTY(EditAnywhere, Category="Character Config")
	float negativeMovementXScale;	


	
	// =================================================
	// Player Attack:
	// =================================================
	int currentAttack = 1;



	// =================================================
	// Player Movement:
	// =================================================
	bool playerIsMoving = false;

	

public:
	// =================================================
	// Life Cycle:
	// =================================================
	AKPlayerCharacter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	
	// =================================================
	// Player Movement:
	// =================================================
	UFUNCTION(BlueprintCallable, Category="Player Movement")
	void StartMoving();
	
	UFUNCTION(BlueprintCallable, Category="Player Movement")
	void MovePlayer(float axisValue);

	UFUNCTION(BlueprintCallable, Category="Player Movement")
	void StopMoving();

	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Player Movement")
	bool IsPlayerMoving() const;



	// =================================================
	// Player Attack:
	// =================================================
	UFUNCTION(BlueprintCallable, Category="Player Attack")
	void Attack(EKAttackDirection attackDirection);
};
