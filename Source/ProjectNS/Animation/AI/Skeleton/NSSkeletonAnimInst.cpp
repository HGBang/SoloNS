// Copyright Project NS


#include "NSSkeletonAnimInst.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSSkeletonAnimInst)

UNSSkeletonAnimInst::UNSSkeletonAnimInst() :
	Super(),
	AnimType(ESkeletonAnimType::IdleAndWalk_Normal)
{
}

void UNSSkeletonAnimInst::ChangeAnimType_Hit()
{
	Super::ChangeAnimType_Hit();

	AnimType = ESkeletonAnimType::Hit_Front;
}
