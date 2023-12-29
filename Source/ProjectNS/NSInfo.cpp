// Copyright Project NS


#include "NSInfo.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(NSInfo)
DEFINE_LOG_CATEGORY(NS_Log)

#define UE_LOGFMT_LOG(Format, ...) UE_LOGFMT(NS_Log, Log, "{Func} : {Call}", __FUNCTION__, Format UE_PRIVATE_LOGFMT_FIELDS(__VA_ARGS__))

FNSItemInfo::FNSItemInfo()
	: Super()
	, Name()
	, Amount(0)
	, Description()
	, Icon(nullptr)
	, Valid(false)
{
}

void FNSItemInfo::SetName(const FText& InName)
{
	Name = InName;
}

void FNSItemInfo::SetAmount(int32 InAmount)
{
	Amount = InAmount;
}

void FNSItemInfo::SetDescription(const FText& InDescription)
{
	Description = InDescription;
}

void FNSItemInfo::SetIcon(UTexture2D* InIcon)
{
	Icon = InIcon;
}

void FNSItemInfo::SetValid(bool IsValid)
{
	Valid = IsValid;
}

void FNSItemInfo::AddAmount(int32 InAmount)
{
	Amount += InAmount;
}