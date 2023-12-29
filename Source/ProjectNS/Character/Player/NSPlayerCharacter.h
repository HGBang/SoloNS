// Copyright Project NS

#pragma once

#include "../NSCharacter.h"
#include "NSPlayerCharacter.generated.h"

#define MIN_CAMERA_ZOOM 1000.f
#define MAX_CAMERA_ZOOM 2000.f
#define BASE_CAMERA_ZOOM 1500.f
#define ZOOM_DEGREE 150.f
#define ROTATION_DEGREE 3.f

class USpringArmComponent;
class UCameraComponent;
class USplineComponent;
class USplineMeshComponent;
class UPlayerMainWidget;
class UCharacterSheetComponent;

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSPlayerCharacter : public ANSCharacter
{
	GENERATED_BODY()

public:
	ANSPlayerCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Category = "NS|Component|Camera", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<USpringArmComponent>		SpringArm;

	UPROPERTY(Category = "NS|Component|Camera", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UCameraComponent>		Camera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Component", meta = (AllowPrivateAccess = true))
	TObjectPtr<UCharacterSheetComponent> CharacterSheet;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NS|PathSpline", meta = (AllowPrivateAccess = true))
	TObjectPtr<USplineComponent> PathSpline;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "NS|PathSpline", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMesh>		PathMesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|PathSpline", meta = (AllowPrivateAccess = true))
	float PathMeshLength;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|PathSpline", meta = (AllowPrivateAccess = true))
	TArray<TObjectPtr<USplineMeshComponent>>	SplineMeshes;

	FVector CachedDestinationPoint;

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "NS|Widget", meta = (AllowPrivateAccess = true))
	TSubclassOf<UPlayerMainWidget> PlayerMainWidgetClass;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "NS|Widget", meta = (AllowPrivateAccess = true))
	TObjectPtr<UPlayerMainWidget> PlayerMainWidget;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Battle Area Option
public:
	virtual void PlayTurn(const float& DiceValue) override;
	virtual void CharacterTurnEnd() override;

public:
	void ShowPathSpline(const FVector& DestinationPoint);
	virtual void CalculateAccuracy(ANSCharacter* Target);

	
public: // Spring Arm Setting Func
	// 카메라 줌인/아웃
	void ZoomCamera(float Degree);
	// 카메라 기본으로 정렬
	void SetAlignmentCamera();
	// 카메라 좌우 조정
	void RotationCamera(float Degree);

};
