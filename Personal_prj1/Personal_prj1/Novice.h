#pragma once

#include "Job.h"
#include <vector>

#include "JobData.h"
#include "Monster.h"
#include "Player.h"
#include <string>
#include "Status.h"

class Novice : public Job
{
public:
	bool Strike(Player* InPlayer, Monster* Target);
	
	Novice(JobType InType);
	virtual ~Novice() {}

private:
	std::vector<JobType> NextJobs;
};