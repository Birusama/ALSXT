// MIT


#include "ALSXTCharacterAdvanced.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "AlsCameraComponent.h"
#include "Components/Character/ALSXTCharacterCameraEffectsComponent.h"
#include "Components/Character/ALSXTEmoteComponent.h"
#include "Components/Character/ALSXTGestureComponent.h"
#include "Math/Vector.h"
#include "ALSXTBlueprintFunctionLibrary.h"
#include "Engine/World.h"

AALSXTCharacterAdvanced::AALSXTCharacterAdvanced(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	BodyCamera = CreateDefaultSubobject<UCineCameraComponent>(TEXT("Body Camera"));
	BodyCamera->SetupAttachment(GetMesh(), FName("spine_03"));
	BodyCamera->SetRelativeRotation_Direct({ 0.0f, 90.0f, -90.0f });
	BodyCamera->SetRelativeLocation_Direct({ 0.0f, 20.72f, 0.0f });
	
	Combat = CreateDefaultSubobject<UALSXTCombatComponent>(TEXT("Combat"));
	AddOwnedComponent(Combat);

	AcrobaticActions = CreateDefaultSubobject<UALSXTAcrobaticActionComponent>(TEXT("Acrobatic Actions"));
	AddOwnedComponent(AcrobaticActions);

	Emotes = CreateDefaultSubobject<UALSXTEmoteComponent>(TEXT("Emotes"));
	AddOwnedComponent(Emotes);

	Gestures = CreateDefaultSubobject<UALSXTGestureComponent>(TEXT("Gestures"));
	AddOwnedComponent(Gestures);
	
	CameraEffects = CreateDefaultSubobject<UALSXTCharacterCameraEffectsComponent>(TEXT("Camera Effects"));
	AddOwnedComponent(CameraEffects);
}

void AALSXTCharacterAdvanced::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bDesiredAiming && IALSXTHeldItemInterface::Execute_IsHoldingAimableItem(this))
	{
		FTransform NewTransform;
		FALSXTAimState NewAimState = GetAimState();
		NewAimState.CurrentCameraTargetRelativeTransform = NewTransform;
		SetAimState(NewAimState);
	}
}

void AALSXTCharacterAdvanced::BeginPlay()
{
	Super::BeginPlay();
}

void AALSXTCharacterAdvanced::SetupPlayerInputComponent(UInputComponent* Input)
{
	Super::SetupPlayerInputComponent(Input);

	auto* EnhancedInput{ Cast<UEnhancedInputComponent>(Input) };
	if (IsValid(EnhancedInput))
	{
		EnhancedInput->BindAction(HoldBreathAction, ETriggerEvent::Triggered, this, &ThisClass::InputHoldBreath);
		EnhancedInput->BindAction(AcrobaticAction, ETriggerEvent::Triggered, this, &ThisClass::InputAcrobaticAction);
		EnhancedInput->BindAction(PrimaryActionAction, ETriggerEvent::Triggered, this, &ThisClass::InputPrimaryAction);
		EnhancedInput->BindAction(SecondaryActionAction, ETriggerEvent::Triggered, this, &ThisClass::InputSecondaryAction);
		EnhancedInput->BindAction(SwitchTargetLeftAction, ETriggerEvent::Triggered, this, &ThisClass::InputSwitchTargetLeft);
		EnhancedInput->BindAction(SwitchTargetRightAction, ETriggerEvent::Triggered, this, &ThisClass::InputSwitchTargetRight);
		// EnhancedInput->BindAction(PrimaryInteractionAction, ETriggerEvent::Triggered, this, &ThisClass::InputPrimaryInteraction);
		// EnhancedInput->BindAction(SecondaryInteractionAction, ETriggerEvent::Triggered, this, &ThisClass::InputSecondaryInteraction);
		EnhancedInput->BindAction(SelectEmoteAction, ETriggerEvent::Triggered, this, &ThisClass::InputSelectEmote);
		EnhancedInput->BindAction(SelectGestureAction, ETriggerEvent::Triggered, this, &ThisClass::InputSelectGesture);

		OnSetupPlayerInputComponentUpdated.Broadcast();
	}
}

