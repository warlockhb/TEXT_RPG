// src/Logger.cpp
#include "Logger.h"
#include <iostream>

// GetInstance 메서드 구현
Logger& Logger::GetInstance() {
    static Logger Instance;
    return Instance;
}

// LogEvent 메서드 구현
void Logger::LogEvent(const std::string& Entry) {
    Logs.push_back(Entry);
    std::cout << Entry << std::endl; // 실시간으로 콘솔에 출력
}

// RecordMonsterDefeated 메서드 구현
void Logger::RecordMonsterDefeated(const std::string& MonsterName) {
    MonstersDefeated[MonsterName]++; // 몬스터 처치 수 ++
    LogEvent("Monster defeated: " + MonsterName); // 로그 기록 추가 (선택 사항)
}

// RecordItemUsed 메서드 구현
void Logger::RecordItemUsed(const std::string& ItemName) {
    ItemsUsed[ItemName]++; // 아이템 사용 수 ++
    LogEvent("Item used: " + ItemName); // 로그 기록 추가 (선택 사항)
}

// AddGold 메서드 구현
void Logger::AddGold(int Amount) {
    TotalGoldAcquired += Amount; // 총 골드 획득량
    LogEvent("Gold acquired: " + std::to_string(Amount)); // 로그 기록 추가 (선택 사항)
}

// ShowLogs 메서드 구현
void Logger::ShowLogs() const {
    std::cout << "----- 게임 로그 -----" << std::endl;
    for (const auto& Entry : Logs) {
        std::cout << Entry << std::endl;
    }
}

// ShowSummary 메서드 구현
void Logger::ShowSummary() const {
    std::cout << "\n----- 게임 요약 -----" << std::endl;

    // 몬스터 처치 내역
    std::cout << "처치한 몬스터:" << std::endl;
    if (MonstersDefeated.empty()) {
        std::cout << "없음" << std::endl;
    }
    else {
        for (const auto& Pair : MonstersDefeated) {
            const std::string& Monster = Pair.first;
            int Count = Pair.second;
            std::cout << Monster << " - " << Count << "마리" << std::endl;
        }
    }

    // 아이템 사용 내역
    std::cout << "사용한 아이템:" << std::endl;
    if (ItemsUsed.empty()) {
        std::cout << "없음" << std::endl;
    }
    else {
        for (const auto& Pair : ItemsUsed) {
            const std::string& Item = Pair.first;
            int Count = Pair.second;
            std::cout << Item << " - " << Count << "개" << std::endl;
        }
    }

    // 총 골드 획득
    std::cout << "총 골드 획득: " << TotalGoldAcquired << "골드";
    std::cin.get();
    std::cin.get();
}
