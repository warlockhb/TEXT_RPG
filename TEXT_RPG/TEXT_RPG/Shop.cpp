#include "Character.h"
#include "Shop.h"
#include "./Item/PassiveItem/Potion.h"
#include "./Item/Equipment/Equipment.h"
#include "./Item/PassiveItem/Amulet.h"
#include "./Item/PassiveItem/PassiveItem.h"

#include <iostream>

#include "Inventory.h"

using namespace std;

Shop::Shop()
{
	potions[ID_POTION_HP_SMALL] = new PotionHPSmall();
	potions[ID_POTION_HP_MEDIUM] = new PotionHpMedium();
	potions[ID_POTION_HP_LARGE] = new PotionHpLarge();

	amulets[ID_AMULET_OF_STRENGTH] = new AmuletOfStrngth();
	amulets[ID_AMULET_OF_WISDOM] = new AmuletOfWisdom();
	amulets[ID_AMULET_OF_VITALITY] = new AmuletOfVitality();
	amulets[ID_AMULET_OF_FORTUNE] = new AmuletOfFortune();
}

void Shop::EnterShop(Character& character) {
	int choice;
	cout << "상점에 입장했습니다." << endl;
	while (true) {
		cout << "---<< 상점 >>---" << endl;
		cout << " 1. 상품 구매" << endl;
		cout << " 2. 상품 판매" << endl;
		cout << " 3. 상점 나가기" << endl;
		cout << "----------------" << endl;
		cout << "번호를 입력하세요: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			//상품 구매
			/*BuyItem();*/
			break;
		case 2:
			//상품 판매
			cout << " 상품 판매화면으로 이동합니다" << endl;
			SellItem(character);
			break;
		case 3:
			cout << " 상점 나가는 중" << endl;
			return;
		default:
			cout << "잘못 입력하셨습니다. 1~3까지의 번호만 입력하세요" << endl;
			break;
		}
	}
}
void Shop::BuyItem(Character& character)
{
	while (true)
	{
		int choice;
		cout << "---<< 구매 가능한 상품 >>---" << endl;
		cout << " 1. 포션" << endl;
		cout << " 2. 부적" << endl;
		cout << " 3. 상점 나가기" << endl;
		cout << "----------------" << endl;
		cout << "번호를 입력하세요: " << endl;

		cin >> choice;
		switch (choice)
		{
		case 1:
			BuyLogic(character, potions);
			break;
		case 2:
			BuyLogic(character, amulets);
			break;
		}
	}

}
void Shop::ShowItems(const std::map<int, PassiveItem*>& map_item)
{
	int cnt = 1;
	cout << "--<<  구매 가능한 상품 목록  >>--" << endl;
	for (auto& item : map_item)
	{//출력예시 : - 100. 소형 포션 : 체력을 회복시켜준다 (30G)
		cout <<" - " <<item.first << ". "
			 << item.second->GetName() << ": "
			 <<item.second->GetDescription() << " ("
			 <<item.second->GetPrice() << "G)" << endl;
	}
	cout << " - 0. 돌아가기" << endl;
	cout << "----------------" << endl;

}

void Shop::BuyLogic(Character& character, const std::map<int, PassiveItem*>& map_item) {
	int selectedID;
	while (true)
	{
		ShowItems(map_item);
		cout << "상품번호를 입력하세요: ";
		cin >> selectedID;

		if (selectedID == 0)
		{
			//0. 돌아가기 입력된 경우
			return;
		}
		else if (map_item.find(selectedID) != map_item.end())
		{
			//아이템 아이디 올바르게 입력된 경우
			PassiveItem* selectedItem = map_item.at(selectedID);
			//item_price : 선택한 아이템 가격
			int item_price = selectedItem->GetPrice();
			if (character.GetGold() < item_price) //골드가 부족한 경우
			{
				cout << "골드가 부족합니다." << endl;
				return;
			}
			else{//골드 충분한 경우
				/*if(character.GetInventory()->GetItemInventorySize() == character.GetInventory()->GetMaxInventorySize()){ //인벤토리 자리 없는 경우
				cout << "인벤토리가 꽉 찼습니다." << endl;
				return;
				}*/
				
				/*else {// 인벤토리 내 자리가 있는 경우
				character.LoseGold(item_price);
				character.GetInventory()->AddItem(selectedItem);
				}*/
			}
		}
		
		else
		{
			cout << "잘못 입력하셨습니다. 상품번호만 입력하세요." << endl;
		}
	}
}


void Shop::SellItem(Character& character) {
	Inventory* inventory = character.GetInventory();

	while (true)
	{
		//인벤토리 목록 출력 코드
		cout << "---<< 인벤토리 목록 >>---" << endl;
		for (int i = 0; i < inventory->GetMaxItemInventorySize() - inventory->GetItemInventoryEmptySize(); ++i)
		{
			PassiveItem* item = inventory->GetItem(i);
			if (item)
			{//출력 예시 : 1. 이름 : 설명 (가격: 10G)
				cout << i + 1 << ". " << item->GetName() << ": "
					 << item->GetDescription() << "(가격: " << item->GetPrice() << "G)" << endl;
			}
		}
		cout << "-------------------------" << endl;
		cout << "판매할 아이템의 번호를 입력하세요 (0: 나가기): ";

		int choice;
		cin >> choice;

		if (choice == 0)
		{
			return;
		}

		PassiveItem* itemToSell = inventory->GetItem(choice - 1);
		if (itemToSell == nullptr) {
			cout << "잘못된 번호입니다. 다시 입력하세요." << endl;
			continue;
		}

		//판매
		int itemPrice = itemToSell->GetPrice();
		character.AddGold(itemPrice * 0.6);
		inventory->RemoveItem(choice - 1);
		cout << itemToSell->GetName() << " 아이템을 판매했습니다.(가격: " << itemPrice * 0.6 << "G)" << endl;
		
		
	}

}


Shop::~Shop()
{
	for (auto& amulet : amulets)
	{
		delete amulet.second;
	}
	for (auto& potion : potions)
	{
		delete potion.second;
	}
}
