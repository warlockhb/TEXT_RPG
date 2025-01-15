#include "DropManager.h"
#include "./Item/PassiveItem/Potion.h"
#include "./Item/Equipment/Equipment.h"
#include "./Item/PassiveItem/Amulet.h"
#include "./Item/PassiveItem/PassiveItem.h"

#define ItemCnt 27

DropManager::DropManager()
    : gen(std::random_device{}( ))
{
    _Items.push_back(new PotionHPSmall());
    _Items.push_back(new PotionHpMedium());
    _Items.push_back(new PotionHpLarge());

    _Probability.push_back(0.1);
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
    Item* item = nullptr;
    std::uniform_real_distribution<> dist(0.0 , 1.0); // 0.0 ~ 1.0 범위의 실수
    double randomNum = dist(gen);

    float cumulativeRate = 0.0f;
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

