#include "Warrior.h"

#include <cstdio>

#include "Novice.h"
#include "JobData.h"
#include "Utilities.h"
#include "Actor.h"



bool Warrior::PowerStrike(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 2;
	if (InPlayer->Stat.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->Name.c_str(), NeedMp);
		return false;
	}
	InPlayer->Stat.CurrentMp -= NeedMp;

	int Critical = GenerateRandomNumber(0, 99);
	int Damage = InPlayer->Stat.Atk * 2;
	if (Critical < InPlayer->Stat.Crit)
	{
		Damage = Damage * (100 + InPlayer->Stat.CritDmg) / 100;
	}
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Power Strike");
	Target->Suffer(Damage, InPlayer);

	return true;
}


Warrior::Warrior(JobType InType)
	: Novice(InType)
{
	Degree++;
	NeedLevelToNextDegree = 20;

	NextJobs = {
		JobType::Knight,
		JobType::Berserker
	};

	SkillList.push_back(
		{ "Power Strike",
			[this](Actor* InPlayer, Actor* Target) -> bool
			{
				return this->PowerStrike(InPlayer, Target);
			}
		});
}
