#pragma once

#include <string>

#include "Actor.h"
#include "Job.h"

class Player : public Actor
{
public:
	virtual void Attack();
	virtual void Suffer();

	void Info();
	void AddExp(int InExp);
	void LevelUp();

	Player();
	Player(std::string InName, Job* InJob)
		:Name(InName), Actor()
	{
		LevelUp();
	}
	virtual ~Player();
	

private:
	std::string Name;
	int Level = 0;
	Job* Class;

	int BaseHp = 50;
	int BaseMp = 0;
	int BaseExp = 0;
		
	int BaseAtk = 10;
	int BaseDef = 5;
	int BaseSpd = 5;
		
	int BaseCounter = 10;
	int BaseDodge = 20;
	int BaseCrit = 10;
};

