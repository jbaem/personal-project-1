#pragma once

#include <string>

#include "Actor.h"
#include "Job.h"
#include "Status.h"
#include "ActorInfo.h"
#include "JobData.h"

class Player : public Actor
{
public:
	virtual int MyTurn(Actor* Target);
	ActorInfo Info();
	void PrintPlayerInfo();
	void AddExp(int InExp);
	void LevelUp();
	Job* GetJob() const { return CurrentJob; }
	int GetGold() const { return Gold; }
	void Recovery(int InRecoveryHp);
	void LoseGold(int LostGold);
	int GetLevel() const { return Level; }
	int GetExp() const { return CurrentExp; }
	void EarnGold(int InGold);
	virtual void Die(Actor* Attacker);
	bool UseSkill(Actor* Target);

	Player() = default;
	Player(std::string InName, Status InStat, Job* InJob)
		:Actor(InName, InStat, 0), CurrentJob(InJob)
	{
		Level = 0;
		CurrentExp = 0;
		IsPlayer = true;
		LevelUp();
	}
	virtual ~Player() {}
	
	Job* CurrentJob;

private:
	int Level = 0;
	int CurrentExp = 0;
};

