#include "GameManager.h"
#include "Logger.h"
#include "BattleManager.h"
#include "Character.h"
#include <iostream>
using namespace std;


void GameManager::StartGame()
{
	if (MyCharacter == nullptr)
	{
		GenerateCharacter();
	}
}
void GameManager::GenerateCharacter()
{
	cout << "캐릭터 이름을 입력하시오:";
	string name;
	cin >> name;
	MyCharacter = Character::GetInstance(name);
	Logger::GetInstance().LogEvent("캐릭터가 생성되었습니다: " + name);
}

void GameManager::ShowMenu()
{
	::cout << "\n----- 메인 메뉴 -----" << endl;
	::cout << "1. 전투 시작" << endl;
	::cout << "2. 캐릭터 상태 확인" << endl;
	::cout << "3. 게임 로그 보기" << endl;
	::cout << "4. 게임 요약 보기" << endl;
	::cout << "5. 종료" << endl;
	::cout << "선택: ";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}
}
