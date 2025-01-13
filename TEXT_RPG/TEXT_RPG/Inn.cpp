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
		cout << "여관에 입장했습니다." << endl;
		cout << "---<<  여관  >>---" << endl;
		cout << "-  이용료 : 10G -" << endl;
		cout << "------------------" << endl;
		cout << "여관을 사용하겠습니까?(y/n): ";
		//선택지 입력(예외처리필요)
		cin >> choice;
		

		switch (choice) {
		case 'y':
			//여관 이용O 선택한 경우
			if (character.getgold < cost) {
				//골드 부족한 경우 -> 마을로 복귀
				cout << "골드가 부족하여 마을로 돌아갑니다." << endl;
				return;
			}
			else {
				//골드 충분한 경우 -> 여관 이용 후 마을로 복귀
				cout << "여관 이용중" << endl;
				UseInn(character);
				//마을로 복귀
				cout << "마을로 돌아갑니다." << endl;
				return;
			}
			break;
		case 'n':
			//여관 이용X 선택한 경우 -> 마을로 복귀 
			cout << "여관 이용을 거부했습니다. 마을로 돌아갑니다." << endl;
			//마을로 복귀
			return;

		default:
			//값을 잘못 입력한 경우 EnterInn() 재호출
			cout << "y 또는 n만 입력해주세요" << endl;
			break;
		}
	
	}
}

void Inn::UseInn(Character& character) {
	//10골드 차감 및 플레이어 체력 회복(수정 필요re)
	character.setgold(-10);
	character.health = character.maxhealth;//
	cout << "잔여 골드 수: "<< character.getgold() << endl;
	cout << "현재 체력: " << character.health << endl;
	//여관 이용 종료
	/*Logger::getInstance().logEvent("여관 이용 종료");*/
}