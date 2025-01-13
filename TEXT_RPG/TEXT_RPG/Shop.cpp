#include "Character.h"
#include "Village.h"
#include "Shop.h"
#include "Logger.h"
//#include "Item.h"

#include <iostream>

using namespace std;


void Shop::EnterShop(Character& character) {
	int choice;
	while (true) {
		cout << "상점에 입장했습니다." << endl;

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
			cout << " 상품 구매" << endl;
			//BuyItem();
			break;
		case 2:
			//상품 판매
			cout << " 상품 판매" << endl;
			//SellItem();
			break;
		case 3:
			cout << " 상점 나가는 중" << endl;
			return;
		}
	}
}


//
//void Shop::BuyItem(Character & character) {
//	//수정
//}
//
//void Shop::ShowItems(Item& item) {
//	//수정
//}
//
//void Shop::SellItem(Character& character) {
//	//수정
//
//}