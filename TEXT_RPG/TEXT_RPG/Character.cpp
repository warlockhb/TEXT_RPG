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
		instance = new Chracter();
	}

	return instance;
}

//�÷��̾� ���Ⱥ����ֱ�
void Character::displayStatus()
{
	cout << "=============================" << endl;
	cout << "�̸� : " << name << endl;
	cout << "���� : " << level << endl;
	cout << "ü�� : " << health << "/" << maxhealth << endl;
	cout << "���ݷ� : " << attack << endl;
	cout << "���� ����ġ : " << exp << endl;
	cout << "���� ���������� ����ġ : " << maxExp - exp << endl;
	cout << "���� ��� : " << gold << endl;
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
		cout << "���� ��!" << endl;
	}

	if (level >= 10)
	{
		cout << "�ִ� ����!" << endl;
	}
}

void Character::useItem(int index)
{
	if (index < 0 || index >= inventory.size())
	{
		cout << "�߸� �ԷµǾ����ϴ�." << endl;
	}

	PassiveItem* item = inventory[index];
	//������ ���
	//item->use(this)?

	delete item;
	inventory.erase(inventory.begin() + index);
	cout << "�������� ����߽��ϴ�!" << endl;
}

void Character::addItem(PassiveItem* item)
{
	if (inventory.size() < max_inventory_size)
	{
		inventory.push_back(item);
		cout << "�κ��丮�� �������� �߰��Ǿ����ϴ�." << endl;
	}
	else
	{
		cout << "�κ��丮�� ��������, �������� �߰��� �� �����ϴ�." << endl;
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
		cout << "�߸� �ԷµǾ����ϴ�." << endl;
	}

	Equipment* skill = equipment_inventory[index];

	delete skill;
	cout << "��ų�� ����߽��ϴ�!" << endl;
}

void Character::addskill(Equipment* skill)
{
	if (equipment_inventory.size() < max_skill_size)
	{
		equipment_inventory.push_back(skill);
		cout << "��ų�� �߰��Ǿ����ϴ�." << endl;
	}
	else
	{
		cout << "�κ��丮�� ��������, ��ų�� �߰��� �� �����ϴ�." << endl;
	}
}

void Character::removeskill(Equipment* skill)
{
	auto it = find(equipment_inventory.begin(), equipment_inventory.end(), item);

	if (it != equipment_inventory.end())
	{
		equipment_inventory.erase(it);
	}
}

void Character::byeInventory(int buycount)
{
	switch (buycount)
	{
	case 1:
		max_inventory_size += 3;
		inventory.reserve(max_inventory_size);
		cout << "�κ��丮�� Ȯ��Ǿ����ϴ�. ���� �κ��丮 ������ : " << inventory.size() << endl;
		break;
	case 2:
		max_inventory_size += 5;
		inventory.reserve(max_inventory_size);
		cout << "�κ��丮�� Ȯ��Ǿ����ϴ�. ���� �κ��丮 ������ : " << inventory.size() << endl;
		break;
	default:
		cout << "�κ��丮�� �ִ� Ȯ���߽��ϴ�!" << endl;
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
		cout << "��带 ����߽��ϴ�! ���� ��� : " << buymoney << "���� ��� : " << gold << endl;
	}
	else
	{
		cout << "��尡 �����մϴ�! ���� ���� ��� : " << gold << endl;
	}
}

void Character::plusgold(int sellmoney)
{
	gold += dealmoney;
	cout << "���� ���� ��� : " << sellmoney << endl;
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