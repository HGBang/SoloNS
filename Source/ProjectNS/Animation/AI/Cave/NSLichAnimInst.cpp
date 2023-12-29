// Copyright Project NS


#include "NSLichAnimInst.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSLichAnimInst)

UNSLichAnimInst::UNSLichAnimInst() :
	Super(),
	AnimType(ELichAnimType::IdleAndWalk)
{
}

void UNSLichAnimInst::ChangeAnimType_Hit()
{
	Super::ChangeAnimType_Hit();

	AnimType = ELichAnimType::Hit_Front;
}
