#include "Novice.h"

#include <string>
#include <cstdio>
#include <vector>

#include "Job.h"
#include "JobData.h"
#include "Status.h"
#include "Utilities.h"
#include "Actor.h"
#include "Constants.h"

bool Novice::Strike(Actor* InPlayer, Actor* Target)
{
	const int NeedMp = 1;
	Status PlayerStatus = InPlayer->GetStatus();
	if (PlayerStatus.CurrentMp < NeedMp)
	{
		printf("[%s] 마나가 부족하여 스킬 사용 불가 (필요마나 : %d)\n", InPlayer->GetName().c_str(), NeedMp);
		return false;
	}
	PlayerStatus.CurrentMp -= NeedMp;

	int Damage = InPlayer->CalculateDamage(STRIKE_MODIFIER);
	printf("[%s] %d 데미지로 %s 공격 시도!\n", Name.c_str(), Damage, "Strike");
	Target->Defense(Damage, InPlayer);

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

