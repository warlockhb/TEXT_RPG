#include "Character.h"

Character * Character::instance = nullptr;

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
	//this->Inventory.reserve(Max_Inventory_Size);
	//this->Equipment_Inventory.reserve(Max_Skill_Size);
}

Character* Character::GetInstance(string New_name)
{
	if (instance == nullptr)
	{
		instance = new Character(New_name);
	}
	return instance;
}


void Character::DisplayStatus()
{
	cout << "=============================" << endl;
	cout << "이름 : " << Name << endl;
	cout << "레벨 : " << Level << endl;
	cout << "체력 : " << Health << "/" << MaxHealth << endl;
	cout << "공격력 : " << Attack << endl;
	cout << "현재 경험치 : " << Exp << endl;
	cout << "다음 레벨까지의 경험치 : " << MaxExp - Exp << endl;
	cout << "보유 골드 : " << Gold << endl;
	cout << "=============================" << endl;
}


void Character::LevelUp()
{
	if (Level < 10 && Exp >= MaxExp)

	{
		this->Level++;
		this->MaxHealth += Level * 20;
		this->Health = MaxHealth;
		this->Attack += Level * 5;
		this->Exp = 0;
		cout << "레벨 업!" << endl;
	}
	if (Level >= 10)
	{
		cout << "최대 레벨!" << endl;
	}
}

//void Character::UseItem(int index)
//{
//	if (index < 0 || index >= Inventory.size())
//	{
//		cout << "잘못 입력되었습니다." << endl;
//	}
//
//	PassiveItem* item = Inventory[index];
//	//아이템 사용
//	//item->use(this)?
//
//	//delete item;
//	Inventory.erase(Inventory.begin() + index);
//	cout << "아이템을 사용했습니다!" << endl;
//}

//void Character::AddItem(PassiveItem* item)
//{
//	if (Inventory.size() < Max_Inventory_Size)
//	{
//		Inventory.push_back(item);
//		cout << "인벤토리에 아이템이 추가되었습니다." << endl;
//	}
//	else
//	{
//		cout << "인벤토리가 가득차서, 아이템을 추가할 수 없습니다." << endl;
//	}
//}

//void Character::RemoveItem(PassiveItem* item)
//{
//	auto it = find(Inventory.begin(), Inventory.end(), item);
//
//	if (it != Inventory.end())
//	{
//		Inventory.erase(it);
//	}
//}
//
//void Character::SkillUse(int index)
//{
//	if (index < 0 || index >= Equipment_Inventory.size())
//	{
//		cout << "잘못 입력되었습니다." << endl;
//	}
//
//	Equipment* skill = Equipment_Inventory[index];
//
//	delete skill;
//	cout << "스킬을 사용했습니다!" << endl;
//}
//
//void Character::AddSkill(Equipment* skill)
//{
//	if (Equipment_Inventory.size() < Max_Skill_Size)
//	{
//		Equipment_Inventory.push_back(skill);
//		cout << "스킬이 추가되었습니다." << endl;
//	}
//	else
//	{
//		cout << "인벤토리가 가득차서, 스킬을 추가할 수 없습니다." << endl;
//	}
//}
//
//void Character::RemoveSkill(Equipment* skill)
//{
//	auto it = find(Equipment_Inventory.begin(), Equipment_Inventory.end(), skill);
//
//	if (it != Equipment_Inventory.end())
//	{
//		Equipment_Inventory.erase(it);
//	}
//}
//
//void Character::ByeInventory(int buycount)
//{
//	switch (buycount)
//	{
//	case 1:
//		Max_Inventory_Size += 3;
//		Inventory.reserve(Max_Inventory_Size);
//		cout << "인벤토리를 확장되었습니다. 현재 인벤토리 사이즈 : " << Inventory.size() << endl;
//		break;
//	case 2:
//		Max_Inventory_Size += 5;
//		Inventory.reserve(Max_Inventory_Size);
//		cout << "인벤토리를 확장되었습니다. 현재 인벤토리 사이즈 : " << Inventory.size() << endl;
//		break;
//	default:
//		cout << "인벤토리를 최대 확장했습니다!" << endl;
//		break;
//	}
//}

void Character::Die()
{
	cout << "캐릭터가 사망했습니다. 게임 오버" << endl;
	cout << "당신의 최종 레벨 : " << Level << endl;
}

int Character::GetAttack()
{
	return Attack;
}

int Character::GetHealth()
{
	return Health;
}

int Character::Getgold()
{
	return Gold;
}

string Character::GetName()
{
	return Name;
}

int Character::GetLevel()
{
	return Level;
}

int Character::GetMaxHealth()
{
	return MaxHealth;
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
}

void Character::SetMinusGold(int buymoney)
{
	if (Gold >= buymoney)
	{
		Gold -= buymoney;
		cout << "골드를 사용했습니다! 사용된 골드 : " << buymoney << "남은 골드 : " << Gold << endl;
	}
	else
	{
		cout << "골드가 부족합니다! 현재 보유 골드 : " << Gold << endl;
	}
}

void Character::SetPlusGold(int sellmoney)
{
	Gold += sellmoney;
	cout << "현재 보유 골드 : " << Gold << endl;
}

void Character::SetMinusHp(int minushp)
{
	if (Health > 0)
	{
		Health -= minushp;
		cout << "현재 캐릭터의 체력 : " << Health << endl;

		if (Health <= 0)
		{
			Die();
		}
	}
	else
	{
		Die();
	}
}

void Character::SetPlusHp(int plushp)
{
	if (Health < MaxHealth)
	{
		Health += plushp;
		cout << "현재 캐릭터의 체력 : " << Health << endl;

		if (Health >= MaxHealth)
		{
			Health = MaxHealth;
		}
	}
	else
	{
		cout << "체력을 회북 할 수 없습니다." << endl;
	}
}

void Character::SetMinusAttack(int minusatk)
{
	Attack -= minusatk;
}

void Character::SetPlusAttack(int plusatk)
{
	Attack += plusatk;
}



