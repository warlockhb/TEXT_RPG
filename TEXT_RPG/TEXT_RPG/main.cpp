#include <iostream>

#include "BattleManager.h"
#include "GameManager.h"
#include "Character.h"
#include "Inventory.h"
#include "Item/PassiveItem/Potion.h"
void main()
{
    BattleManager *battleManager = new BattleManager();
    //battleManager->StartBattle();

    Character* player = Character::GetInstance("hero");

    player->DisPlayStatus();
    player->GetInventory()->DisplayInventory();

    PotionHPSmall* potion = new PotionHPSmall();

    player->GetInventory()->AddItem(potion);
    player->GetInventory()->DisplayInventory();
}