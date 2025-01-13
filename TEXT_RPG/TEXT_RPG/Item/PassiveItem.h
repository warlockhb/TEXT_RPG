#pragma once
#include "Item.h"

enum EPassiveItemType
{
    // 100~199 : 포션
    ID_POTION_HP_SMALL = 100,         // 작은 체력 포션
    ID_POTION_HP_MEDIUM = 101,        // 중간 체력 포션
    ID_POTION_HP_LARGE = 102,         // 큰 체력 포션
    
    ID_POTION_MP_SMALL = 110,         // 작은 마나 포션
    ID_POTION_MP_MEDIUM = 111,        // 중간 마나 포션
    ID_POTION_MP_LARGE = 112,         // 큰 마나 포션

    // 200~299 : 부적
    ID_AMULET_OF_STRENGTH = 200,      // 힘의 부적
    ID_AMULET_OF_WISDOM = 201,        // 지혜의 부적
    ID_AMULET_OF_VITALITY = 202,      // 생명력의 부적
    ID_AMULET_OF_FORTUNE = 203,       // 행운의 부적
};

class PassiveItem : public Item
{
public:
    void ApplyPassive(Character* character);
    void RemovePassive(Character* character);
    
    virtual void ApplyEffect(Character* character) override;
    virtual void RemoveEffect(Character* character) override;
};
