#include "Knight.h"
#include "JobData.h"
#include "Actor.h"
#include "Warrior.h"
#include "Utilities.h"
#include <cstdio>

bool Knight::ShieldAttack(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 2;
	if (InPlayer->Stat.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->Name.c_str(), NeedMp);
		return false;
	}
	InPlayer->Stat.CurrentMp -= NeedMp;

	printf("[%s] 이번 턴에 반격 확률 30%% 증가\n", InPlayer->Name.c_str());
	InPlayer->Stat.Counter += 30;

	int Critical = GenerateRandomNumber(0, 99);
	int Damage = static_cast<int>(InPlayer->Stat.Atk * 2.5);
	if (Critical < InPlayer->Stat.Crit)
	{
		Damage = Damage * (100 + InPlayer->Stat.CritDmg) / 100;
	}
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Shield Attack");
	Target->Suffer(Damage, InPlayer);

	InPlayer->Stat.Counter -= 30;

	return true;
}

bool Knight::DevineShieldAttack(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 4;
	if (InPlayer->Stat.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->Name.c_str(), NeedMp);
		return false;
	}
	InPlayer->Stat.CurrentMp -= NeedMp;

	printf("[%s] 이번 턴에 반격 확률 50%% 증가\n", InPlayer->Name.c_str());
	InPlayer->Stat.Counter += 50;

	int Critical = GenerateRandomNumber(0, 99);
	int Damage = InPlayer->Stat.Atk * 4;
	if (Critical < InPlayer->Stat.Crit)
	{
		Damage = Damage * (100 + InPlayer->Stat.CritDmg) / 100;
	}
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Devine Shield Attack");
	Target->Suffer(Damage, InPlayer);

	InPlayer->Stat.Counter -= 50;

	return true;
}

Knight::Knight(JobType InType)
	:Warrior(InType)
{
	Degree++;
	NeedLevelToNextDegree = INT_MAX;

	NextJobs = {

	};

	SkillList.push_back(
		{ "Shield Attack",
			[this](Actor* InPlayer, Actor* Target) -> bool
			{
				return this->ShieldAttack(InPlayer, Target);
			}
		}
	);

	SkillList.push_back(
		{ "Devine Shield Attack",
			[this](Actor* InPlayer, Actor* Target) -> bool
			{
				return this->DevineShieldAttack(InPlayer, Target);
			}
		}
	);
}
