// src/Logger.cpp
#include "Logger.h"
#include <iostream>

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::logEvent(const std::string& entry) {
    logs.push_back(entry);
    std::cout << entry << std::endl; // 실시간으로 콘솔에 출력
}

void Logger::recordMonsterDefeated(const std::string& monsterName) {
    monstersDefeated[monsterName]++; //몬스터 처치 수 ++
}

void Logger::recordItemUsed(const std::string& itemName) {
    itemsUsed[itemName]++; //아이템 사용 수 ++
}

void Logger::addGold(int amount) {
    totalGoldAcquired += amount;// 총 골드 획득량
}

void Logger::showLogs() const {
    std::cout << "----- 게임 로그 -----" << std::endl;
    for (const auto& entry : logs) {
        std::cout << entry << std::endl;
    }
}

void Logger::showSummary() const {
    std::cout << "\n----- 게임 요약 -----" << std::endl;

    // 몬스터 처치 내역
    std::cout << "처치한 몬스터:" << std::endl;
    if (monstersDefeated.empty()) {
        std::cout << "없음" << std::endl;
    }
    else {
        for (const auto& pair : monstersDefeated) {
            const std::string& monster = pair.first;
            int count = pair.second;
            std::cout << monster << " - " << count << "마리" << std::endl;
        }
    }

    // 아이템 사용 내역
    std::cout << "사용한 아이템:" << std::endl;
    if (itemsUsed.empty()) {
        std::cout << "없음" << std::endl;
    }
    else {
        for (const auto& pair : itemsUsed) {
            const std::string& item = pair.first;
            int count = pair.second;
            std::cout << item << " - " << count << "개" << std::endl;
        }
    }

    // 총 골드 획득
    std::cout << "총 골드 획득: " << totalGoldAcquired << "골드" << std::endl;
}
