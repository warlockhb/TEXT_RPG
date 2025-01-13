#include "Character.h"
em#include "Character.h"

Character* Character::instance = nullptr;

Character::Character(string New_name)
{
	this->Name = New_name;
	this->Level = 1;
	this->MaxHealth = 100;
	this->Health = MaxHealth;
	this->Attack = 30;
	this->Exp = 0;
	this->MaxExp = 100;
	this->Gold = 0;
	this->Inventory.reserve(Max_Inventory_Size);
	this->Equipment_Inventory.reserve(Max_Skill_Size);
}

Character* Character::GetInstance(string name)
{
	if (instance == nullptr)
	{
		instance = new Character();
	}

	return instance;
}

<<<<<<< HEAD
//플레이어 스탯보여주기
void Character::DisPlayStatus()
{
	cout << "=============================" << endl;
	cout << "이름 : " << Name << endl;
	cout << "레벨 : " << Level << endl;
	cout << "체력 : " << Health << "/" << MaxHealth << endl;
	cout << "공격력 : " << Attack << endl;
	cout << "현재 경험치 : " << Exp << endl;
	cout << "다음 레벨까지의 경험치 : " << MaxExp - Exp << endl;
	cout << "보유 골드 : " << Gold << endl;
=======
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
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
	cout << "=============================" << endl;
}

void Character::LevelUp()
{
	if (Level < 10 && exp >= maxExp)
	{
<<<<<<< HEAD
		this->Level++;
		this->MaxHealth += Level * 20;
		this->Health = MaxHealth;
		this->Attack += Level * 5;
		this->Exp = 0;
		cout << "레벨 업!" << endl;
=======
		this->level++;
		this->maxhealth += level * 20;
		this->health = maxhealth;
		this->attack += level * 5;
		this->exp = 0;
		cout << "���� ��!" << endl;
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
	}

	if (Level >= 10)
	{
<<<<<<< HEAD
		cout << "최대 레벨!" << endl;
=======
		cout << "�ִ� ����!" << endl;
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
	}
}

void Character::UseItem(int index)
{
	if (index < 0 || index >= Inventory.size())
	{
<<<<<<< HEAD
		cout << "잘못 입력되었습니다." << endl;
	}

	PassiveItem* item = Inventory[index];
	//아이템 사용
	//item->use(this)?

	delete item;
	Inventory.erase(Inventory.begin() + index);
	cout << "아이템을 사용했습니다!" << endl;
=======
		cout << "�߸� �ԷµǾ����ϴ�." << endl;
	}

	PassiveItem* item = inventory[index];
	//������ ���
	//item->use(this)?

	delete item;
	inventory.erase(inventory.begin() + index);
	cout << "�������� ����߽��ϴ�!" << endl;
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
}

void Character::AddItem(PassiveItem* item)
{
	if (Inventory.size() < Max_Inventory_Size)
	{
<<<<<<< HEAD
		Inventory.push_back(item);
		cout << "인벤토리에 아이템이 추가되었습니다." << endl;
	}
	else
	{
		cout << "인벤토리가 가득차서, 아이템을 추가할 수 없습니다." << endl;
=======
		inventory.push_back(item);
		cout << "�κ��丮�� �������� �߰��Ǿ����ϴ�." << endl;
	}
	else
	{
		cout << "�κ��丮�� ��������, �������� �߰��� �� �����ϴ�." << endl;
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
	}
}

void Character::RemoveItem(PassiveItem* item)
{
	auto it = find(Inventory.begin(), Inventory.end(), item);

	if (it != Inventory.end())
	{
		Inventory.erase(it);
	}
}

void Character::SkillUse(int index)
{
	if (index < 0 || index >= Equipment_Inventory.size())
	{
<<<<<<< HEAD
		cout << "잘못 입력되었습니다." << endl;
=======
		cout << "�߸� �ԷµǾ����ϴ�." << endl;
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
	}

	Equipment* skill = Equipment_Inventory[index];

	delete skill;
<<<<<<< HEAD
	cout << "스킬을 사용했습니다!" << endl;
=======
	cout << "��ų�� ����߽��ϴ�!" << endl;
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
}

void Character::AddSkill(Equipment* skill)
{
	if (Equipment_Inventory.size() < Max_Skill_Size)
	{
<<<<<<< HEAD
		Equipment_Inventory.push_back(skill);
		cout << "스킬이 추가되었습니다." << endl;
	}
	else
	{
		cout << "인벤토리가 가득차서, 스킬을 추가할 수 없습니다." << endl;
=======
		equipment_inventory.push_back(skill);
		cout << "��ų�� �߰��Ǿ����ϴ�." << endl;
	}
	else
	{
		cout << "�κ��丮�� ��������, ��ų�� �߰��� �� �����ϴ�." << endl;
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
	}
}

void Character::RemoveSkill(Equipment* skill)
{
	auto it = find(Equipment_Inventory.begin(), Equipment_Inventory.end(), skill);

	if (it != Equipment_Inventory.end())
	{
		Equipment_Inventory.erase(it);
	}
}

void Character::ByeInventory(int buycount)
{
	switch (buycount)
	{
	case 1:
<<<<<<< HEAD
		Max_Inventory_Size += 3;
		Inventory.reserve(Max_Inventory_Size);
		cout << "인벤토리를 확장되었습니다. 현재 인벤토리 사이즈 : " << Inventory.size() << endl;
		break;
	case 2:
		Max_Inventory_Size += 5;
		Inventory.reserve(Max_Inventory_Size);
		cout << "인벤토리를 확장되었습니다. 현재 인벤토리 사이즈 : " << Inventory.size() << endl;
		break;
	default:
		cout << "인벤토리를 최대 확장했습니다!" << endl;
=======
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
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
		break;
	}
}

int Character::Getgold()
{
	return Gold;
}

void Character::MinusGold(int buymoney)
{
	if (Gold >= buymoney)
	{
<<<<<<< HEAD
		Gold -= buymoney;
		cout << "골드를 사용했습니다! 사용된 골드 : " << buymoney << "남은 골드 : " << Gold << endl;
	}
	else
	{
		cout << "골드가 부족합니다! 현재 보유 골드 : " << Gold << endl;
=======
		gold -= buymoney;
		cout << "��带 ����߽��ϴ�! ���� ��� : " << buymoney << "���� ��� : " << gold << endl;
	}
	else
	{
		cout << "��尡 �����մϴ�! ���� ���� ��� : " << gold << endl;
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
	}
}

void Character::PlusGold(int sellmoney)
{
<<<<<<< HEAD
	Gold += sellmoney;
	cout << "현재 보유 골드 : " << Gold << endl;
=======
	gold += dealmoney;
	cout << "���� ���� ��� : " << sellmoney << endl;
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
}

void Character::SetExp(int plusexp)
{
	if (Level < 10)
	{
		if (Exp < MaxExp)
		{
			Exp += plusexp;
		}
		else
		{
			LevelUp();
			Exp += plusexp;
		}
	}
<<<<<<< HEAD
}

void Character::GetAttack()
{
	return Attack;
}

void Character::GetHealth()
{
	return Health;
}





=======
}
>>>>>>> 4d9d67f6080d6d58e206ff953df655494e76d7ec
