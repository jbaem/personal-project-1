#pragma once

#include <vector>

#include "Warrior.h"
#include "JobData.h"
#include "Actor.h"

class Berserker : public Warrior
{
public:
	bool FinishStrike(Actor* InPlayer, Actor* Target);
	bool RageBlade(Actor* InPlayer, Actor* Target);

public:
	Berserker(JobType InType);
	virtual ~Berserker() {}
};