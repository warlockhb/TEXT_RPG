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
		cout << "������ �����߽��ϴ�." << endl;

		cout << "---<< ���� >>---" << endl;
		cout << " 1. ��ǰ ����" << endl;
		cout << " 2. ��ǰ �Ǹ�" << endl;
		cout << " 3. ���� ������" << endl;
		cout << "----------------" << endl;
		cout << "��ȣ�� �Է��ϼ���: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			//��ǰ ����
			cout << " ��ǰ ����" << endl;
			//BuyItem();
			break;
		case 2:
			//��ǰ �Ǹ�
			cout << " ��ǰ �Ǹ�" << endl;
			//SellItem();
			break;
		case 3:
			cout << " ���� ������ ��" << endl;
			return;
		}
	}
}


//
//void Shop::BuyItem(Character & character) {
//	//����
//}
//
//void Shop::ShowItems(Item& item) {
//	//����
//}
//
//void Shop::SellItem(Character& character) {
//	//����
//
//}