FTransform AALSXTCharacterAdvanced::GetADSRelativeTransform_Implementation() const
{
	FTransform NewTransform;
	NewTransform.SetLocation(UKismetMathLibrary::InverseTransformDirection(GetCapsuleComponent()->GetComponentTransform(), AimState.CurrentCameraTargetTransform.GetLocation()));
	NewTransform.SetRotation(UKismetMathLibrary::InverseTransformRotation(GetCapsuleComponent()->GetComponentTransform(), AimState.CurrentCameraTargetTransform.GetRotation().Rotator()).Quaternion());
	return NewTransform;
}

FRotator AALSXTCharacterAdvanced::CalculateRecoilControlRotation_Implementation(FRotator AdditiveControlRotation) const
{
	FRotator CurrentControlRotation = GetWorld()->GetFirstPlayerController()->GetControlRotation();
	FRotator NewControlRotation = CurrentControlRotation + AdditiveControlRotation;
	GetWorld()->GetFirstPlayerController()->SetControlRotation(NewControlRotation);
	return NewControlRotation;
}

void AALSXTCharacterAdvanced::CalcADSCamera(FMinimalViewInfo& ViewInfo)
{
	if (Camera->IsActive() && GetViewMode() == AlsViewModeTags::FirstPerson && GetDesiredRotationMode() == AlsRotationModeTags::Aiming && GetDesiredCombatStance() == ALSXTCombatStanceTags::Aiming)
	{
		Camera->GetViewInfo(ViewInfo);
		return;
	}

}

void AALSXTCharacterAdvanced::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	FDoRepLifetimeParams Parameters;
	Parameters.bIsPushBased = true;

	Parameters.Condition = COND_SkipOwner;
	DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, DesiredHoldingBreath, Parameters)
	DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, DesiredGesture, Parameters)
	DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, DesiredGestureHand, Parameters)
	DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, DesiredReloadingType, Parameters)
	DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, DesiredFirearmFingerAction, Parameters)
	DOREPLIFETIME_WITH_PARAMS_FAST(ThisClass, DesiredFirearmFingerActionHand, Parameters)
}

// Gesture

void AALSXTCharacterAdvanced::SetDesiredGesture(const FGameplayTag& NewGestureTag)
{
	if (DesiredGesture != NewGestureTag)
	{
		DesiredGesture = NewGestureTag;

		MARK_PROPERTY_DIRTY_FROM_NAME(ThisClass, DesiredGesture, this)

			if (GetLocalRole() == ROLE_AutonomousProxy)
			{
				ServerSetDesiredGesture(NewGestureTag);
			}
	}
}

void AALSXTCharacterAdvanced::ServerSetDesiredGesture_Implementation(const FGameplayTag& NewGestureTag)
{
	SetDesiredGesture(NewGestureTag);
}

void AALSXTCharacterAdvanced::SetGesture(const FGameplayTag& NewGestureTag)
{

	if (Gesture != NewGestureTag)
	{
		const auto PreviousGesture{ Gesture };

		Gesture = NewGestureTag;

		OnGestureChanged(PreviousGesture);
	}
}

void AALSXTCharacterAdvanced::OnGestureChanged_Implementation(const FGameplayTag& PreviousGestureTag) {}

// GestureHand

void AALSXTCharacterAdvanced::SetDesiredGestureHand(const FGameplayTag& NewGestureHandTag)
{
	if (DesiredGestureHand != NewGestureHandTag)
	{
		DesiredGestureHand = NewGestureHandTag;

		MARK_PROPERTY_DIRTY_FROM_NAME(ThisClass, DesiredGestureHand, this)

			if (GetLocalRole() == ROLE_AutonomousProxy)
			{
				ServerSetDesiredGestureHand(NewGestureHandTag);
			}
	}
}

void AALSXTCharacterAdvanced::ServerSetDesiredGestureHand_Implementation(const FGameplayTag& NewGestureHandTag)
{
	SetDesiredGestureHand(NewGestureHandTag);
}

