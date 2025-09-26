#include "Monster.h"

#include <cstdio>

#include "Status.h"
#include "Actor.h"

//float RandomFactor = 0.9f + ((static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 0.2f);

int Monster::MyTurn(Actor* Target)
{
    if (Stat.CurrentMp < SkillMana)
    {
        Attack(Target);
    }
    else
    {
        UseSkill(Target);
        Stat.CurrentMp -= SkillMana;
    }
    return 0;
}

bool Monster::UseSkill(Actor* Target)
{
    printf("스킬 사용\n");
    return false;
}

void Monster::Die(Actor* Attacker)
{
    printf("[%s] %s 의 공격으로 사망했습니다.\n", Name.c_str(), Attacker->GetName().c_str());
}

void Monster::PrintMonsterInfo()
{
    printf("\n");
    printf("--------------------------------------------------------------------\n");
    printf("|\t\t\t<몬스터 상태창>\t\t\t\t |\n");
    printf("--------------------------------------------------------------------\n");
    printf("| 이름 : %22s |\n", Name.c_str());
    printf("| 체력 : %3d/%3d | 마나 : %2d/%2d |\n",
        Stat.CurrentHp, Stat.Hp,
        Stat.CurrentMp, Stat.Mp);
    printf("--------------------------------------------------------------------\n");
    printf("| 공격력  :  %3d | 크리 확률  :  %3d%% | 크리티컬 데미지 :  %3d%%  |\n", Stat.Atk, Stat.Crit, Stat.CritDmg);
    printf("| 방어력  :  %3d | 반격 확률  :  %3d%% |\n", Stat.Def, Stat.Counter);
    printf("| 스피드  :  %3d | 회피 확률  :  %3d%% |\n", Stat.Spd, Stat.Dodge);
    printf("--------------------------------------------------------------------\n");
}
