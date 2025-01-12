// include/Logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>
#include <map>

class Logger {
private:
    std::vector<std::string> logs;
    std::map<std::string, int> monstersDefeated;
    std::map<std::string, int> itemsUsed;
    int totalGoldAcquired;

    Logger() : totalGoldAcquired(0) {}
public:
    // 복사 생성자 및 대입 연산자 삭제
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance();

    // 일반 로그 기록
    void logEvent(const std::string& entry);

    // 몬스터 처치 기록
    void recordMonsterDefeated(const std::string& monsterName);

    // 아이템 사용 기록
    void recordItemUsed(const std::string& itemName);

    // 골드 획득 기록
    void addGold(int amount);

    // 로그 전체 보기
    void showLogs() const;

    // 요약 로그 보기
    void showSummary() const;
};

#endif
