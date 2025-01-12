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
    // ���� ������ �� ���� ������ ����
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance();

    // �Ϲ� �α� ���
    void logEvent(const std::string& entry);

    // ���� óġ ���
    void recordMonsterDefeated(const std::string& monsterName);

    // ������ ��� ���
    void recordItemUsed(const std::string& itemName);

    // ��� ȹ�� ���
    void addGold(int amount);

    // �α� ��ü ����
    void showLogs() const;

    // ��� �α� ����
    void showSummary() const;
};

#endif
