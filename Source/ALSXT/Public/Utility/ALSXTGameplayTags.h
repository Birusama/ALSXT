#pragma once

#include "NativeGameplayTags.h"

namespace AlsOverlayModeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BuildingPlan)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Flashlight)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AxeOneHanded)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AxeTwoHanded)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Pickaxe)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Knife)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Hammer)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Sword)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Katana)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Grenade)
}

namespace AlsLocomotionActionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CrowdNavigationReaction)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(DefensiveReaction)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ImpactReaction)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ClutchImpactPoint)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SyncedAttackReaction)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ImpactFall)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ImpactFallLand)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ImpactGetUp)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ImpactResponse)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ThrowDefault)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Vaulting)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Sliding)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Acrobatic)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WallJumping)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WallRunning)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Emote)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(EnteringStationary)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ExitingStationary)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PrimaryAction)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SecondaryAction)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PrimaryInteraction)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SecondaryInteraction)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(EquipingItem)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UnequipingItem)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InspectHeldItem)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Reloading)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TogglingFireMode)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TogglingFirearmStance)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Charging)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FixingMalfunction1)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FixingMalfunction2)
}

namespace ALSXTLeanDirectionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Left)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Right)
}

namespace ALSXTActionTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Primary)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Secondary)
}

namespace ALSXTActionStanceTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Prone)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Crouched)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Standing)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InAir)
}

namespace ALSXTMantleTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(High)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Low)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InAir)
}

namespace ALSXTVaultTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Low)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Medium)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(High)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Fence)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InAir)
}

namespace ALSXTAcrobaticActionTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Flip)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WallJump)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WallRun)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WallRunLeft)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WallRunRight)
}

namespace ALSXTPhysicalAnimationModeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(None)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Bump)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Hit)
}

namespace ALSXTReactionAnimationTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Impact)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(WithRecovery)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Synced)
}

namespace ALSXTFallTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Bump)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Impact)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SyncedAttack)
}

namespace ALSXTPlayerServerStateTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Loading)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InLobby)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InPreGame)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Spectating)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InGame)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Disconnected)
}

namespace ALSXTPlayerGameRoleTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(OrganizationLeader)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SectionLeader)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FireteamLeader)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Unit)
}

namespace ALSXTPlayerServerRoleTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GameMaster)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Moderator)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player)
}

namespace ALSXTFacialExpressionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(None)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Happy)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Pain)
}

namespace ALSXTSexTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Male)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Female)
}

namespace ALSXTVoiceVariantTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Default)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Variant01)
}

namespace ALSXTStatusTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Normal)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(KnockedDown)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Unconscious)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Dead)
}

namespace ALSXTFreelookingTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(False)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(True)
}

namespace ALSXTFocusedTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(False)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(True)
}

namespace ALSXTHoldingBreathTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(False)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(True)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Released)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Exhausted)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Gasping)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Coughing)
}

namespace ALSXTCursorLocationTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ScreenCenter)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MouseLocation)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Location)
}

namespace ALSXTObjectCollisionTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(None)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Impact)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Drag)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Roll)
}

namespace ALSXTImpactTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CrowdNavigation)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Bump)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Impact)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attack)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SyncedAttack)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Hit)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Fall)
}

namespace ALSXTImpactVelocityTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Slow)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Moderate)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Fast)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Faster)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TerminalVelocity)
}

namespace ALSXTImpactFormTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Push)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Blunt)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Blade)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Bullet)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Explosion)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Electric)
}

namespace ALSXTImpactLocationTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Head)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Neck)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(UpperTorso)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LowerTorso)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Hip)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftUpperArm)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftForearm)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftHand)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightUpperArm)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightForearm)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightHand)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftThigh)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftLowerLeg)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftFoot)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightThigh)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightLowerLeg)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightFoot)
}

namespace ALSXTImpactSideTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Front)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Back)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Left)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Right)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Hight)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Middle)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Low)
}

namespace ALSXTReboundTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(False)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(True)
}

namespace ALSXTElementalConditionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Dry)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Wet)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Doused)
}

namespace ALSXTImpactSurfaceTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cloth)
}

namespace ALSXTBloodSpatterVelocityTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(None)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Slow)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Moderate)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Fast)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TerminalVelocity)
}

namespace ALSXTBloodSpatterVolumeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Small)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Medium)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Large)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ExtraLarge)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Max)
}

namespace ALSXTBloodSpatterDistanceTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LessThanTwo)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TwoToFive)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(FiveToMax)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Max)
}

namespace ALSXTHealthTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(None)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Little)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Moderate)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Most)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(All)
}

namespace ALSXTDamageAmountTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(None)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Little)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Moderate)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Most)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(All)
}

