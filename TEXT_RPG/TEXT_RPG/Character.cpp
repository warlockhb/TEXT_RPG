#include "Character.h"

Character* Character::instance = nullptr;

Character::Character(string Name)
{
	this->name = Name;
	this->level = 1;
	this->maxhealth = 100;
	this->health = maxhealth;
	this->attack = 30;
	this->exp = 0;
	this->maxExp = 100;
	this->gold = 0;
	this->inventory.reserve(max_inventory_size);
	this->equipment_inventory.reserve(max_skill_size);
}

Character* Character::getInstance(string name)
{
	if (instance == nullptr)
	{
		instance = new Character(name);
	}

	return instance;
}

//플레이어 스탯보여주기
void Character::displayStatus()
{
	cout << "=============================" << endl;
	cout << "이름 : " << name << endl;
	cout << "레벨 : " << level << endl;
	cout << "체력 : " << health << "/" << maxhealth << endl;
	cout << "공격력 : " << attack << endl;
	cout << "현재 경험치 : " << exp << endl;
	cout << "다음 레벨까지의 경험치 : " << maxExp - exp << endl;
	cout << "보유 골드 : " << gold << endl;
	cout << "=============================" << endl;
}

void Character::levelUp()
{
	if (level < 10 && exp >= maxExp)
	{
		this->level++;
		this->maxhealth += level * 20;
		this->health = maxhealth;
		this->attack += level * 5;
		this->exp = 0;
		cout << "레벨 업!" << endl;
	}

	if (level >= 10)
	{
		cout << "최대 레벨!" << endl;
	}
}

void Character::useItem(int index)
{
	if (index < 0 || index >= inventory.size())
	{
		cout << "잘못 입력되었습니다." << endl;
	}

	PassiveItem* item = inventory[index];
	//아이템 사용
	//item->use(this)?

	delete item;
	inventory.erase(inventory.begin() + index);
	cout << "아이템을 사용했습니다!" << endl;
}

void Character::addItem(PassiveItem* item)
{
	if (inventory.size() < max_inventory_size)
	{
		inventory.push_back(item);
		cout << "인벤토리에 아이템이 추가되었습니다." << endl;
	}
	else
	{
		cout << "인벤토리가 가득차서, 아이템을 추가할 수 없습니다." << endl;
	}
}

void Character::removeItem(PassiveItem* item)
{
	auto it = find(inventory.begin(), inventory.end(), item);

	if (it != inventory.end())
	{
		inventory.erase(it);
	}
}

void Character::skilluse(int index)
{
	if (index < 0 || index >= equipment_inventory.size())
	{
		cout << "잘못 입력되었습니다." << endl;
	}

	Equipment* skill = equipment_inventory[index];

	delete skill;
	cout << "스킬을 사용했습니다!" << endl;
}

void Character::addskill(Equipment* skill)
{
	if (equipment_inventory.size() < max_skill_size)
	{
		equipment_inventory.push_back(skill);
		cout << "스킬이 추가되었습니다." << endl;
	}
	else
	{
		cout << "인벤토리가 가득차서, 스킬을 추가할 수 없습니다." << endl;
	}
}

void Character::removeskill(Equipment* skill)
{
	/*	auto it = find(equipment_inventory.begin(), equipment_inventory.end(), item);

		if (it != equipment_inventory.end())
		{
			equipment_inventory.erase(it);
		}
		*/
}

void Character::byeInventory(int buycount)
{
	switch (buycount)
	{
	case 1:
		max_inventory_size += 3;
		inventory.reserve(max_inventory_size);
		cout << "인벤토리를 확장되었습니다. 현재 인벤토리 사이즈 : " << inventory.size() << endl;
		break;
	case 2:
		max_inventory_size += 5;
		inventory.reserve(max_inventory_size);
		cout << "인벤토리를 확장되었습니다. 현재 인벤토리 사이즈 : " << inventory.size() << endl;
		break;
	default:
		cout << "인벤토리를 최대 확장했습니다!" << endl;
		break;
	}
}

int Character::getgold() const
{
	return gold;
}

void Character::minusgold(int buymoney)
{
	if (gold >= buymoney)
	{
		gold -= buymoney;
		cout << "골드를 사용했습니다! 사용된 골드 : " << buymoney << "남은 골드 : " << gold << endl;
	}
	else
	{
		cout << "골드가 부족합니다! 현재 보유 골드 : " << gold << endl;
	}
}

void Character::plusgold(int sellmoney)
{
	//	gold += dealmoney;
	cout << "현재 보유 골드 : " << sellmoney << endl;
}

void Character::setexp(int plusexp)
{
	if (level < 10)
	{
		if (exp < maxExp)
		{
			exp += plusexp;
		}
		else
		{
			levelUp();
			exp += plusexp;
		}
	}
}



