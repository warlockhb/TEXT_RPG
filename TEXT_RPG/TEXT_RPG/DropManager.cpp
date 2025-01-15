#include "DropManager.h"
#include "./Item/PassiveItem/Potion.h"
#include "./Item/Equipment/Equipment.h"
#include "./Item/PassiveItem/Amulet.h"
#include "./Item/PassiveItem/PassiveItem.h"
#include "Item/Equipment/Head.h"
#include "Item/Equipment/Guard.h"
#include "Item/Equipment/Boots.h"
#include "Item/Equipment/Armor.h"
#include "Item/Equipment/Weapon.h"
#include <algorithm>

#define ItemCnt 27

bool SortFunc(Item* _first, Item* _second)
{
    if ( _first->GetPrice() < _second->GetPrice() )
        return true;

    return false;
}

DropManager::DropManager()
    : gen(std::random_device{}( ))
    , _TotalProbability(0)
{
    // Potion
    _Items.push_back(new PotionHPSmall());
    _Items.push_back(new PotionHpMedium());
    _Items.push_back(new PotionHpLarge());

    // Amulet
    _Items.push_back(new AmuletOfStrngth());
    _Items.push_back(new AmuletOfWisdom());
    _Items.push_back(new AmuletOfVitality());
    _Items.push_back(new AmuletOfFortune());
    
    // Head
    _Items.push_back(new HeadLeatherCap());
    _Items.push_back(new HeadIronHelmet());
    _Items.push_back(new HeadKnightHelmet());
    _Items.push_back(new HeadDragonHelmet());

    // Armor
    _Items.push_back(new BodyLeatherCap());
    _Items.push_back(new BodyChainArmor());
    _Items.push_back(new BodyPlateArmor());
    _Items.push_back(new BodyDragonArmor());

    // Guard
    _Items.push_back(new ArmLeatherGuard());
    _Items.push_back(new ArmIronGuard());
    _Items.push_back(new ArmMithrilGuard());
    _Items.push_back(new ArmDragonGuard());

    // Boots
    _Items.push_back(new FootLeatherBoots());
    _Items.push_back(new FootIronBoots());
    _Items.push_back(new FootSwiftBoots());
    _Items.push_back(new FootDragonBoots());

    // Weapon
    _Items.push_back(new WeaponLongSword());
    _Items.push_back(new WeaponBattleAxe());
    _Items.push_back(new WeaponLongBow());
    _Items.push_back(new WeaponMagicStaff());

    sort(_Items.begin() , _Items.end(), SortFunc);
    
    int currentPrice = _Items[0]->GetPrice();
    int pastPrice = currentPrice;
    int remainingNum = ItemCnt;
    int probability = remainingNum;


    for ( size_t i = 0; i < _Items.size(); i++ )
    {
        if ( currentPrice > pastPrice )
        {
            probability = remainingNum;
        }
        _Probability.push_back(probability);
        remainingNum--;
        _TotalProbability += probability;
    }

}

DropManager::~DropManager()
{
    for ( Item* item : _Items )
    {
        delete item;
        item = nullptr;
    }
}

Item* DropManager::DropItem()
{
    std::uniform_real_distribution<> dist1(1 , 5); 
    int randomNum = dist1(gen);

    if ( randomNum != 5 )
        return nullptr;

    std::uniform_real_distribution<> dist2(1 , _TotalProbability); 
    randomNum = dist2(gen);

    int cumulativeRate = 0;
    for ( size_t i = 0; i < _Items.size(); i++ )
    {
        cumulativeRate += _Probability[i];

        if ( randomNum <= cumulativeRate )
        {
            return _Items[i];
        }
    }

    return nullptr;
}

int DropManager::DropGold()
{
    std::uniform_int_distribution<> dist(1 , 5); // 0 ~ 4
    int randomNum = dist(gen);
    int gold = Character::GetInstance()->GetLevel() * randomNum;

    return gold;
}

