#pragma once

#include "Job.h"
#include <vector>

#include "JobData.h"
#include "Actor.h"

class Novice : public Job
{
public:
	bool Strike(Actor* InPlayer, Actor* Target);
	
	Novice(JobType InType);
	virtual ~Novice() {}
};