#include "Chracter.h"

Chracter* Charather::instance = nullptr;

Chracter::Chracter(string Name)
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
}

Chracter* Chracter::getInstance(string name)
{
	if (instance == nullptr)
	{
		instance = new Chracter();
	}

	return instance;
}

//플레이어 스탯보여주기
void Chracter::displayStatus()
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

void Chracter::levelUp()
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

void Chracter::useItem(int index)
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

void Chracter::addItem(PassiveItem* item)
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

void Chracter::removeItem(PassiveItem* item)
{
	auto it = find(inventory.begin(), inventory.end(), item);

	if (it != inventory.end())
	{
		inventory.erase(it);
	}
}

void Chracter::byeInventory(int buycount)
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

int Chracter::getgold() const
{
	return gold;
}

void Chracter::setgold(int dealmoney)
{
	//여기에 구매할가격은 마이너스값으로 넣어주기?
	if (dealmoney < 0)
	{
		int cost = -dealmoney;
		if (gold >= cost)
		{
			gold -= cost;
			cout << "골드를 사용했습니다! 사용된 골드 : " << cost << "남은 골드 : " << gold << endl;
		}
		else
		{
			cout << "골드가 부족합니다! 현재 보유 골드 : " << gold << endl;
		}
	}
	else
	{
		gold += dealmoney;
		cout << "현재 보유 골드 : " << dealmoney << endl;
	}
}

void Chracter::setexp(int plusexp)
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



