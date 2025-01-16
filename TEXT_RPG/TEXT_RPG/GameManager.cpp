﻿#include "GameManager.h"
#include "Logger.h"
#include "BattleManager.h"
#include "Character.h"
#include "Village.h"
#include <cstdlib>
#include <ctime>
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
	cout << "캐릭터 이름을 고르세요 :";
	string name;
	cin >> name;
	MyCharacter = Character::GetInstance(name);
	Logger::GetInstance().LogEvent("캐릭터가 생성되었습니다: " + name);
}

bool GameManager::ShowMenu()
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
	Village village;
	switch (choice)
	{
	case 1:
		{
			battleManager->StartBattle();
			if (battleManager->GetBattleState() == 2)
			{
				int getexp = rand() % 31 + 20;
				MyCharacter->GainExp(getexp);
				MyCharacter->LevelUp();
				village.ShowChoice(*MyCharacter);
			}
			else if (battleManager->GetBattleState() == 3)
			{
				Logger::GetInstance().ShowSummary();
				return false;
			}
			
			break;
		}
	case 2:
		MyCharacter->DisPlayStatus();
		break;
	case 3:
		Logger::GetInstance().ShowLogs();
		break;
	case 4:
		Logger::GetInstance().ShowSummary();
		break;
	case 5:
		cout << "게임을 종료합니다." << endl;
		Logger::GetInstance().ShowSummary();
		return false;
		break;
	}
	return true;
}
