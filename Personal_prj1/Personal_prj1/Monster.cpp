#include "Monster.h"

#include <cstdlib>

#include "Status.h"
#include "Actor.h"
#include "ActorInfo.h"
#include <cstdio>

//float RandomFactor = 0.9f + ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 0.2f);

ActorInfo Monster::Info()
{
	return {
		Name,
		"Null",
		0,
		Gold,
		Stat
	};
}

void Monster::PrintMonsterInfo()
{
    ActorInfo OutInfo = Info();
    Status OutStat = OutInfo.Stat;

    printf("\n");
    printf("--------------------------------------------------------------------\n");
    printf("|\t\t\t<몬스터 상태창>\t\t\t\t |\n");
    printf("--------------------------------------------------------------------\n");
    printf("| 이름 : %22s |\n", OutInfo.Name.c_str());
    printf("| 체력 : %3d/%3d | 마나 : %2d/%2d |\n",
        OutStat.CurrentHp, OutStat.Hp,
        OutStat.CurrentMp, OutStat.Mp);
    printf("--------------------------------------------------------------------\n");
    printf("| 공격력  :  %3d | 크리 확률  :  %3d%% | 크리티컬 데미지 :  %3d%%  |\n", OutStat.Atk, OutStat.Crit, OutStat.CritDmg);
    printf("| 방어력  :  %3d | 반격 확률  :  %3d%% |\n", OutStat.Def, OutStat.Counter);
    printf("| 스피드  :  %3d | 회피 확률  :  %3d%% |\n", OutStat.Spd, OutStat.Dodge);
    printf("--------------------------------------------------------------------\n");
}

int Monster::MyTurn(Actor* Target)
{
    Stat.CurrentMp++;
    if (Stat.CurrentMp < SkillMana)
    {
        Attack(Target);
        return 1;
    }
    else
    {
        return 2;
    }
}

void Monster::Die(Actor* Attacker)
{
    printf("[%s] %s 의 공격으로 사망했습니다.\n", Name.c_str(), Attacker->Name.c_str());
}