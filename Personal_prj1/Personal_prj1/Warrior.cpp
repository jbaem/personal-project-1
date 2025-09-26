#include "Warrior.h"

#include <cstdio>

#include "Novice.h"
#include "JobData.h"
#include "Utilities.h"
#include "Actor.h"
#include "Constants.h"

bool Warrior::PowerStrike(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 2;
	Status PlayerStatus = InPlayer->GetStatus();
	if (PlayerStatus.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->GetName().c_str(), NeedMp);
		return false;
	}
	PlayerStatus.CurrentMp -= NeedMp;

	int Damage = InPlayer->CalculateDamage(POWER_STRIKE_MODIFIER);
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Power Strike");
	Target->Defense(Damage, InPlayer);

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
