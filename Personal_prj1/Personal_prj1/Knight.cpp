#include "Knight.h"

#include <cstdio>

#include "JobData.h"
#include "Actor.h"
#include "Warrior.h"
#include "Utilities.h"
#include "Constants.h"

bool Knight::ShieldAttack(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 2;
	Status PlayerStatus = InPlayer->GetStatus();
	if (PlayerStatus.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->GetName().c_str(), NeedMp);
		return false;
	}

	PlayerStatus.CurrentMp -= NeedMp;
	
	printf("[%s] 이번 턴에 반격 확률 30%% 증가\n", InPlayer->GetName().c_str());
	PlayerStatus.Counter += 30;

	int Damage = InPlayer->CalculateDamage(SHIELD_ATTACK_MODIFIER);
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Shield Attack");
	Target->Defense(Damage, InPlayer);

	PlayerStatus.Counter -= 30;

	return true;
}

bool Knight::DivineShieldAttack(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 4;
	Status PlayerStatus = InPlayer->GetStatus();
	if (PlayerStatus.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->GetName().c_str(), NeedMp);
		return false;
	}
	PlayerStatus.CurrentMp -= NeedMp;

	printf("[%s] 이번 턴에 반격 확률 50%% 증가\n", InPlayer->GetName().c_str());
	PlayerStatus.Counter += 50;

	int Damage = InPlayer->CalculateDamage(DIVINE_SHIELD_ATTACK_MODIFIER);
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Devine Shield Attack");
	Target->Defense(Damage, InPlayer);

	PlayerStatus.Counter -= 50;

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
		{ "Divine Shield Attack",
			[this](Actor* InPlayer, Actor* Target) -> bool
			{
				return this->DivineShieldAttack(InPlayer, Target);
			}
		}
	);
}
