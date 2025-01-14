// src/Logger.cpp
#include "Logger.h"
#include <iostream>

// GetInstance 硫붿꽌�뱶 援ы쁽
Logger& Logger::GetInstance() {
    static Logger Instance;
    return Instance;
}

// LogEvent 硫붿꽌�뱶 援ы쁽
void Logger::LogEvent(const std::string& Entry) {
    Logs.push_back(Entry);
    std::cout << Entry << std::endl; // �떎�떆媛꾩쑝濡� 肄섏넄�뿉 異쒕젰
}

// RecordMonsterDefeated 硫붿꽌�뱶 援ы쁽
void Logger::RecordMonsterDefeated(const std::string& MonsterName) {
    MonstersDefeated[MonsterName]++; // 紐ъ뒪�꽣 泥섏튂 �닔 ++
    LogEvent("Monster defeated: " + MonsterName); // 濡쒓렇 湲곕줉 異붽�� (�꽑�깮 �궗�빆)
}

// RecordItemUsed 硫붿꽌�뱶 援ы쁽
void Logger::RecordItemUsed(const std::string& ItemName) {
    ItemsUsed[ItemName]++; // �븘�씠�뀥 �궗�슜 �닔 ++
    LogEvent("Item used: " + ItemName); // 濡쒓렇 湲곕줉 異붽�� (�꽑�깮 �궗�빆)
}

// AddGold 硫붿꽌�뱶 援ы쁽
void Logger::AddGold(int Amount) {
    TotalGoldAcquired += Amount; // 珥� 怨⑤뱶 �쉷�뱷�웾
    LogEvent("Gold acquired: " + std::to_string(Amount)); // 濡쒓렇 湲곕줉 異붽�� (�꽑�깮 �궗�빆)
}

// ShowLogs 硫붿꽌�뱶 援ы쁽
void Logger::ShowLogs() const {
    std::cout << "----- 寃뚯엫 濡쒓렇 -----" << std::endl;
    for (const auto& Entry : Logs) {
        std::cout << Entry << std::endl;
    }
}

// ShowSummary 硫붿꽌�뱶 援ы쁽
void Logger::ShowSummary() const {
    std::cout << "\n----- 寃뚯엫 �슂�빟 -----" << std::endl;

    // 紐ъ뒪�꽣 泥섏튂 �궡�뿭
    std::cout << "泥섏튂�븳 紐ъ뒪�꽣:" << std::endl;
    if (MonstersDefeated.empty()) {
        std::cout << "�뾾�쓬" << std::endl;
    }
    else {
        for (const auto& Pair : MonstersDefeated) {
            const std::string& Monster = Pair.first;
            int Count = Pair.second;
            std::cout << Monster << " - " << Count << "留덈━" << std::endl;
        }
    }

    // �븘�씠�뀥 �궗�슜 �궡�뿭
    std::cout << "�궗�슜�븳 �븘�씠�뀥:" << std::endl;
    if (ItemsUsed.empty()) {
        std::cout << "�뾾�쓬" << std::endl;
    }
    else {
        for (const auto& Pair : ItemsUsed) {
            const std::string& Item = Pair.first;
            int Count = Pair.second;
            std::cout << Item << " - " << Count << "媛�" << std::endl;
        }
    }

    // 珥� 怨⑤뱶 �쉷�뱷
    std::cout << "珥� 怨⑤뱶 �쉷�뱷: " << TotalGoldAcquired << "怨⑤뱶" << std::endl;
}
