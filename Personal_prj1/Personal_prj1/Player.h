#pragma once

#include <string>

#include "Actor.h"
#include "Job.h"
#include "Status.h"
#include "ActorInfo.h"

class Player : public Actor
{
public:
	ActorInfo Info();
	void AddExp(int InExp);
	void LevelUp();
	Job* ClassUp();

	Player() = default;
	Player(std::string InName, Status InStat, Job* InJob)
		:Actor(InName, InStat), CurrentJob(InJob)
	{
		IsPlayer = true;
		LevelUp();
	}
	virtual ~Player() {}
	

private:
	int Level = 0;
	int CurrentExp = 0;
	Job* CurrentJob;
	Status* TempStat = nullptr;
};

