#pragma once

#include "Warrior.h"
#include "JobData.h"
#include "Actor.h"

class Knight : public Warrior
{
public:
	bool ShieldAttack(Actor* InPlayer, Actor* Target);
	bool DivineShieldAttack(Actor* InPlayer, Actor* Target);

public:
	Knight(JobType InType);
	virtual ~Knight() {}
};