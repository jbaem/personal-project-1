#pragma once

#include <string>

#include "Actor.h"
#include "Job.h"
#include "Status.h"
#include "ActorInfo.h"

class Player : public Actor
{
public:
	virtual int MyTurn(Actor* Target) override;

	virtual bool UseSkill(Actor* Target) override;
	virtual void Die(Actor* Attacker) override;
	
	void AddExp(int InExp);
	void LevelUp();
	void Recovery(int InRecoveryHp);
	void EarnGold(int InGold);
	void LoseGold(int LostGold);
	
	Job* GetJob() const { return CurrentJob; }
	int GetLevel() const { return Level; }
	int GetGold() const { return Gold; }
	int GetExp() const { return Stat.CurrentExp; }

	ActorInfo Info();
	void PrintPlayerInfo();

private:
	int Level = 0;
	Job* CurrentJob;

public:
	Player(std::string InName, Status InStat, Job* InJob);
	virtual ~Player() {}
};

