#pragma once

#include "Job.h"
#include "Status.h"

class Novice : public Job
{
public:
	Novice()
		:Job (
			JobType::Novice,
			"Novice",
			Status(
				50, 0, 0,
				3, 1, 1,
				0, 0, 0, 0
			)
		)
	{}
	virtual ~Novice() {}

private:
	virtual void Strike(int& PlayerMp);
};