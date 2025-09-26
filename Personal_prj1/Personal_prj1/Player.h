#pragma once

#include <string>

#include "Actor.h"
#include "Job.h"
#include "Status.h"

class Player : public Actor
{
public:
	virtual int MyTurn(Actor* Target) override;

	virtual bool UseSkill(Actor* Target) override;
	virtual void Die(Actor* Attacker) override;
	
	void InitMp() { Stat.CurrentMp = 0; }
	void AddExp(int InExp);
	void LevelUp();
	void Recovery(int InRecoveryHp);
	void EarnGold(int InGold);
	void LoseGold(int LostGold);

	inline Job* GetJob() const { return CurrentJob; }
	inline void SetJob(Job* InJob) { CurrentJob = InJob; }
	inline int GetLevel() const { return Level; }
	inline int GetExp() const { return Stat.CurrentExp; }

	void PrintPlayerInfo();


private:
	int Level = 0;
	Job* CurrentJob;

public:
	Player(std::string InName, Status InStat, Job* InJob);
	virtual ~Player() {}
};