void AALSXTCharacterAdvanced::SetGestureHand(const FGameplayTag& NewGestureHandTag)
{

	if (GestureHand != NewGestureHandTag)
	{
		const auto PreviousGestureHand{ GestureHand };

		GestureHand = NewGestureHandTag;

		OnGestureHandChanged(PreviousGestureHand);
	}
}

void AALSXTCharacterAdvanced::OnGestureHandChanged_Implementation(const FGameplayTag& PreviousGestureHandTag) {}

// ReloadingType

void AALSXTCharacterAdvanced::SetDesiredReloadingType(const FGameplayTag& NewReloadingTypeTag)
{
	if (DesiredReloadingType != NewReloadingTypeTag)
	{
		DesiredReloadingType = NewReloadingTypeTag;

		MARK_PROPERTY_DIRTY_FROM_NAME(ThisClass, DesiredReloadingType, this)

			if (GetLocalRole() == ROLE_AutonomousProxy)
			{
				ServerSetDesiredReloadingType(NewReloadingTypeTag);
			}
	}
}

void AALSXTCharacterAdvanced::ServerSetDesiredReloadingType_Implementation(const FGameplayTag& NewReloadingTypeTag)
{
	SetDesiredReloadingType(NewReloadingTypeTag);
}

void AALSXTCharacterAdvanced::SetReloadingType(const FGameplayTag& NewReloadingTypeTag)
{

	if (ReloadingType != NewReloadingTypeTag)
	{
		const auto PreviousReloadingType{ ReloadingType };

		ReloadingType = NewReloadingTypeTag;

		OnReloadingTypeChanged(PreviousReloadingType);
	}
}

void AALSXTCharacterAdvanced::OnReloadingTypeChanged_Implementation(const FGameplayTag& PreviousReloadingTypeTag) {}

// FirearmFingerAction

void AALSXTCharacterAdvanced::SetDesiredFirearmFingerAction(const FGameplayTag& NewFirearmFingerActionTag)
{
	if (DesiredFirearmFingerAction != NewFirearmFingerActionTag)
	{
		DesiredFirearmFingerAction = NewFirearmFingerActionTag;

		MARK_PROPERTY_DIRTY_FROM_NAME(ThisClass, DesiredFirearmFingerAction, this)

			if (GetLocalRole() == ROLE_AutonomousProxy)
			{
				ServerSetDesiredFirearmFingerAction(NewFirearmFingerActionTag);
			}
	}
}

void AALSXTCharacterAdvanced::ServerSetDesiredFirearmFingerAction_Implementation(const FGameplayTag& NewFirearmFingerActionTag)
{
	SetDesiredFirearmFingerAction(NewFirearmFingerActionTag);
}

void AALSXTCharacterAdvanced::SetFirearmFingerAction(const FGameplayTag& NewFirearmFingerActionTag)
{

	if (FirearmFingerAction != NewFirearmFingerActionTag)
	{
		const auto PreviousFirearmFingerAction{ FirearmFingerAction };

		FirearmFingerAction = NewFirearmFingerActionTag;

		OnFirearmFingerActionChanged(PreviousFirearmFingerAction);
	}
}

void AALSXTCharacterAdvanced::OnFirearmFingerActionChanged_Implementation(const FGameplayTag& PreviousFirearmFingerActionTag) {}

// FirearmFingerActionHand

void AALSXTCharacterAdvanced::SetDesiredFirearmFingerActionHand(const FGameplayTag& NewFirearmFingerActionHandTag)
{
	if (DesiredFirearmFingerActionHand != NewFirearmFingerActionHandTag)
	{
		DesiredFirearmFingerActionHand = NewFirearmFingerActionHandTag;

		MARK_PROPERTY_DIRTY_FROM_NAME(ThisClass, DesiredFirearmFingerActionHand, this)

			if (GetLocalRole() == ROLE_AutonomousProxy)
			{
				ServerSetDesiredFirearmFingerActionHand(NewFirearmFingerActionHandTag);
			}
	}
}

void AALSXTCharacterAdvanced::ServerSetDesiredFirearmFingerActionHand_Implementation(const FGameplayTag& NewFirearmFingerActionHandTag)
{
	SetDesiredFirearmFingerActionHand(NewFirearmFingerActionHandTag);
}

