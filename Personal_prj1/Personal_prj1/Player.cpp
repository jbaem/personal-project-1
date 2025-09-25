#include <cstdio>

#include <iostream>

#include "Player.h"
#include "ActorInfo.h"
#include "Job.h"
#include "Actor.h"
#include "Utilities.h"
#include "JobData.h"
#include <string>

ActorInfo Player::Info()
{
	return {
		Name,
		CurrentJob->Name,
		Level,
		Gold,
		Stat
	};
}
void Player::PrintPlayerInfo()
{
	ActorInfo OutInfo = Info();
	Status OutStat = OutInfo.Stat;

	printf("--------------------------------------------------------------------\n");
	printf("|\t\t\t<캐릭터 상태창>\t\t\t\t |\n");
	printf("--------------------------------------------------------------------\n");
	printf("| 이름 : %22s | 직업 : %11s | 레벨 : %2d |\n", OutInfo.Name.c_str(), OutInfo.JobName.c_str(), OutInfo.Level);
	printf("| 체력 : %3d/%3d | 마나 : %2d/%2d | 경험치 : %4d/%4d |\n",
		OutStat.CurrentHp, OutStat.Hp,
		OutStat.CurrentMp, OutStat.Mp,
		CurrentExp, OutStat.Exp);
	printf("--------------------------------------------------------------------\n");
	printf("| 공격력  :  %3d | 크리 확률  :  %3d%% | 크리티컬 데미지 :  %3d%%  |\n", OutStat.Atk, OutStat.Crit, OutStat.CritDmg);
	printf("| 방어력  :  %3d | 반격 확률  :  %3d%% |\n", OutStat.Def, OutStat.Counter);
	printf("| 스피드  :  %3d | 회피 확률  :  %3d%% |	골드 보유량 : %8dG  |\n", OutStat.Spd, OutStat.Dodge, OutInfo.Gold);
	printf("--------------------------------------------------------------------\n");
}

int Player::MyTurn(Actor* Target)
{
	Stat.CurrentMp++;
	int InputNumber = 0;
	while (true)
	{
		printf("전투 행동을 고르자\n");
		printf("1. 일반 공격\n");
		printf("2. 스킬 공격\n");
		printf("3. 도망가기 \n");
		printf(">>> ");
		std::cin >> InputNumber;

		switch (InputNumber)
		{
		case 1:
			Attack(Target);
			return InputNumber;
		case 2:
			//TODO: 스킬 구현
			UseSkill(Target);
			return InputNumber;
		case 3:
			return InputNumber;
		default:
			break;
		}
	}
}

void Player::AddExp(int InExp)
{
	printf("[%s] 획득 경험치 : %4d\n", Name.c_str(), InExp);
	CurrentExp += InExp;
	if (CurrentExp >= Stat.Exp)
	{
		CurrentExp -= Stat.Exp;
		LevelUp();
	}
}

void Player::LevelUp()
{
	Level++;
	Stat.Hp += CurrentJob->GrowStatus.Hp;
	SetHp(Stat.Hp);

	Stat.Exp += CurrentJob->GrowStatus.Exp;
	
	Stat.Atk += CurrentJob->GrowStatus.Atk;
	Stat.Def += CurrentJob->GrowStatus.Def;
	Stat.Spd += CurrentJob->GrowStatus.Spd;
	if (Level != 1)
	{
		printf("[%s] 레벨 업!!!! [%d -> %d]\n\n", Name.c_str(), Level - 1, Level);
	}
}

void Player::Recovery(int InRecoveryHp)
{
	int BeforeHp = Stat.CurrentHp;
	SetHp(Stat.CurrentHp + InRecoveryHp);
	printf("[%s] %d 만큼 회복했습니다.\n", Name.c_str(), Stat.CurrentHp - BeforeHp);
}

void Player::LoseGold(int LostGold)
{
	int BeforeGold = Gold;
	Gold = Clamp(Gold - LostGold, 0, Gold);
	printf("[%s] %d 만큼 소모했습니다.\n", Name.c_str(), Gold - BeforeGold);
}

void Player::EarnGold(int InGold)
{
	printf("[%s] 획득 골드 : %4d\n", Name.c_str(), InGold);
	Gold += InGold;
}

void Player::Die(Actor* Attacker)
{
	printf("[%s] %s 의 공격으로 사망했습니다.\n", Name.c_str(), Attacker->Name.c_str());
	printf("마을로 이동합니다.\n");
	SetHp(1);
}

void Player::UseSkill(Actor* Target)
{
	while (true)
	{
		int InputNumber = 0;
		
		printf("어떤 스킬을 사용할까?\n");
		int SkillNumber = 0;
		while (SkillNumber < CurrentJob->SkillList.size())
		{
			printf("%d. %s\n", SkillNumber + 1, CurrentJob->SkillList[SkillNumber].first.c_str());
			SkillNumber++;
		}
		printf("%d. 뒤로\n", SkillNumber);
		std::cin >> InputNumber;

		if (InputNumber >= SkillNumber || InputNumber <= 0)
		{
			continue;
		}

		//TODO: Last Code 
		bool IsUsed = CurrentJob->SkillList[InputNumber - 1].second(*this, Target);
	}
}
