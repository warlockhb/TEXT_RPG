#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PassiveItem;


class Chracter
{
private:
	//�̱���
	static Chracter* instance;

	//��ġ �Ķ����
	string name;	
	int level;		
	int health;		
	int maxhealth;	
	int attack;		
	int exp;
	int maxExp;
	int gold;
	
	//�κ��丮
	vector<PassiveItem*> inventory;
	const size_t max_inventory_size = 7;
	//���ĭ


	Chracter(string Name);

	Chracter(const Chracter&) = delete;
	Chracter& operator = (const Character&) = delete;

public:
	//�̱��� ����
	static Chracter* getInstance(string name = "");

	void displayStatus();

	void levelUp();

	void useItem(int index);

	void addItem(PassiveItem* item);

	void removeItem(PassiveItem* item);

	void byeInventory(int buycount);

	int getgold() const;
	void setgold(int dealmoney);

	void setexp(int plusexp);


};