void AALSXTCharacterAdvanced::SetFirearmFingerActionHand(const FGameplayTag& NewFirearmFingerActionHandTag)
{

	if (FirearmFingerActionHand != NewFirearmFingerActionHandTag)
	{
		const auto PreviousFirearmFingerActionHand{ FirearmFingerActionHand };

		FirearmFingerActionHand = NewFirearmFingerActionHandTag;

		OnFirearmFingerActionHandChanged(PreviousFirearmFingerActionHand);
	}
}

void AALSXTCharacterAdvanced::OnFirearmFingerActionHandChanged_Implementation(const FGameplayTag& PreviousFirearmFingerActionHandTag) {}

// HoldingBreath
// Pauses the Breath Additive Animation for a period at the cost of stamina

void AALSXTCharacterAdvanced::SetDesiredHoldingBreath(const FGameplayTag& NewHoldingBreathTag)
{
	if (DesiredHoldingBreath != NewHoldingBreathTag)
	{
		DesiredHoldingBreath = NewHoldingBreathTag;

		MARK_PROPERTY_DIRTY_FROM_NAME(ThisClass, DesiredHoldingBreath, this)

			if (GetLocalRole() == ROLE_AutonomousProxy)
			{
				ServerSetDesiredHoldingBreath(NewHoldingBreathTag);
			}
	}
}

void AALSXTCharacterAdvanced::ServerSetDesiredHoldingBreath_Implementation(const FGameplayTag& NewHoldingBreathTag)
{
	SetDesiredHoldingBreath(NewHoldingBreathTag);
}

void AALSXTCharacterAdvanced::SetHoldingBreath(const FGameplayTag& NewHoldingBreathTag)
{

	if (HoldingBreath != NewHoldingBreathTag)
	{
		const auto PreviousHoldingBreath{ HoldingBreath };

		HoldingBreath = NewHoldingBreathTag;

		OnHoldingBreathChanged(PreviousHoldingBreath);
	}
}

void AALSXTCharacterAdvanced::OnHoldingBreathChanged_Implementation(const FGameplayTag& PreviousHoldingBreathTag) {}

FGameplayTag AALSXTCharacterAdvanced::GetCharacterHoldingBreath_Implementation() const
{
	return GetDesiredHoldingBreath();
}

void AALSXTCharacterAdvanced::OnDesiredAimingChanged_Implementation(bool bPreviousDesiredAiming)
{
	if (bDesiredAiming)
	{
		if (Execute_GetTargetableOverlayModes(this).HasTag(OverlayMode) && (DesiredCombatStance.MatchesTag(ALSXTCombatStanceTags::Aiming) || DesiredCombatStance.MatchesTag(ALSXTCombatStanceTags::Ready)))
		{
			Combat->GetClosestTarget();
		}
	}
	else
	{
		Combat->DisengageAllTargets();
	}
}

bool AALSXTCharacterAdvanced::CanPerformPrimaryAction_Implementation() const
{
	return true;
}

bool AALSXTCharacterAdvanced::CanPerformSecondaryAction_Implementation() const
{
	return true;
}

// Input Actions

void AALSXTCharacterAdvanced::InputSelectEmote(const FInputActionValue& ActionValue)
{
	if (CanSelectEmote())
	{
		// 
	}
}

void AALSXTCharacterAdvanced::InputSelectGesture(const FInputActionValue& ActionValue)
{
	if (CanSelectGesture())
	{
		//
	}
}

// Acrobatic Action Component
void AALSXTCharacterAdvanced::InputAcrobaticAction(const FInputActionValue& ActionValue)
{
	if (CanPerformAcrobaticAction() && bMovementEnabled && GetLocomotionAction() != AlsLocomotionActionTags::Acrobatic)
	{
		AcrobaticActions->TryAcrobaticAction();
	}
}

