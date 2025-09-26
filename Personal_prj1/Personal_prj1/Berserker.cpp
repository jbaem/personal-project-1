#include "Berserker.h"
#include "Utilities.h"
#include <cstdio>
#include <climits>
#include "Warrior.h"
#include "Actor.h"

bool Berserker::FinishStrike(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 3;
	if (InPlayer->Stat.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->Name.c_str(), NeedMp);
		return false;
	}
	InPlayer->Stat.CurrentMp -= NeedMp;

	int Critical = GenerateRandomNumber(0, 99);
	int Damage = InPlayer->Stat.Atk * 3;
	if (Critical < InPlayer->Stat.Crit)
	{
		Damage = Damage * (100 + InPlayer->Stat.CritDmg) / 100;
	}
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Finish Strike");
	Target->Suffer(Damage, InPlayer);

	return true;
}

bool Berserker::RageBlade(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 4;
	if (InPlayer->Stat.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->Name.c_str(), NeedMp);
		return false;
	}
	InPlayer->Stat.CurrentMp -= NeedMp;

	printf("[%s] 이번 턴에 크리티컬 확률 및 크리티컬 데미지 30%% 증가\n", InPlayer->Name.c_str());
	InPlayer->Stat.Crit += 30;
	InPlayer->Stat.CritDmg += 30;

	int Critical = GenerateRandomNumber(0, 99);
	int Damage = InPlayer->Stat.Atk * 4;
	if (Critical < InPlayer->Stat.Crit)
	{
		Damage = Damage * (100 + InPlayer->Stat.CritDmg) / 100;
	}
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Rage Blade");
	Target->Suffer(Damage, InPlayer);

	InPlayer->Stat.Crit -= 30;
	InPlayer->Stat.CritDmg -= 30;

	return true;
}

Berserker::Berserker(JobType InType)
	: Warrior(InType)
{
	Degree++;
	NeedLevelToNextDegree = INT_MAX;

	NextJobs = {

	};

	SkillList.push_back(
		{ "Finish Strike",
			[this](Actor* InPlayer, Actor* Target) -> bool
			{
				return this->FinishStrike(InPlayer, Target);
			}
		}
	);

	SkillList.push_back(
		{ "Rage Blade",
			[this](Actor* InPlayer, Actor* Target) -> bool
			{
				return this->RageBlade(InPlayer, Target);
			}
		}
	);
}