#pragma once

#include <vector>
#include "Novice.h"
#include "JobData.h"
#include "Job.h"
#include "Actor.h"

class Warrior : public Novice
{
public:
	bool PowerStrike(Actor* InPlayer, Actor* Target);
	
	Warrior(JobType InType);
	virtual ~Warrior() {}
};