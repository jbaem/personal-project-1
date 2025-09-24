#pragma once

#include "Actor.h"
#include "Status.h"
#include <string>

class Monster : public Actor
{
public:
	int DropGold = 0;

	Monster() = default;
	Monster(std::string InName, Status InStat)
		: Actor(InName, InStat) {}
	virtual ~Monster() {}
};
