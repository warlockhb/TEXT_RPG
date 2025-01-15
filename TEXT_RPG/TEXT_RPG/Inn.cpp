#include "Inn.h"
#include "Character.h"

#include <iostream>

using namespace std;


void Inn::EnterInn(Character& character) {
	string choice = "";
	

	while (true)
	{
		cout << "여관에 입장했습니다" << endl;
		cout << "---<<  여관  >>---" << endl;
		cout << "-  이용료  : 10G -" << endl;
		cout << "------------------" << endl;
		cout << "여관을 사용하겠습니까?(y/n): ";
		
		cin >> choice;

		if (choice == "y"){
			if (character.GetGold() < INN_COST) {
				//골드가 부족한 경우 -> 마을로 복귀
				cout << "골드가 부족하여 마을로 돌아갑니다." << endl;
				return;
			}
			else {
				//골드가 충분한 경우 여관 이용 후 마을로 복귀
				cout << "여관 이용중.." << endl;
				UseInn(character);
				//마을로 복귀
				cout << "마을로 돌아갑니다." << endl;
				return;
			}
		}
		else if (choice == "n"){
			//여관 이용X 선택한 경우 -> 마을로 복귀
			cout << "여관 이용을 거부했습니다. 마을로 돌아갑니다." << endl;
			return;
		}
		else{
			//값을 잘못 입력한 경우 EnterInn() 재호출
			cout << "y 또는 n만 입력해주세요." << endl;
		}
	
	}
}

void Inn::UseInn(Character& character) {
	//10골드 차감
	character.LoseGold(INN_COST);

	//플레이어 체력 회복
	int recover = character.GetMaxHealth() - character.GetHealth();
	character.AddGold(recover);
}