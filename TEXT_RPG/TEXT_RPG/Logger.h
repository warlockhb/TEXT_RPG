// include/Logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>
#include <map>

class Logger {
private:
    std::vector<std::string> Logs;
    std::map<std::string, int> MonstersDefeated;
    std::map<std::string, int> ItemsUsed;
    int TotalGoldAcquired;

    Logger() : TotalGoldAcquired(0) {}
public:
    // 복사 생성자 및 대입 연산자 삭제
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& GetInstance();

    // 일반 로그 기록
    void LogEvent(const std::string& Entry);

    // 몬스터 처치 기록
    void RecordMonsterDefeated(const std::string& MonsterName);

    // 아이템 사용 기록
    void RecordItemUsed(const std::string& ItemName);

    // 골드 획득 기록
    void AddGold(int Amount);

    // 로그 전체 보기
    void ShowLogs() const;

    // 요약 로그 보기
    void ShowSummary() const;
};

#endif