void AALSXTCharacterAdvanced::InputHoldBreath(const FInputActionValue& ActionValue)
{
	if (CanHoldBreath())
	{
		SetDesiredHoldingBreath(ActionValue.Get<bool>() ? ALSXTHoldingBreathTags::True : ALSXTHoldingBreathTags::False);

		if (ActionValue.Get<bool>())
		{
			SetDesiredHoldingBreath(ALSXTHoldingBreathTags::True);
		}
		else
		{
			SetDesiredHoldingBreath(ALSXTHoldingBreathTags::False);
		}
	}
}

void AALSXTCharacterAdvanced::InputReload()
{
	// 
}

void AALSXTCharacterAdvanced::InputReloadWithRetention()
{
	// 
}

//Combat Component
void AALSXTCharacterAdvanced::InputSwitchTargetLeft()
{
	Combat->GetTargetLeft();
}

void AALSXTCharacterAdvanced::InputSwitchTargetRight()
{
	Combat->GetTargetRight();
}

void AALSXTCharacterAdvanced::BeginHoldBreathTimer()
{
	if (ALSXTSettings->Freelook.bEnableFreelook)
	{
		GetWorld()->GetTimerManager().SetTimer(HoldBreathTimerHandle, HoldBreathTimerDelegate, 0.1f, true);
	}
}

void AALSXTCharacterAdvanced::HoldBreathTimer()
{

}

void AALSXTCharacterAdvanced::EndHoldBreathTimer()
{
	// Clear Attack Trace Timer
	// FALSXTFreelookState EmptyState;
	// SetFreelookState(EmptyState);
	GetWorld()->GetTimerManager().ClearTimer(HoldBreathTimerHandle);
}

void AALSXTCharacterAdvanced::OnAttackCollision_Implementation(FAttackDoubleHitResult Hit)
{
	// Combat->OnAttackCollisionDelegate.Add()
	// Combat->OnAttackCollisionDelegate.BindUObject(this, &ThisClass::OnAttackCollision_Implementation);
	// Combat->OnAttackCollision(Hit);
}

// Interface Functions

FGameplayTag AALSXTCharacterAdvanced::GetCharacterGesture_Implementation() const
{
	return GetDesiredGesture();
}

FGameplayTag AALSXTCharacterAdvanced::GetCharacterGestureHand_Implementation() const
{
	return GetDesiredGestureHand();
}

FGameplayTag AALSXTCharacterAdvanced::GetCharacterReloadingType_Implementation() const
{
	return GetDesiredReloadingType();
}

FGameplayTag AALSXTCharacterAdvanced::GetCharacterFirearmFingerAction_Implementation() const
{
	return GetDesiredFirearmFingerAction();
}

FGameplayTag AALSXTCharacterAdvanced::GetCharacterFirearmFingerActionHand_Implementation() const
{
	return GetDesiredFirearmFingerActionHand();
}

//Camera Effects Component Interface
UAlsCameraComponent* AALSXTCharacterAdvanced::GetCameraComponent_Implementation() const
{
	return Camera;
}

UALSXTCharacterCameraEffectsComponent* AALSXTCharacterAdvanced::GetCameraEffectsComponent_Implementation() const
{
	return CameraEffects;
}

FALSXTFirearmAimState AALSXTCharacterAdvanced::GetFirearmAimState_Implementation() const
{
	return FirearmAimState;
}


void AALSXTCharacterAdvanced::PlayAttackSound_Implementation(bool MovementSound, bool AccentSound, bool WeaponSound, const FGameplayTag& SoundSex, const FGameplayTag& Variant, const FGameplayTag& Overlay, const FGameplayTag& Strength, const FGameplayTag& AttackMode, const float Stamina)
{
	CharacterSound->PlayAttackSound(MovementSound, AccentSound, WeaponSound, SoundSex, Variant, Overlay, Strength, AttackMode, Stamina);
}

void AALSXTCharacterAdvanced::SetRadialBlurEffect_Implementation(float Amount)
{
	CameraEffects->SetRadialBlur(Amount);
}

void AALSXTCharacterAdvanced::ResetRadialBlurEffect_Implementation()
{
	CameraEffects->ResetRadialBlur();
}

void AALSXTCharacterAdvanced::SetFocusEffect_Implementation(bool NewFocus)
{
	CameraEffects->SetFocusEffect(NewFocus);
}

