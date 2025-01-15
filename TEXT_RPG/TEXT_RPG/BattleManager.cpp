#include "BattleManager.h"
#include "MonsterManager.h"
#include "Character.h"
#include <cstdlib>

using namespace std;

BattleManager::BattleManager()
{
    IsBattleEnd = false;
    _BattleState = EBS_INPROGRESS;
}

BattleManager::~BattleManager()
{
    delete _MonsterManager;
    _MonsterManager = nullptr;
    _Monster = nullptr;
}

void BattleManager::StartBattle()
{
    //Todo : 자동공격 & 수동공격
    cout << "1. 자동 전투 ___ 2. 수동 전투" << endl;

    //cout << "---- 자동 전투 시작 ----" << endl;
    int BattleType = 1;
    cin >> BattleType;
    cout << endl;

    switch (BattleType)
    {
    case 1:
        cout << "자동전투" << endl;
        AutoBattle();
        break;
    case 2:
        cout << "수동전투" << endl;
        ManualBattle();
        break;
    default:
        cout << "그냥 자동전투하세요.";
        break;
    }
}

EBattleState BattleManager::GetBattleState() const
{
    return _BattleState;
}

void BattleManager::AutoBattle()
{
    _MonsterManager = new MonsterManager();

    _Monster = _Monster = Character::GetInstance()->GetLevel() == 10
                           ? _MonsterManager->CreateBossMonster()
                           : _MonsterManager->CreateNormalMonster();

    int TurnCount = 0;
    while (!IsBattleEnd)
    {
        if (TurnCount % 2 == 0)
        {
            AttackMonster(*_Monster);
            //Todo : Item 랜덤 사용
        }
        else
        {
            AttackCharacter(*_Monster);
        }
        
        TurnCount++;
    }
}

void BattleManager::AttackCharacter(Monster& Monster)
{
    cout << "---- 몬스터가 플레이어를 공격합니다.----\n" << endl;
    int Damage = Monster.GetPower();
    //cout << "---- 데미지 : " << Damage << " ----\n" << endl;
    Character::GetInstance()->TakeDamage(Damage);
    int Health = Character::GetInstance()->GetCurrentHealth();
    //cout << "캐릭터 남은 체력 : " << Health << "\n" << endl;

    if (IsDead(Health))
    {
        EndBattle(false);
    }
}

void BattleManager::AttackMonster(Monster& Monster)
{
    cout << "---- 플레이어가 몬스터를 공격합니다.----\n" << endl;
    int Damage = Character::GetInstance()->GetCurrentAttack();
    cout << "---- 데미지 : " << Damage << " ----\n" << endl;
    Monster.TakeDamage(Damage);
    int Health = Monster.GetHp();
    
    cout << "몬스터 남은 체력 : " <<  Health << "\n" << endl;
    
    if (IsDead(Health))
    {
        EndBattle(true);
    }
}

void BattleManager::ManualBattle()
{
   _MonsterManager = new MonsterManager();
    //Todo : 보스몬스터 조건
    _Monster = Character::GetInstance()->GetLevel() == 10
                           ? _MonsterManager->CreateBossMonster()
                           : _MonsterManager->CreateNormalMonster();

    int TurnCount = 0;
    while (!IsBattleEnd)
    {
        if (TurnCount % 2 == 0)
        {
            int choice = 0;

            cout << "1. 기본공격 ____ 2. 스킬사용 ____ 3. 아이템 사용 ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "기본 공격" << endl;
                AttackMonster(*_Monster);
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                cout << "기본 공격" << endl;
                AttackMonster(*_Monster);
                break;
            }
        }
        else
        {
            AttackCharacter(*_Monster);
        }
        
        TurnCount++;
    }
}

void BattleManager::EndBattle(bool IsPlayerWin)
{
    _MonsterManager->DeleteMonster(_Monster, IsPlayerWin);
    
    IsBattleEnd = true;

    if (IsPlayerWin)
    {
        // 플레이어 승리
        _BattleState = EBS_PLAYER_WIN;
    }
    else
    {
        _BattleState = EBS_PLAYER_LOSE;
    }
    cout << "---- 전투 종료 ----" << endl;
}

bool BattleManager::IsDead(int Health)
{
    return Health <= 0;
}
