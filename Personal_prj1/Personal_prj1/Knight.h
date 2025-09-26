#pragma once

#include "Warrior.h"
#include "JobData.h"
#include "Actor.h"

class Knight : public Warrior
{
public:
	bool ShieldAttack(Actor* InPlayer, Actor* Target);
	bool DevineShieldAttack(Actor* InPlayer, Actor* Target);

	Knight(JobType InType);
	virtual ~Knight() {}
};