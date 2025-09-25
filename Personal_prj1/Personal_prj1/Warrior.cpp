#include "Warrior.h"
#include "Novice.h"
#include "JobData.h"
#include "Utilities.h"



bool Warrior::PowerStrike(Player* InPlayer, Monster* Target)
{
	const int NeedMp = 2;
	if (InPlayer->Stat.CurrentMp < NeedMp)
	{
		return false;
	}
	InPlayer->Stat.CurrentMp -= NeedMp;

	int Critical = GenerateRandomNumber(0, 99);
	int Damage = InPlayer->Stat.Atk * 2;
	if (Critical < InPlayer->Stat.Crit)
	{
		Damage = Damage * (100 + InPlayer->Stat.CritDmg) / 100;
	}
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Strike");
	Target->Suffer(Damage, InPlayer);

	return true;
}


Warrior::Warrior(JobType InType)
	: Novice(InType)
{
	Degree++;
	NeedLevelToNextDegree = 10;

	NextJobs = {
		JobType::Knight,
		JobType::Berserker
	};

	SkillList.push_back(
		{ "PowerStrike",
			[this](Player* InPlayer, Monster* Target) -> bool
			{
				this->PowerStrike(InPlayer, Target);
			}
		});
}
