#include "Potion.h"

PotionHPSmal::PotionHPSmal(): PassiveItem()
{
    StatModifier.HpMod = 10;
    *this = PassiveItem(
        ID_POTION_HP_SMALL,
        "소형 체력 포션",
        20,
        "체력을" + to_string(StatModifier.HpMod) + "회복시켜준다."
        );
}
