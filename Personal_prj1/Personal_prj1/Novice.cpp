#include "Novice.h"
#include "Player.h"
#include "Monster.h"
#include <string>
#include <cstdio>

#include "Job.h"
#include "JobData.h"
#include "Status.h"
#include "Utilities.h"

bool Novice::Strike(Player* InPlayer, Monster* Target)
{
	const int NeedMp = 1;
	if (InPlayer->Stat.CurrentMp < NeedMp)
	{
		return false;
	}
	InPlayer->Stat.CurrentMp -= NeedMp;

	int Critical = GenerateRandomNumber(0, 99);
	int Damage = InPlayer->Stat.Atk * 1.5;
	if (Critical < InPlayer->Stat.Crit)
	{
		Damage = Damage * (100 + InPlayer->Stat.CritDmg) / 100;
	}
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Strike");
	Target->Suffer(Damage, InPlayer);

	return true;
}

Novice::Novice(JobType InType)
	:Job(InType)
{
	Degree++;
	NeedLevelToNextDegree = 5;

	NextJobs = {
		JobType::Warrior
	};

	SkillList.push_back(
		{ "Strike",
			[this](Player* InPlayer, Monster* Target) -> bool
			{
				this->Strike(InPlayer, Target);
			}
		});
}

