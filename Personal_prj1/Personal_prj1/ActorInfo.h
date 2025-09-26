#pragma once
#include <string>

#include "Status.h"

struct ActorInfo
{
	std::string Name = "";
	std::string JobName = "";
	int Level = 0;
	int Gold = 0;
	Status Stat = Status();

	ActorInfo(std::string InName, std::string InJobName, int InLevel, int InGold, Status InStat)
		:Name(InName), JobName(InJobName), Level(InLevel), Gold(InGold), Stat(InStat) {}
};

