#include "Player.h"

#include <iostream>
#include <cstdio>
#include <string>

#include "Job.h"
#include "Actor.h"
#include "Status.h"
#include "Constants.h"
#include "Utilities.h"

int Player::MyTurn(Actor* Target)
{
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
			if (!UseSkill(Target))
			{
				continue;
			}
			return InputNumber;
		case 3:
			return InputNumber;
		default:
			break;
		}
	}
}

bool Player::UseSkill(Actor* Target)
{
	int InputNumber = 0;
	while (true)
	{
		printf("어떤 스킬을 사용할까?\n");
		int SkillListSize = CurrentJob->SkillList.size();
		for (int i = 0; i < SkillListSize; ++i)
		{
			printf("%d. %s\n", i + 1, CurrentJob->SkillList[i].first.c_str());
		}
		printf("%d. 뒤로\n", SkillListSize + 1);
		printf(">>> ");
		std::cin >> InputNumber;
		printf("\n");

		if (InputNumber > SkillListSize + 1 || InputNumber < FIRST_NUMBER)
		{
			continue;
		}

		if (InputNumber == SkillListSize + 1)
		{
			return false;
		}

		break;
	}
	auto& Skill = CurrentJob->SkillList[InputNumber - FIRST_NUMBER].second;

	return Skill(this, Target);
}

void Player::Die(Actor* Attacker)
{
	printf("[%s] %s 의 공격으로 사망했습니다.\n", Name.c_str(), Attacker->GetName().c_str());
	printf("마을로 이동합니다.\n");
}

void Player::AddExp(int InExp)
{
	printf("[%s] 획득 경험치 : %4d\n", Name.c_str(), InExp);
	Stat.CurrentExp += InExp;
	while (Stat.CurrentExp >= Stat.Exp)
	{
		Stat.CurrentExp -= Stat.Exp;
		LevelUp();
	}
}

void Player::LevelUp()
{
	Level++;
	Stat.Hp += CurrentJob->GetStatus().Hp;
	SetHp(Stat.Hp);
	Stat.Exp += CurrentJob->GetStatus().Exp;
	
	Stat.Atk += CurrentJob->GetStatus().Atk;
	Stat.Def += CurrentJob->GetStatus().Def;
	Stat.Spd += CurrentJob->GetStatus().Spd;
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

void Player::EarnGold(int InGold)
{
	Gold += InGold;
	printf("[%s] 획득 골드 : %4d\n", Name.c_str(), InGold);
}

void Player::LoseGold(int LostGold)
{
	int BeforeGold = Gold;
	Gold = Clamp(Gold - LostGold, 0, Gold);
	printf("[%s] %d 만큼 소모했습니다.\n", Name.c_str(), BeforeGold - Gold);
}

void Player::PrintPlayerInfo()
{
	printf("\n");
	printf("--------------------------------------------------------------------\n");
	printf("|\t\t\t<캐릭터 상태창>\t\t\t\t |\n");
	printf("--------------------------------------------------------------------\n");
	printf("| 이름 : %22s | 직업 : %11s | 레벨 : %2d |\n", Name.c_str(), CurrentJob->GetName().c_str(), Level);
	printf("| 체력 : %3d/%3d | 마나 : %2d/%2d | 경험치 : %4d/%4d |\n",
		Stat.CurrentHp, Stat.Hp,
		Stat.CurrentMp, Stat.Mp,
		Stat.CurrentExp, Stat.Exp);
	printf("--------------------------------------------------------------------\n");
	printf("| 공격력  :  %3d | 크리 확률  :  %3d%% | 크리티컬 데미지 :  %3d%%  |\n", Stat.Atk, Stat.Crit, Stat.CritDmg);
	printf("| 방어력  :  %3d | 반격 확률  :  %3d%% |\n", Stat.Def, Stat.Counter);
	printf("| 스피드  :  %3d | 회피 확률  :  %3d%% |	골드 보유량 : %8dG  |\n", Stat.Spd, Stat.Dodge, Gold);
	printf("--------------------------------------------------------------------\n");
}

Player::Player(std::string InName, Status InStat, Job* InJob)
	:Actor(InName, InStat, 0), CurrentJob(InJob)
{
	Level = 0;
	IsPlayer = true;
	LevelUp();
}