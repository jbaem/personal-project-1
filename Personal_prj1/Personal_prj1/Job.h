#pragma once
#include <string>

#include "Status.h"
#include "JobData.h"

class Job
{
public:
	Job(JobType InType, std::string InName, Status& InStat)
		:Type(InType), Name(InName), GrowStatus(InStat)
	{ }
	virtual ~Job() {};

	JobType Type;
	std::string Name;
	Status& GrowStatus;
};