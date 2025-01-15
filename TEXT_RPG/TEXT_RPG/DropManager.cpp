#include "DropManager.h"
#include "./Item/PassiveItem/Potion.h"
#include "./Item/Equipment/Equipment.h"
#include "./Item/PassiveItem/Amulet.h"
#include "./Item/PassiveItem/PassiveItem.h"
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
    _Items.push_back(new PotionHPSmall());
    _Items.push_back(new PotionHpMedium());
    _Items.push_back(new PotionHpLarge());

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

    Item* item = nullptr;
    std::uniform_real_distribution<> dist2(1 , _TotalProbability); 
    randomNum = dist2(gen);

    int cumulativeRate = 0;
    for ( size_t i = 0; i < _Items.size(); i++ )
    {
        cumulativeRate += _Probability[i];

        if ( randomNum <= cumulativeRate )
        {
            item = new Item(*_Items[i]);
        }
    }

    return item;
}

int DropManager::DropGold()
{
    std::uniform_int_distribution<> dist(1 , 5); // 0 ~ 4
    int randomNum = dist(gen);
    int gold = Character::GetInstance()->GetLevel() * randomNum;

    return gold;
}

