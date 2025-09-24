#include "Player.h"
#include "ActorInfo.h"
#include "Job.h"

ActorInfo Player::Info()
{
	return ActorInfo(
		Name,
		CurrentJob->Name,
		TempStat
	);
}

void Player::AddExp(int InExp)
{
	CurrentExp += InExp;
	if (CurrentExp > Stat->Exp)
	{
		CurrentExp -= Stat->Exp;
		LevelUp();
	}
}

void Player::LevelUp()
{
	Level++;
	Stat->Hp += CurrentJob->Stat->Hp;
	Stat->Exp += CurrentJob->Stat->Exp;
	
	Stat->Atk += CurrentJob->Stat->Atk;
	Stat->Def += CurrentJob->Stat->Def;
	Stat->Spd += CurrentJob->Stat->Spd;
}

Job* Player::ClassUp()
{


	return CurrentJob;
}