void AALSXTCharacterAdvanced::AddDrunkEffect_Implementation(float Magnitude, float Length, float FadeInLength, float FadeOutLength)
{
	CameraEffects->AddDrunkEffect(Magnitude, Length);
}

void AALSXTCharacterAdvanced::ResetDrunkEffect_Implementation()
{
	CameraEffects->ResetDrunkEffect();
}

void AALSXTCharacterAdvanced::AddHighEffect_Implementation(float Magnitude, float Length, float FadeInLength, float FadeOutLength)
{
	CameraEffects->AddHighEffect(Magnitude, Length);
}

void AALSXTCharacterAdvanced::ResetHighEffect_Implementation()
{
	CameraEffects->ResetHighEffect();
}

void AALSXTCharacterAdvanced::AddSuppressionEffect_Implementation(float Magnitude, float PostDelay)
{
	CameraEffects->AddSuppression(Magnitude, PostDelay);
}

void AALSXTCharacterAdvanced::ResetSuppressionEffect_Implementation()
{
	CameraEffects->ResetSuppression();
}

void AALSXTCharacterAdvanced::AddBlindnessEffect_Implementation(float Magnitude, float Length, float FadeOutLength)
{
	CameraEffects->AddBlindnessEffect(Magnitude, Length);
}

void AALSXTCharacterAdvanced::ResetBlindnessEffect_Implementation()
{
	CameraEffects->ResetBlindnessEffect();
}

void AALSXTCharacterAdvanced::AddProjectileFlyByEffect_Implementation(USoundBase* Sound, FVector Location, FRotator Rotation)
{
	//
}

void AALSXTCharacterAdvanced::AddConcussionEffect_Implementation(float Magnitude, float Length, float FadeInLength, float FadeOutLength)
{
	CameraEffects->AddConcussionEffect(Magnitude, Length);
}

void AALSXTCharacterAdvanced::ResetConcussionEffect_Implementation()
{
	CameraEffects->ResetConcussionEffect();
}

void AALSXTCharacterAdvanced::AddDamageEffect_Implementation(float Damage, const FGameplayTag& DamageType, const FHitResult& HitResult, float PostDelay)
{
	CameraEffects->AddDamageEffect(Damage, PostDelay);
}

void AALSXTCharacterAdvanced::ResetDamageEffect_Implementation()
{
	CameraEffects->ResetDamageEffect();
}

void AALSXTCharacterAdvanced::AddNearDeathEffect_Implementation(float Damage, const FGameplayTag& DamageType)
{
	//
}

void AALSXTCharacterAdvanced::ResetNearDeathEffect_Implementation()
{
	//
}

void AALSXTCharacterAdvanced::AddDeathEffect_Implementation(float Damage, const FGameplayTag& DamageType, const FHitResult& HitResult, float PostDelay)
{
	//
}

void AALSXTCharacterAdvanced::ResetDeathEffect_Implementation()
{
	//
}

//Head Look At Interface
void AALSXTCharacterAdvanced::IsInFrontOf_Implementation(bool& IsInFrontOf, FVector LookAtActorLocation) const
{
	IsInFrontOf = FVector::DotProduct(LookAtActorLocation, ALSXTMesh->GetForwardVector()) < 0.0f;
}

//Combat Interface
FALSXTGeneralCombatSettings AALSXTCharacterAdvanced::GetGeneralCombatSettings_Implementation()
{
	return ALSXTAdvancedSettings->Combat;
}

FALSXTCombatAttackTraceSettings AALSXTCharacterAdvanced::GetCombatAttackTraceSettings_Implementation()
{
	return Combat->CurrentAttackTraceSettings;
}

void AALSXTCharacterAdvanced::BeginCombatAttackCollisionTrace_Implementation(FALSXTCombatAttackTraceSettings TraceSettings)
{
	Combat->BeginAttackCollisionTrace(TraceSettings);
}

void AALSXTCharacterAdvanced::EndCombatAttackCollisionTrace_Implementation()
{
	Combat->EndAttackCollisionTrace();
}