#include "DungeonManager.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

#include "Monster.h"
#include "Slime.h"
#include "Goblin.h"
#include "Gnoll.h"
#include "Orc.h"
#include "Golem.h"
#include "Actor.h"
#include <utility>
#include <vector>
#include <functional>

int DungeonManager::DungeonChoice()
{
    int InputNumber = 0;
    while (true)
    {
        printf("1.  슬라임 던전\n");
        printf("2.  고블린 던전\n");
        printf("3.    놀   던전\n");
        printf("4.   오크  던전\n");
        printf("5.   골렘  던전\n");
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

    return 0;
}

void DungeonManager::GoToDungeon()
{
    const int VillageNumber = 2;
    int InputNumber = 0;
    while (DungeonInput() != VillageNumber)
    {
        Battle();
    }
}

int DungeonManager::DungeonInput()
{
    const int VillageNumber = 2;
    int InputNumber = 0;
    while (InputNumber != VillageNumber)
    {
        printf("1. 탐험\n");
        printf("2. 마을로\n");
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
}

void DungeonManager::Battle()
{
    Monster* Monster = MonsterGenerator();
    if (!Monster)
    {
        printf("적이 없습니다.\n");
        return;
    }

    std::priority_queue<Turn, std::vector<Turn>, std::greater<Turn>> PQ;
    PQ.push({ 200.0f / User->Stat.Spd, User });
    PQ.push({ 200.0f / Monster->Stat.Spd, Monster });

    while (Monster->GetCurrentHp() > 0 && User->GetCurrentHp() > 0)
    {
        float CurrentTime = PQ.top().first;
        Actor* CurrentActor = PQ.top().second;
        PQ.pop();

        if (CurrentActor->IsPlayer)
        {
            //TODO: User Choice Skill
            CurrentActor->Attack(Monster);
        }
        else
        {
            //TODO: Monster Choice Skill
            CurrentActor->Attack(User);
        }
        float NextTime = CurrentTime + 200.0f / CurrentActor->Stat.Spd;
        PQ.push({ NextTime, CurrentActor });
    }
    PQ = {};
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

