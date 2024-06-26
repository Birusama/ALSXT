#pragma once

#include "Settings/ALSXTIdleAnimationSettings.h"
#include "ALSXTIdleAnimationComponentInterface.generated.h"

UINTERFACE(Blueprintable)
class UALSXTIdleAnimationComponentInterface : public UInterface {
	GENERATED_BODY()
};

class ALSXT_API IALSXTIdleAnimationComponentInterface {
	GENERATED_BODY()

public:
  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Idle Animation Component Interface")
  bool ShouldIdle();

  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Idle Animation Component Interface")
  UALSXTIdleAnimationSettings* SelectIdleSettings();

  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Idle Animation Component Interface")
  void EnableIdleAnimation(bool Enable);

  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Idle Animation Component Interface")
  void ResetTimer();

  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Idle Animation Component Interface")
  void StopIdleAnimation();

};