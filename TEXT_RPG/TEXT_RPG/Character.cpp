#include "Character.h"
#include <algorithm>
#include <iostream>
#include "Inventory.h"
#include "EquipmentSlot.h"
#include "Monster.h"
using namespace std;

Character * Character::instance = nullptr;

Character::Character(string New_name)
{
	this->Name = New_name;
	this->Level = 1;
	this->MaxHealth = 200;
	this->Health = MaxHealth;
	this->Attack = 30;
	this->Exp = 0;
	this->MaxExp = 100;
	this->Gold = 0;
	this->CurrentMaxHealth = MaxHealth;
	this->CurrentHealth = MaxHealth;
	this->CurrentAttack = Attack;

	inventory = new Inventory(this);
	equipmentSlot = new EquipmentSlot(this);
}

Character::~Character()
{
	if (inventory != nullptr)
	{
		delete inventory;
		inventory = nullptr;
	}

	if (equipmentSlot != nullptr)
	{
		delete equipmentSlot;
		equipmentSlot = nullptr;
	}
}


Character* Character::GetInstance(string New_name)
{
	if (instance == nullptr)
	{
		instance = new Character(New_name);
	}
	else if (!New_name.empty() && instance->Name.empty())
	{
		instance->Name = New_name;
	}
	return instance;
}

Inventory* Character::GetInventory()
{
	return inventory;
}

EquipmentSlot* Character::GetEquipmentSlot()
{
	return equipmentSlot;
}

string Character::GetName() const
{
	return Name;
}

int Character::GetLevel() const
{
	return Level;
}

int Character::GetHealth() const
{
	return Health;
}

int Character::GetMaxHealth() const
{
	return MaxHealth;
}

int Character::GetAttack() const
{
	return Attack;
}

int Character::GetExp() const
{
	return Exp;
}

int Character::GetGold() const
{
	return Gold;
}

int Character::GetCurrentHealth() const
{
	return CurrentHealth;
}

int Character::GetCurrentMaxHealth() const
{
	return CurrentMaxHealth;
}

int Character::GetCurrentAttack() const
{
	return  CurrentAttack;
}

void Character::SetHealth(int health)
{
	health = min(health, MaxHealth);
	health = max(health, 0);
	Health = health;
}

void Character::SetMaxHealth(int maxhealth)
{
	maxhealth = min(maxhealth, MaxHealth);
	maxhealth = max(maxhealth, 1);
	MaxHealth = maxhealth;
}

void Character::SetAttack(int attack)
{
	Attack = max(0, attack);
}

void Character::SetExp(int exp)
{
	Exp = max(0, exp);
}

void Character::SetMaxExp(int maxexp)
{
	MaxExp = max(1, maxexp);
}

void Character::SetGold(int gold)
{
	Gold = max(0, gold);
}

void Character::SetCurrentHealth(int health)
{
	health = min(health, MaxHealth);
	health = max(health, 0);
	CurrentHealth = health;
}

void Character::SetCurrentMaxHealth(int maxhealth)
{
	maxhealth = max(1, maxhealth);
	CurrentMaxHealth = max(maxhealth, MaxHealth);
}

void Character::SetCurrentAttack(int atk)
{
	CurrentAttack = max(0, atk);
}