namespace ALSXTDamageTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Impact)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Edge)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Burn)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Explosion)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Gas)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Poison)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Illness)
}

namespace ALSXTLocomotionVariantTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Default)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Exaggerated)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Style01)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Style02)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Style03)
}

namespace ALSXTInjuryTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(None)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Head)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Abdomen)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftArm)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightArm)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftLeg)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightLeg)
}

namespace ALSXTCombatStanceTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Neutral)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ready)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Aiming)
}

namespace ALSXTIdleAnimationActivityTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Neutral)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Smoking)
}

namespace ALSXTUnarmedAttackTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftFist)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightFist)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftFoot)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightFoot)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftElbow)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightElbow)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftKnee)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightKnee)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Head)
}

namespace ALSXTAttackTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftFist)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightFist)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftFoot)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightFoot)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftElbow)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightElbow)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftKnee)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightKnee)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Head)
}

namespace ALSXTWeaponFirearmStanceTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Regular)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CantedLeft)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(CantedRight)
}

namespace ALSXTWeaponCarryPositionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Concealed)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SlingChest)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SlingOffSideDrop)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SlingRearSweep)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SlingClimber)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(HolsterChest)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(HolsterHip)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(HolsterLeg)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MeleeChestSheath)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MeleeBelt)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MeleeArm)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MeleeLeg)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MeleeBack)
}


namespace ALSXTWeaponReadyPositionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(None)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Carry)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PatrolReady)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LowReady)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(HighReady)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Sul)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AroundCover)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Retention)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Hip)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ready)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Aiming)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Hidden)
}

namespace ALSXTDefensiveModeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(None)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Avoiding)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Anticipation)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Blocking)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ClutchImpactPoint)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BraceForImpact)
}

namespace ALSXTBlockingTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(NotBlocking)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Blocking)
}

namespace ALSXTStationaryModeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Static)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Interaction)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(VehicleDriver)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(VehiclePassenger)
}

namespace ALSXTStaticStationaryModeTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Seat)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Surface)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ground)
}

namespace ALSXTVehicleStationaryModeTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Driver)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Passenger)
}

namespace ALSXTVehicleSeatSideTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Left)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Right)
}

namespace ALSXTEmoteTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RunningMan)
}

namespace ALSXTGestureTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Point)
}

namespace ALSXTHandTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Left)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Right)
}

namespace ALSXTWeaponObstructionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Environment)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Flagging)
}

namespace ALSXTStaminaTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Full)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Optimal)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Half)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Low)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Empty)
}

namespace ALSXTActionStrengthTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Light)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Medium)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Heavy)
}

namespace ALSXTAttackMethodTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cancelled)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Regular)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Riposte)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Unique)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Grapple)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Throw)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(KnockOut)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TakeDown)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cybernetic)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Device)
}

namespace ALSXTDefenseTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Regular)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Parry)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Dodge)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Redirection)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cybernetic)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Device)
}

namespace ALSXTItemConditionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Prestine)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Good)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Worn)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Ruined)
}

namespace ALSXTClothingStateTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(HoodUp)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Open)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Closed)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Tucked)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(LeftSleeveUp)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(RightSleeveUp)
}

namespace ALSXTGripPositionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Default)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Underbarrel)
}

namespace ALSXTForegripPositionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Default)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MagazineWell)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(VerticalGrip)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AngledForeGrip)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TopHorizontalGrip)
}

namespace ALSXTCharacterMovementSoundTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Walking)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Running)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Sprinting)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Jumping)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Crouch)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Uncrouch)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(GettingUp)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Sliding)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Equip)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Unequip)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ChangeCombatStance)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Impact)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Blocking)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ChangeWeaponReadyPosition)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ChangeGripPosition)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ChangeForegripPosition)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ChangeSightPosition)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Gesture)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MantlingLow)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MantlingHigh)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Vaulting)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Leaning)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Flip)
}

namespace ALSXTObjectWeightTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Stealth)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(VeryLight)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Light)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Default)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Heavy)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(VeryHeavy)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ExtremelyHeavy)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(MassivelyHeavy)
}

namespace ALSXTWeaponTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(M4)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Pistol)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(PistolTwoHanded)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Knife)
}

namespace ALSXTWeaponActionTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Reloading)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cycling)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InpectingMagazine)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InspectingChamber)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(ClearingJam)
}

namespace ALSXTMotionSoundAreaTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Upper)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Lower)
}

namespace ALSXTBreathTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Regular)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Coughing)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Cold)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Injured)
}

namespace ALSXTMeshPaintTypeTags
{
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BloodDamage)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(SurfaceDamage)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(BackSpatter)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Saturation)
	ALSXT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Burn)
}