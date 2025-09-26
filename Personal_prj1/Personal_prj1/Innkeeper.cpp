#include "Innkeeper.h"

#include <cstdio>
#include <iostream>

#include "Player.h"
#include "Constants.h"

void Innkeeper::Talk(Player* InPlayer)
{
	const int NeedGold = RECOVERY_GOLD_RATE * InPlayer->GetLevel();
	
	int InputNumber = 0;
	while (true)
	{
		printf("[%s] 자고 가려면 %d 필요합니다.\n", Name.c_str(), NeedGold);
		printf("1. 체력 회복\n");
		printf("2. 돌아가기\n");
		printf(">>> ");
		std::cin >> InputNumber;

		switch (InputNumber)
		{
		case 1:
			Heal(InPlayer, NeedGold);
			printf("[%s] 상쾌해진 기분으로 여관을 나왔습니다.\n", InPlayer->GetName().c_str());
			return;
		case 2:
			printf("[%s] 아직 쉬고 싶지 않습니다.\n", InPlayer->GetName().c_str());
			return;
		default:
			break;
		}
	}
}

void Innkeeper::Heal(Player* InPlayer, const int InNeedGold)
{
	if (InPlayer->GetGold() < InNeedGold)
	{
		printf("\n돈이 부족하여 마구간에서 자고자 합니다.\n");
		printf("[%s] 넓은 아량으로 허락해줬습니다.\n\n", Name.c_str());
	}
	
	InPlayer->LoseGold(InNeedGold);
	InPlayer->Recovery(InPlayer->GetStatus().Hp);
}
