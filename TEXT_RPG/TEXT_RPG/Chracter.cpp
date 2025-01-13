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

//�÷��̾� ���Ⱥ����ֱ�
void Chracter::displayStatus()
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

void Chracter::levelUp()
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

void Chracter::useItem(int index)
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

void Chracter::addItem(PassiveItem* item)
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

int Chracter::getgold() const
{
	return gold;
}

void Chracter::setgold(int dealmoney)
{
	//���⿡ �����Ұ����� ���̳ʽ������� �־��ֱ�?
	if (dealmoney < 0)
	{
		int cost = -dealmoney;
		if (gold >= cost)
		{
			gold -= cost;
			cout << "��带 ����߽��ϴ�! ���� ��� : " << cost << "���� ��� : " << gold << endl;
		}
		else
		{
			cout << "��尡 �����մϴ�! ���� ���� ��� : " << gold << endl;
		}
	}
	else
	{
		gold += dealmoney;
		cout << "���� ���� ��� : " << dealmoney << endl;
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



