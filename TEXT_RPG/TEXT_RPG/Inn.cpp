#include "Inn.h"
#include "Item.h"
#include "Character.h"
#include "Logger.h"
#include "Village.h"

#include <iostream>

using namespace std;


void Inn::EnterInn(Character& character) {
	char choice;
	

	while (true) {
		cout << "������ �����߽��ϴ�." << endl;
		cout << "---<<  ����  >>---" << endl;
		cout << "-  �̿�� : 10G -" << endl;
		cout << "------------------" << endl;
		cout << "������ ����ϰڽ��ϱ�?(y/n): ";
		//������ �Է�(����ó���ʿ�)
		cin >> choice;
		

		switch (choice) {
		case 'y':
			//���� �̿�O ������ ���
			if (character.getgold < cost) {
				//��� ������ ��� -> ������ ����
				cout << "��尡 �����Ͽ� ������ ���ư��ϴ�." << endl;
				return;
			}
			else {
				//��� ����� ��� -> ���� �̿� �� ������ ����
				cout << "���� �̿���" << endl;
				UseInn(character);
				//������ ����
				cout << "������ ���ư��ϴ�." << endl;
				return;
			}
			break;
		case 'n':
			//���� �̿�X ������ ��� -> ������ ���� 
			cout << "���� �̿��� �ź��߽��ϴ�. ������ ���ư��ϴ�." << endl;
			//������ ����
			return;

		default:
			//���� �߸� �Է��� ��� EnterInn() ��ȣ��
			cout << "y �Ǵ� n�� �Է����ּ���" << endl;
			break;
		}
	
	}
}

void Inn::UseInn(Character& character) {
	//10��� ���� �� �÷��̾� ü�� ȸ��(���� �ʿ�re)
	character.setgold(-10);
	character.health = character.maxhealth;//
	cout << "�ܿ� ��� ��: "<< character.getgold() << endl;
	cout << "���� ü��: " << character.health << endl;
	//���� �̿� ����
	/*Logger::getInstance().logEvent("���� �̿� ����");*/
}