#include "DungeonManager.h"

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

#include "Monster.h"
#include "Slime.h"
#include "Goblin.h"
#include "Gnoll.h"
#include "Orc.h"
#include "Golem.h"
#include "Actor.h"
#include <utility>
#include "Utilities.h"
#include "ActorInfo.h"
#include "Status.h"

void DungeonManager::DungeonChoice()
{
    int InputNumber = 0;
    while (true)
    {
        printf("--------------------------------------------------------------------\n");
        printf("\n\t\t\t<던전 선택>\n\n");
        printf("어떤 던전으로 가야하지? 너무 어려운 던전은 공략하기 힘들어!\n");
        printf("1.  슬라임 던전 (Lv. 1)\n");
        printf("2.  고블린 던전 (Lv. 5)\n");
        printf("3.    놀   던전 (Lv.10)\n");
        printf("4.   오크  던전 (Lv.15)\n");
        printf("5.   골렘  던전 (Lv.20)\n");
        printf("\n>>> ");

        std::cin >> InputNumber;
        switch (InputNumber)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            CurrentDungeon = InputNumber;
            GoToDungeon();
            return;
        default:
            break;
        }
    }
}

void DungeonManager::GoToDungeon()
{
    const int MonsterSpawnRate = 80;
    const int VillageNumber = 2;
    int InputNumber = 0;
    while (DungeonInput() != VillageNumber && User->GetCurrentHp() > 0)
    {
        int CurrentEvent = GenerateRandomNumber(0, 99);
        if (CurrentEvent < MonsterSpawnRate)
        {
            printf("몬스터를 만났다!\n");
            Battle();
        }
        else
        {
            printf("몬스터를 만나지 못했다!.\n");
        }
    }
}

int DungeonManager::DungeonInput()
{
    const int VillageNumber = 2;
    int InputNumber = 0;
    while (InputNumber != VillageNumber)
    {
        User->PrintPlayerInfo();
        printf("--------------------------------------------------------------------\n");
        printf("\n\t\t\t<던전>\n\n");
        printf("어떻게 할래?\n");
        printf("1. 앞으로 나아가기 (몬스터를 만난다.)\n");
        printf("2. 마을로\n");

        printf("\n>>> ");
        std::cin >> InputNumber;
        switch (InputNumber)
        {
        case 1:
        case 2:
            return InputNumber;
        default:
            break;
        }
    }
    return 0;
}

void DungeonManager::Battle()
{
    Monster* CurrentMonster = MonsterGenerator();
    if (!CurrentMonster)
    {
        printf("적이 없습니다.\n");
        return;
    }

    //std::priority_queue<Turn, std::vector<Turn>, std::greater<Turn>> PQ;
    std::priority_queue<Turn, std::vector<Turn>, Comparator> PQ;
    PQ.push(std::make_pair( 200.0f / User->Stat.Spd, User ));
    PQ.push(std::make_pair( 200.0f / CurrentMonster->Stat.Spd, CurrentMonster ));

    int TurnCount = 1;
    while (CurrentMonster->GetCurrentHp() > 0 && User->GetCurrentHp() > 0)
    {
        User->PrintPlayerInfo();
        CurrentMonster->PrintMonsterInfo();
        printf("\n\t\t\t<%d 번째 턴>\n\n", TurnCount);

        float CurrentTime = PQ.top().first;
        Actor* CurrentActor = PQ.top().second;
        PQ.pop();

        int BattleChoice = 0;
        if (CurrentActor->IsPlayer)
        {
            BattleChoice = CurrentActor->MyTurn(CurrentMonster);
        }
        else
        {
            BattleChoice = CurrentActor->MyTurn(User);
        }
        printf("\n");

        if (BattleChoice == 3)
        {
            printf("[%s] 도망쳤습니다.\n", CurrentActor->Name.c_str());
            break;
        }

        float NextTime = CurrentTime + 200.0f / CurrentActor->Stat.Spd;
        PQ.push({ NextTime, CurrentActor });
        
        TurnCount++;
    }
    PQ = {};

    if (User->GetCurrentHp() <= 0)
    {
        User->Die(CurrentMonster);
    }

    if (CurrentMonster->GetCurrentHp() <= 0)
    {
        CurrentMonster->Die(User);
        
        User->AddExp(CurrentMonster->Stat.Exp);
        User->EarnGold(CurrentMonster->Gold);
    }

    delete CurrentMonster;
    CurrentMonster = nullptr;
    return;
}

Monster* DungeonManager::MonsterGenerator()
{
    switch (CurrentDungeon)
    {
    case 1:
        return new Slime();
    case 2:
        return new Goblin();
    case 3:
        return new Gnoll();
    case 4:
        return new Orc();
    case 5:
        return new Golem();
    default:
        break;
    }
    return nullptr;
}

