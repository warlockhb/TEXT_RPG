#include "Character.h"
#include "Shop.h"
#include "./Item/PassiveItem/Potion.h"

//#include "Item.h"

#include <iostream>

using namespace std;


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
			BuyItem();
			break;
		case 2:
			//상품 판매
			cout << " 상품 판매화면으로 이동합니다" << endl;
			SellItem();
			break;
		case 3:
			cout << " 상점 나가는 중" << endl;
			return;
		default:
			cout << "잘못된 선택입니다!" << endl;
			break;
		}
	}
}


void Shop::BuyItem() {
	int choice;
	while (true)
	{
		cout << "--<<  아이템 구매  >>--" << endl;
		cout << " 1. 포션" << endl;
		cout << " 2. 패시브" << endl;
		cout << " 3. 아뮬렛" << endl;
		cout << " 4. 장비" << endl;
		cout << " 5. 돌아가기" << endl;
		cout << "---------------------" << endl;
		cout << "번호를 입력하세요: ";
		//선택지 입력(예외처리필요)
		cin >> choice;

		if (1 <= choice && choice <= 4)
		{
			ShowItems(choice);
		}
		else if (choice == 5)
		{
			cout << "상점 초기화면으로 돌아갑니다" << endl;
			return;
		}
		else
		{
			cout << "잘못 입력하셨습니다. 1~4까지의 번호만 입력하세요" << endl;
		}
	}
}



void Shop::ShowItems(int choice)
{
	switch (choice)
	{
	case 1:
		cout << "--<<  포션 구매  >>--" << endl;
		//for문 : {i}<<". " << 아이템명 << 아이템 설명? << 아이템 가격 << endl;
		break;
	case 2:
		cout << "--<<  패시브 구매  >>--" << endl;
		//for문 : {i}<<". " << 아이템명 << 아이템 설명? << 아이템 가격 << endl;
		cout << " 1. " << endl;
		break;
	case 3:
		cout << "--<<  아뮬렛 구매  >>--" << endl;
		//for문 : {i}<<". " << 아이템명 << 아이템 설명? << 아이템 가격 << endl;
		cout << " 1. " << endl;
		break;
	case 4:
		cout << "--<<  장비 구매  >>--" << endl;
		//for문 : {i}<<". " << 아이템명 << 아이템 설명? << 아이템 가격 << endl;
		cout << " 1. " << endl;
		break;
	default://do nothing
		break;
	}
	cout << " 4. 돌아가기" << endl;
	cout << "---------------------" << endl;
	cout << "번호를 입력하세요: ";
	
}

void Shop::SellItem() {
	//수정

}