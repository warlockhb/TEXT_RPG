/*#include "GameManager.h"
int main()
{
    GameManager game;
    game.StartGame();

    std::srand(static_cast<unsigned>(std::time(0))); // 시드 설정
    bool GameEnd = true;
    while (GameEnd)
    {
        GameEnd = game.ShowMenu();
    }
    return 0;
}*/

#include <iostream>

#include "BattleManager.h"
#include "GameManager.h"
#include "Inventory.h"
#include "Item/PassiveItem/Potion.h"
#include "Village.h"

void main()
{
    Character* player = Character::GetInstance("hero");

    player->AddGold(3000);
    player->DisPlayStatus();
    player->GetInventory()->DisplayInventory();
    
    Village village;

    
    // Village에서 캐릭터를 통해 선택지 실행
    village.ShowChoice(*player);

    cout << "게임이 종료되었습니다." << endl;

    return;
}
