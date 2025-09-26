#include "Novice.h"

#include <string>
#include <cstdio>
#include <vector>

#include "Job.h"
#include "JobData.h"
#include "Status.h"
#include "Utilities.h"
#include "Actor.h"

bool Novice::Strike(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 1;
	if (InPlayer->Stat.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->Name.c_str(), NeedMp);
		return false;
	}
	InPlayer->Stat.CurrentMp -= NeedMp;

	int Critical = GenerateRandomNumber(0, 99);
	int Damage = static_cast<int>(InPlayer->Stat.Atk * 1.5);
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
	NeedLevelToNextDegree = 10;


	NextJobs = { 
		JobType::Warrior 
	};

	SkillList.push_back(
		{ "Strike",
			[this](Actor* InPlayer, Actor* Target) -> bool
			{
				return this->Strike(InPlayer, Target);
			}
		});
}

