#include "Character.h"
#include "Shop.h"
#include "./Item/PassiveItem/Potion.h"
#include "./Item/Equipment/Equipment.h"
#include "./Item/PassiveItem/Amulet.h"
#include "./Item/PassiveItem/PassiveItem.h"

#include <iostream>

using namespace std;

Shop::Shop()
{
	items[ID_POTION_HP_SMALL] = new PotionHPSmall();
	items[ID_POTION_HP_MEDIUM] = new PotionHpMedium();
	items[ID_POTION_HP_LARGE] = new PotionHpLarge();

	//[물건복붙]추가 판매할 물건들(작성예정)
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
			cout << " 상품 구매 화면으로 이동합니다" << endl;
			ShowItems();
			BuyItem(character);
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

void Shop::ShowItems()
{
	int cnt = 1;
	cout << "--<<  구매 가능한 상품 목록  >>--" << endl;
	for (auto& item : items)
	{//출력예시 : - 100. 소형 포션 : 체력을 회복시켜준다 (30G)
		cout <<" - " <<item.first << ". "
			 << item.second->GetName() << ": "
			 <<item.second->GetDescription() << " ("
			 <<item.second->GetPrice() << "G)" << endl;
	}
	cout << " - 0. 돌아가기" << endl;
	cout << "----------------" << endl;

}

void Shop::BuyItem(Character& character) {
	int selectedID;
	while (true)
	{
		ShowItems();
		cout << "상품번호를 입력하세요: ";
		//선택지 입력(예외처리필요)
		cin >> selectedID;

		if (selectedID == 0)
		{
			//0. 돌아가기 입력된 경우
			return;
		}
		else if (items.find(selectedID) != items.end())
		{
			//아이템 아이디 입력된 경우
			Item* selectedItem = items[selectedID];
			//item_price : 선택한 아이템 가격
			int item_price = selectedItem->GetPrice();
			if (character.GetGold() >= item_price) //수정 : 자리 없는 경우 거부해야함
			{
				character.LoseGold(item_price);
				//인벤토리에 해당 아이템 삽입
			}
			else
			{//골드가 부족한 경우
				cout << "골드가 부족합니다." << endl;
			}
			
		}
		else
		{
			cout << "잘못 입력하셨습니다. 상품번호만 입력하세요." << endl;
		}
	}
}


void Shop::SellItem(Character& character) {
	//수정
	//- 인벤토리 불러와서 목록 전부 보여준 다음,
	// 판매 원하는 물건을 인벤토리에서 삭제하고 해당 물건 60% 금액을 ++하기
}


Shop::~Shop()
{
	for (auto& item : items)
	{
		delete item.second;
	}
}