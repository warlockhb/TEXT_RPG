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
    // ���� ������ �� ���� ������ ����
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& GetInstance();

    // �Ϲ� �α� ���
    void LogEvent(const std::string& Entry);

    // ���� óġ ���
    void RecordMonsterDefeated(const std::string& MonsterName);

    // ������ ��� ���
    void RecordItemUsed(const std::string& ItemName);

    // ��� ȹ�� ���
    void AddGold(int Amount);

    // �α� ��ü ����
    void ShowLogs() const;

    // ��� �α� ����
    void ShowSummary() const;
};

#endif
