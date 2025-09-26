#include "Berserker.h"
#include "Utilities.h"
#include <cstdio>
#include <climits>
#include "Warrior.h"
#include "Actor.h"
#include "Constants.h"

bool Berserker::FinishStrike(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 3;
	Status PlayerStatus = InPlayer->GetStatus();
	if (PlayerStatus.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->GetName().c_str(), NeedMp);
		return false;
	}
	PlayerStatus.CurrentMp -= NeedMp;

	int Damage = InPlayer->CalculateDamage(FINISH_STRIKE_MODIFIER);
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Finish Strike");
	Target->Defense(Damage, InPlayer);

	return true;
}

bool Berserker::RageBlade(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 4;
	Status PlayerStatus = InPlayer->GetStatus();
	if (PlayerStatus.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->GetName().c_str(), NeedMp);
		return false;
	}
	PlayerStatus.CurrentMp -= NeedMp;

	printf("[%s] 이번 턴에 크리티컬 확률 및 크리티컬 데미지 30%% 증가\n", InPlayer->GetName().c_str());
	PlayerStatus.Crit += 30;
	PlayerStatus.CritDmg += 30;

	int Damage = InPlayer->CalculateDamage(RAGE_BLADE_MODIFIER);
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Rage Blade");
	Target->Defense(Damage, InPlayer);

	PlayerStatus.Crit -= 30;
	PlayerStatus.CritDmg -= 30;

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