void Character::DisPlayStatus()
{
	cout << "=============================" << endl;
	cout << "이름 : " << Name << endl;
	cout << "레벨 : " << Level << endl;
	cout << "체력 : " << CurrentHealth << "/" << CurrentMaxHealth << endl;
	cout << "공격력 : " << CurrentAttack << endl;
	cout << "현재 경험치 : " << Exp << endl;
	cout << "다음 레벨까지의 경험치 : " << MaxExp - Exp << endl;
	cout << "보유 골드 : " << Gold << endl;
	cout << "=============================" << endl;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "계속 하려면 엔터를 누르세요......." << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Character::TakeDamage(int damage)
{
	if (CurrentHealth <= 0)
	{
		PlayerDie();
		return;
	}

	SetCurrentHealth(max(CurrentHealth - damage, 0));
	cout << "캐릭터 피격! 대미지 : " << damage << " 현재 체력 : " << GetCurrentHealth() << endl;

	if (CurrentHealth <= 0)
	{
		SetCurrentHealth(0);
	}
}

void Character::RecoverHealth(int health)
{
	if (CurrentHealth < CurrentMaxHealth)
	{
		SetCurrentHealth(min(CurrentHealth + health, MaxHealth));
	}
	else if (CurrentHealth >= CurrentMaxHealth)
	{
		SetCurrentHealth(CurrentMaxHealth);
		cout << "더이상 체력을 회복할 수 없습니다." << endl;
	}
}

void Character::AllRecoverHealth()
{
	CurrentHealth = CurrentMaxHealth;
}

void Character::PlayerDie()
{
	cout << "===========================" << endl;
	cout << "캐릭터 사망. 게임 오버" << endl;
	cout << "캐릭터 이름 : " << Name << endl;
	cout << "최종 레벨 : " << Level << endl;
	cout << "보유 골드 : " << Gold << endl;
	cout << "===========================" << endl;
}

void Character::GainExp(int plusexp)
{
	if (Level <= 10)
	{
		Exp += plusexp;
	}
}

void Character::LevelUp()
{
	if (Level < 10 && Exp >= MaxExp)

	{
		this->Level++;
		int temp = CurrentMaxHealth - MaxHealth;
		int temp2 = CurrentAttack - Attack;
		this->MaxHealth += Level * 20;
		this->Health = MaxHealth;
		this->Attack += Level * 5;
		int temp3 = Exp - MaxExp;
		this->Exp = temp3;
		this->CurrentMaxHealth = MaxHealth + temp;
		this->CurrentHealth = CurrentMaxHealth;
		this->CurrentAttack = Attack + temp2;
		cout << "레벨 업!" << endl;
	}
	if (Level >= 10)
	{
		cout << "최대 레벨!" << endl;
		if(Exp >= MaxExp)
		{
			Exp = MaxExp;
		}
	}
}

void Character::AddGold(int plusgold)
{
	SetGold(Gold + plusgold);
	cout << "현재 보유한 골드 : " << GetGold() << endl;
}

void Character::LoseGold(int minusgold)
{
	if (GetGold() <= 0)
	{
		cout << "골드가...아예 없으신데요..?" << endl;
	}

	if (GetGold() >= minusgold)
	{
		SetGold(GetGold() - minusgold);
		cout << "골드를 사용하셨습니다. 사용하신 골드 : " << minusgold << "현재 남은 골드 : " << GetGold() << endl;
	}
	else
	{
		cout << "골드가 부족합니다. 보유 골드 : " << GetGold() << endl;
	}
}

void Character::DisPlayInventory()
{
	GetInventory()->DisplayInventory();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "계속 하려면 엔터를 누르세요......." << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Character::DisPlayEquipmentSlot()
{
	GetEquipmentSlot()->DisplayStorage();
	GetEquipmentSlot()->DisplayApply();
	cout << "장비 착용은 1번, 장비 해제는 2번, 장비 교체는 3번, 돌아가기 4번 : " << endl;
	int index;
	cin >> index;
	switch (index)
	{
	case 1:
		Equipment();
		break;
	case 2:
		UnEquipment();
		break;
	case 3:
		ChangeEquipment();
		break;
	case 4:
		cout << "장비함에서 나갑니다." << endl;
		return;
	}
}

void Character::ChangeEquipment()
{
	GetEquipmentSlot()->DisplayStorage();
	GetEquipmentSlot()->DisplayApply();

	if (GetEquipmentSlot()->GetEquipmentEmptySize() == 5 && GetEquipmentSlot()->GetEquipmentApplySlotEmptySize() == 5)
	{
		cout << "장비 보관함에 물건도, 착용한 장비도 없습니다." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "계속 하려면 엔터를 누르세요......." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	
	int index;
	int index2;
	cout << "장비 보관함의 어느 물건을 교체하실건가요? : " << endl;
	cin >> index;
	index -= 1;
	cout << "장비 착용함의 어느 물건을 교체하실건가요? : " << endl;
	cin >> index2;
	index2 -= 1;

	switch (index2)
	{
	case 0:
		GetEquipmentSlot()->ChangeItem(index2, index);
		break;
	case 1:
		GetEquipmentSlot()->ChangeItem(index2, index);
		break;
	case 2:
		GetEquipmentSlot()->ChangeItem(index2, index);
		break;
	case 3:
		GetEquipmentSlot()->ChangeItem(index2, index);
		break;
	case 4:
		GetEquipmentSlot()->ChangeItem(index2, index);
		break;
	default:
		cout << "잘못된 선택입니다. 1~5 사이의 값을 입력하세요." << endl;
		cin.clear();
		break;
	}

	GetEquipmentSlot()->DisplayStorage();
	GetEquipmentSlot()->DisplayApply();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "계속 하려면 엔터를 누르세요......." << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Character::UnEquipment()
{
	GetEquipmentSlot()->DisplayApply();

	if (GetEquipmentSlot()->GetEquipmentApplySlotEmptySize() == 5)
	{
		cout << "착용한 장비가 없습니다." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "계속 하려면 엔터를 누르세요......." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}

	int index;
	cout << "어떤 아이템을 장착 해제 하실 건가요? : " << endl;
	cin >> index;
	index -= 1;

	if (GetEquipmentSlot()->GetEquipmentEmptySize() != 0)
	{
		switch (index)
		{
		case 0:
			if (GetEquipmentSlot()->CheckApplySlot(index) != false)
			{
				GetEquipmentSlot()->Unequip(index);
			}
			else
			{
				cout << "장비를 착용하고 있지 않습니다." << endl;	
			}
			break;
		case 1:
			if (GetEquipmentSlot()->CheckApplySlot(index) != false)
			{
				GetEquipmentSlot()->Unequip(index);
			}
			else
			{
				cout << "장비를 착용하고 있지 않습니다." << endl;	
			}
			break;
		case 2:
			if (GetEquipmentSlot()->CheckApplySlot(index) != false)
			{
				GetEquipmentSlot()->Unequip(index);
			}
			else
			{
				cout << "장비를 착용하고 있지 않습니다." << endl;	
			}
			break;
		case 3:
			if (GetEquipmentSlot()->CheckApplySlot(index) != false)
			{
				GetEquipmentSlot()->Unequip(index);
			}
			else
			{
				cout << "장비를 착용하고 있지 않습니다." << endl;	
			}
			break;
		case 4:
			if (GetEquipmentSlot()->CheckApplySlot(index) != false)
			{
				GetEquipmentSlot()->Unequip(index);
			}
			else
			{
				cout << "장비를 착용하고 있지 않습니다." << endl;	
			}
			break;
		default:
			cout << "잘못된 선택입니다. 1~5 사이의 값을 입력하세요." << endl;
			cin.clear();
			break;
		}
	}

	GetEquipmentSlot()->DisplayStorage();
	GetEquipmentSlot()->DisplayApply();
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "계속 하려면 엔터를 누르세요......." << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Character::Equipment()
{
	GetEquipmentSlot()->DisplayStorage();
	GetEquipmentSlot()->DisplayApply();

	if (GetEquipmentSlot()->GetEquipmentEmptySize() == 5)
	{
		cout << "착용할 장비가 하나도 없습니다." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "계속 하려면 엔터를 누르세요......." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}

	int index;
	cout << "착용할 장비를 선택해 주세요. : " << endl;
	cin >> index;
	index -= 1;

	if (GetEquipmentSlot()->GetEquipmentApplySlotEmptySize() != 0)
	{
		switch (index)
		{
		case 0:
			if (GetEquipmentSlot()->CheckApplySlot(index) == false)
			{
				GetEquipmentSlot()->Equip(index);
			}
			else
			{
				cout << "해당 부위에는 장비가 이미 착용되어 있습니다." << endl;
			}
			break;
		case 1:
			if (GetEquipmentSlot()->CheckApplySlot(index) == false)
			{
				GetEquipmentSlot()->Equip(index);
			}
			else
			{
				cout << "해당 부위에는 장비가 이미 착용되어 있습니다." << endl;
			}
			break;
		case 2:
			if (GetEquipmentSlot()->CheckApplySlot(index) == false)
			{
				GetEquipmentSlot()->Equip(index);
			}
			else
			{
				cout << "해당 부위에는 장비가 이미 착용되어 있습니다." << endl;
			}
			break;
		case 3:
			if (GetEquipmentSlot()->CheckApplySlot(index) == false)
			{
				GetEquipmentSlot()->Equip(index);
			}
			else
			{
				cout << "해당 부위에는 장비가 이미 착용되어 있습니다." << endl;
			}
			break;
		case 4:
			if (GetEquipmentSlot()->CheckApplySlot(index) == false)
			{
				GetEquipmentSlot()->Equip(index);
			}
			else
			{
				cout << "해당 부위에는 장비가 이미 착용되어 있습니다." << endl;
			}
			break;
		default:
			cout << "잘못된 선택입니다. 1~5 사이의 값을 입력하세요." << endl;
			cin.clear();
			break;
		}
	}
	else
	{
		cout << "모든 부위에 장비를 착용하고 있습니다!" << endl;
	}

	GetEquipmentSlot()->DisplayApply();
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "계속 하려면 엔터를 누르세요......." << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}



