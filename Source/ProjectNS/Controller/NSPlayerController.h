// Copyright Project NS

#pragma once

#include "../NSInfo.h"
#include "GameFramework/PlayerController.h"
#include "NSPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class PROJECTNS_API ANSPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ANSPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void TraceCursor();

	/* OutlineInterface를 상속받았는지 확인하고 Excute */
	void TurnOnOutlineActor(AActor* InActor);

	/* OutlineInterface를 상속받았는지 확인하고 Excute */
	void TurnOffOutlineActor(AActor* InActor);

public:
	virtual void PlayerTick(float DeltaTime) override;

protected:
	void OnLeftClickStarted(const FInputActionValue& Value);
	void OnLeftClickTriggered(const FInputActionValue& Value);
	void OnLeftClickCompleted(const FInputActionValue& Value);

protected:
	UPROPERTY(EditAnywhere, Category = "NS|Input")
	TObjectPtr<UInputMappingContext> NSIMC;

protected: // Mouse Action
	UPROPERTY(EditAnywhere, Category = "NS|Input|Mouse")
	TObjectPtr<UInputAction> LeftClickAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Mouse")
	TObjectPtr<UInputAction> RightClickAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Mouse")
	TObjectPtr<UInputAction> WheelScrollAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Mouse")
	TObjectPtr<UInputAction> WheelClickAction;

protected: // Keyboard Action
	UPROPERTY(EditAnywhere, Category = "NS|Input|Keyboard")
	TObjectPtr<UInputAction> QAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Keyboard")
	TObjectPtr<UInputAction> EAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Keyboard")
	TObjectPtr<UInputAction> WAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Keyboard")
	TObjectPtr<UInputAction> AAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Keyboard")
	TObjectPtr<UInputAction> SAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Keyboard")
	TObjectPtr<UInputAction> DAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Keyboard")
	TObjectPtr<UInputAction> ESCAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Keyboard")
	TObjectPtr<UInputAction> IAction;

	UPROPERTY(EditAnywhere, Category = "NS|Input|Keyboard")
	TObjectPtr<UInputAction> KAction;


	UPROPERTY(EditAnywhere, Category = "NS|Input")
	TObjectPtr<UNiagaraSystem> FXCursor;

protected:
	UPROPERTY()
	TObjectPtr<AActor>	LastHitActor;

	UPROPERTY()
	TObjectPtr<AActor>	CurrentHitActor;

	FHitResult			CursorHitResult;

private: // Mouse
	// Mouse Wheel Scroll Action, WheelScroll 1D(float)
	void OnMouseWheelScroll(const FInputActionValue& Value);
	// Mouse Wheel Click Action, WheelClick
	void OnMouseWheelClick(const FInputActionValue& Value);

	// Mouse Right Started Action, Right Click
	void OnMouseRightStarted(const FInputActionValue& Value);
	// Mouse Right Released Action, Right Released
	void OnMouseRightReleased(const FInputActionValue& Value);

private: // Keyboard
	//  Camera Controll

	// Keyboard E Triggered Action, Q
	void OnQTriggered(const FInputActionValue& Value);
	// Keyboard Q Triggered Action, E
	void OnETriggered(const FInputActionValue& Value);

	// Keyboard W Triggered Action, W
	void OnWTriggered(const FInputActionValue& Value);
	// Keyboard A Triggered Action, A
	void OnATriggered(const FInputActionValue& Value);
	// Keyboard A Triggered Action, S
	void OnSTriggered(const FInputActionValue& Value);
	// Keyboard A Triggered Action, D
	void OnDTriggered(const FInputActionValue& Value);
	

	// Shortcut Key

	// Keyboard I Started Action, I
	void OnIStarted(const FInputActionValue& Value);
	// Keyboard K Started Action, I
	void OnKStarted(const FInputActionValue& Value);
	// Keyboard ESC Started Action, ESC
	void OnESCStarted(const FInputActionValue& Value);


public: // TESTTESTTEST
	UFUNCTION(BlueprintCallable)
	void TurnEnd();

};
