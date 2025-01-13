#include "Village.h"
#include "Character.h"
#include "Logger.h"
#include <iostream>
using namespace std;

Village::Village() {
}

void Village::ShowChoice(Character& character) {
	/*Logger::getInstance().logEvent("마을 입장");*/
	cout << "마을에 입장했습니다" << endl;
	int choice;

	while (true) {
		cout << "---<<  선택지  >>---" << endl;
		cout << " 1. 여관" << endl;
		cout << " 2. 상점" << endl;
		cout << " 3. 나가기" << endl;
		cout << "--------------------" << endl;
		cout << "번호를 입력하세요: ";
		//선택지 입력(예외처리필요)
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "여관에 입장중" << endl;
			inn.EnterInn(character);//체력 힐, 골드 여부
			break;

		case 2:
			cout << "상점에 입장중" << endl;
			shop.EnterShop(character);//인벤토리, 골드
			break;

		case 3:
			cout << "마을에서 나가는 중" << endl;
			return;

		default:
			cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
		}
	}
	
}

