#include "Village.h"
#include "Character.h"
#include "Logger.h"
#include <iostream>
using namespace std;

Village::Village() {
}

void Village::ShowChoice(Character& character) {
	/*Logger::getInstance().logEvent("���� ����");*/
	cout << "������ �����߽��ϴ�" << endl;
	int choice;

	while (true) {
		cout << "---<<  ������  >>---" << endl;
		cout << " 1. ����" << endl;
		cout << " 2. ����" << endl;
		cout << " 3. ������" << endl;
		cout << "--------------------" << endl;
		cout << "��ȣ�� �Է��ϼ���: ";
		//������ �Է�(����ó���ʿ�)
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "������ ������" << endl;
			inn.EnterInn(character);//ü�� ��, ��� ����
			break;

		case 2:
			cout << "������ ������" << endl;
			shop.EnterShop(character);//�κ��丮, ���
			break;

		case 3:
			cout << "�������� ������ ��" << endl;
			return;

		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
		}
	}
	
}

