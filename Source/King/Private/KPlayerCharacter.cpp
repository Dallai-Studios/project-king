#include "KPlayerCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// =================================================
// Ciclo de Vida:
// =================================================
AKPlayerCharacter::AKPlayerCharacter() {
	PrimaryActorTick.bCanEverTick = true;

	this->flipbookComponent = this->CreateDefaultSubobject<UPaperFlipbookComponent>("Character Flipbook");
	this->flipbookComponent->SetupAttachment(this->GetRootComponent());

	this->cameraSpringArm = this->CreateDefaultSubobject<USpringArmComponent>("Camera Spring Arm");
	this->cameraSpringArm->SetupAttachment(this->GetRootComponent());

	this->playerCamera = this->CreateDefaultSubobject<UCameraComponent>("Player Camera");
	this->playerCamera->SetupAttachment(this->cameraSpringArm);
}

void AKPlayerCharacter::BeginPlay() {
	Super::BeginPlay();
}

void AKPlayerCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}



// =================================================
// Movimento do Player:
// =================================================
void AKPlayerCharacter::StartMoving() {
	this->flipbookComponent->SetFlipbook(this->runFlipbook);
}

void AKPlayerCharacter::MovePlayer(float axisValue) {
	if (axisValue == 0) return;

	auto flipbookScale = this->flipbookComponent->GetComponentScale();
	
	if (axisValue > 0) flipbookScale.X = this->positiveMovementXScale;
	if (axisValue < 0) flipbookScale.X = this->negativeMovementXScale;
	
	this->flipbookComponent->SetRelativeScale3D(flipbookScale);

	this->AddMovementInput(this->GetActorForwardVector(), axisValue);
}

void AKPlayerCharacter::StopMoving() {
	this->flipbookComponent->SetFlipbook(this->idleFlipbook);
}

void AKPlayerCharacter::Attack(EKAttackDirection attackDirection) {
	auto flipbookScale = this->flipbookComponent->GetRelativeScale3D();

	// I'm using this control variable just to make sure to propel the player to the right
	// direction when the player performs the attack. In this scenario, everytime the player
	// uses the attack, I will also add a small "dash" to the direction of the attack. -Renan
	float directionMultiplayer;
	
	if (attackDirection == EKAttackDirection::ATTACK_RIGHT) {
		flipbookScale.X = this->positiveMovementXScale;
		directionMultiplayer = 1;
	}
	
	if (attackDirection == EKAttackDirection::ATTACK_LEFT) {
		flipbookScale.X = this->negativeMovementXScale;
		directionMultiplayer = -1;
	}

	this->flipbookComponent->SetRelativeScale3D(flipbookScale);

	switch (this->currentAttack) {
		case 1: this->flipbookComponent->SetFlipbook(this->attack1Flipbook); break;
		case 2: this->flipbookComponent->SetFlipbook(this->attack2Flipbook); break;
		case 3: this->flipbookComponent->SetFlipbook(this->attack3Flipbook); break;
	}

	this->currentAttack++;
	if (this->currentAttack > 3) this->currentAttack = 1;
}
