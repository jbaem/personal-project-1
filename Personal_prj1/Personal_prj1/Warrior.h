#pragma once

#include <vector>
#include "Novice.h"
#include "JobData.h"
#include "Job.h"

class Warrior : public Novice
{
public:
	bool PowerStrike(Player* InPlayer, Monster* Target);
	
	Warrior(JobType InType);
	virtual ~Warrior() {}

private:
	std::vector<JobType> NextJobs;
};