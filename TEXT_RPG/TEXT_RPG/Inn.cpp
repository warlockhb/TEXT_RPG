#include "Inn.h"
//#include "Item.h"
#include "Character.h"
#include "Logger.h"
#include "Village.h"

#include <iostream>

using namespace std;


void Inn::EnterInn(Character& character) {
	char choice;
	

	while (true) {
		cout << "�뿬愿��뿉 �엯�옣�뻽�뒿�땲�떎." << endl;
		cout << "---<<  �뿬愿�  >>---" << endl;
		cout << "-  �씠�슜猷� : 10G -" << endl;
		cout << "------------------" << endl;
		cout << "�뿬愿��쓣 �궗�슜�븯寃좎뒿�땲源�?(y/n): ";
		//�꽑�깮吏� �엯�젰(�삁�쇅泥섎━�븘�슂)
		cin >> choice;
		

		switch (choice) {
		case 'y':
			//�뿬愿� �씠�슜O �꽑�깮�븳 寃쎌슦
			if (character.GetGold() < cost) {
				//怨⑤뱶 遺�議깊븳 寃쎌슦 -> 留덉쓣濡� 蹂듦��
				cout << "怨⑤뱶媛� 遺�議깊븯�뿬 留덉쓣濡� �룎�븘媛묐땲�떎." << endl;
				return;
			}
			else {
				//怨⑤뱶 異⑸텇�븳 寃쎌슦 -> �뿬愿� �씠�슜 �썑 留덉쓣濡� 蹂듦��
				cout << "�뿬愿� �씠�슜以�" << endl;
				UseInn(character);
				//留덉쓣濡� 蹂듦��
				cout << "留덉쓣濡� �룎�븘媛묐땲�떎." << endl;
				return;
			}
			break;
		case 'n':
			//�뿬愿� �씠�슜X �꽑�깮�븳 寃쎌슦 -> 留덉쓣濡� 蹂듦�� 
			cout << "�뿬愿� �씠�슜�쓣 嫄곕���뻽�뒿�땲�떎. 留덉쓣濡� �룎�븘媛묐땲�떎." << endl;
			//留덉쓣濡� 蹂듦��
			return;

		default:
			//媛믪쓣 �옒紐� �엯�젰�븳 寃쎌슦 EnterInn() �옱�샇異�
			cout << "y �삉�뒗 n留� �엯�젰�빐二쇱꽭�슂" << endl;
			break;
		}
	
	}
}

void Inn::UseInn(Character& character) {
	//10怨⑤뱶 李④컧 諛� �뵆�젅�씠�뼱 泥대젰 �쉶蹂�(�닔�젙 �븘�슂re)
	character.LoseGold(10);
	//character.health = character.maxhealth;//
	//cout << "�옍�뿬 怨⑤뱶 �닔: "<< character.getgold() << endl;
	//cout << "�쁽�옱 泥대젰: " << character.health << endl;
	//�뿬愿� �씠�슜 醫낅즺
	/*Logger::getInstance().logEvent("�뿬愿� �씠�슜 醫낅즺");*/
}