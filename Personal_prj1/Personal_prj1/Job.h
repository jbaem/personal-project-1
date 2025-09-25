#pragma once
#include <string>

#include "Status.h"
#include "JobData.h"
#include <vector>
#include <functional>
#include <utility>
#include "Monster.h"
#include "Player.h"

class Job
{
public:
	Job(JobType InType) : Type(InType) 
	{
		Name = JobName[Type];
		GrowStatus = JobStatus[Type];
		NeedLevelToNextDegree = 0;
		Degree = 0;
	}
	virtual ~Job() {};

	JobType Type;
	std::string Name;
	Status GrowStatus;
	int NeedLevelToNextDegree = 0;
	int Degree = 0;

	std::vector<JobType> NextJobs;
	std::vector<std::pair<std::string, std::function<bool(Player*, Monster*)>>> SkillList;
};