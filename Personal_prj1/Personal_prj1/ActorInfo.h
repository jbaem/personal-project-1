#pragma once
#include <string>
#include "Status.h"

struct ActorInfo
{
	std::string Name;
	std::string JobName;
	Status Stat;

	ActorInfo(std::string InName, std::string InJobName, Status InStat)
		:Name(InName), JobName(InJobName), Stat(InStat) {}
};
