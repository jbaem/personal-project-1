#include "DungeonManager.h"

#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

#include "Monster.h"
#include "Slime.h"
#include "Goblin.h"
#include "Gnoll.h"
#include "Orc.h"
#include "Golem.h"
#include "Actor.h"
#include "Status.h"
#include "Constants.h"
#include "Utilities.h"

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
        printf("6.  마을로 돌아가기     \n");
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
        case 6:
            return;
        default:
            break;
        }
    }
}

void DungeonManager::GoToDungeon()
{
    int InputNumber = 0;
    while (DungeonInput() != VILLAG_NUMBER && User->GetCurrentHp() > 0)
    {
        int CurrentEvent = GenerateRandomNumber(PERCENT_MIN, PERCENT_MAX);
        if (CurrentEvent < MONSTER_SPAWN_RATE)
        {
            printf("몬스터를 만났다!\n");
            Battle();
        }
        else
        {
            printf("몬스터를 만나지 못했다!.\n");
        }
    }
    if (User->GetCurrentHp() == DIE_HP)
    {
        User->SetHp(1);
    }
}

int DungeonManager::DungeonInput()
{
    int InputNumber = 0;
    while (InputNumber != VILLAG_NUMBER && User->GetCurrentHp() > DIE_HP)
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
    
    Status PlayerStatus = User->GetStatus();
    Status MonsterStatus = CurrentMonster->GetStatus();
    
    const float StandardTime = PlayerStatus.Spd * MonsterStatus.Spd;
    PQ.push(std::make_pair(StandardTime / PlayerStatus.Spd, User ));
    PQ.push(std::make_pair(StandardTime / MonsterStatus.Spd, CurrentMonster ));

    int TurnCount = 1;
    while (CurrentMonster->GetCurrentHp() > DIE_HP && User->GetCurrentHp() > DIE_HP)
    {
        printf("\n###################################################################\n");
        printf("\n\t\t\t<%d 번째 턴>\n\n", TurnCount);

        User->PrintPlayerInfo();
        CurrentMonster->PrintMonsterInfo();
        printf("\n");

        float CurrentTime = PQ.top().first;
        Actor* CurrentActor = PQ.top().second;
        PQ.pop();

        Status CurrentActorStatus = CurrentActor->GetStatus();

        int InputNumber = 0;
        if (CurrentActor->CheckPlayer())
        {
            InputNumber = CurrentActor->MyTurn(CurrentMonster);
        }
        else
        {
            InputNumber = CurrentActor->MyTurn(User);
        }
        if (CurrentActorStatus.CurrentMp < CurrentActorStatus.Mp)
        {
            CurrentActorStatus.CurrentMp++;
        }
        printf("\n");

        if (InputNumber == RUN_NUMBER)
        {
            printf("[%s] 도망쳤습니다.\n", CurrentActor->GetName().c_str());
            break;
        }

        float NextTime = CurrentTime + StandardTime / CurrentActorStatus.Spd;
        PQ.push({ NextTime, CurrentActor });
        
        TurnCount++;
    }
    User->InitMp();

    PQ = {};

    if (User->GetCurrentHp() <= DIE_HP)
    {
        User->Die(CurrentMonster);
    }

    if (CurrentMonster->GetCurrentHp() <= DIE_HP)
    {
        CurrentMonster->Die(User);
        
        User->AddExp(CurrentMonster->GetStatus().Exp);
        User->EarnGold(CurrentMonster->GetGold());
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

