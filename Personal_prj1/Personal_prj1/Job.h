#pragma once

#include <string>
#include <vector>
#include <functional>
#include <utility>

#include "Status.h"
#include "JobData.h"
#include "Actor.h"

class Job
{
public:
	std::string GetName() const { return Name; }
	Status GetStatus() const { return GrowStatus; }
	int GetDegree() const { return Degree; }
	int GetNeedLevel() const { return NeedLevelToNextDegree; }

	std::vector<JobType> NextJobs;
	std::vector<std::pair<std::string, std::function<bool(Actor*, Actor*)>>> SkillList;

protected:
	JobType Type;
	std::string Name;
	Status GrowStatus;
	int NeedLevelToNextDegree = 0;
	int Degree = 0;

public:
	Job(JobType InType)
		: Type(InType) 
	{
		Name = JobName[Type];
		GrowStatus = JobStatus[Type];
		NeedLevelToNextDegree = 0;
		Degree = 0;
	}
	virtual ~Job() {};
};