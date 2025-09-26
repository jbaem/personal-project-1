#pragma once

#include "NPC.h"
#include "Player.h"
#include <string>
#include "Job.h"
#include "JobData.h"

class Instructor : public NPC
{
public:
	virtual void Talk(Player* InPlayer) override;
	void ClassUp(Player* InPlayer);
	Job* MatchJob(JobType InType);


private:
	std::string Name = "Instructor";

public:
	Instructor() = default;
	virtual ~Instructor() {}
};

