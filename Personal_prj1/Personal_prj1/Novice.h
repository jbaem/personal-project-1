#pragma once

#include <string>

#include "Job.h"
#include "Player.h"

class Novice : public Job
{
public:
	virtual void Strike(int& PlayerMp);

	Novice()
		:Name("Novice") { }


private:
	std::string Name;
};