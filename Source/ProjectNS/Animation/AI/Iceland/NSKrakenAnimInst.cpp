// Copyright Project NS


#include "NSKrakenAnimInst.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSKrakenAnimInst)

UNSKrakenAnimInst::UNSKrakenAnimInst() :
	Super(),
	AnimType(EKrakenAnimType::Idle)
{
}

void UNSKrakenAnimInst::ChangeAnimType_Hit()
{
	Super::ChangeAnimType_Hit();

	AnimType = EKrakenAnimType::Hit_Front;
}
