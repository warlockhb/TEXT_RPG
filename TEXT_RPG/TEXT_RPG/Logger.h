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
    // 蹂듭궗 �깮�꽦�옄 諛� ����엯 �뿰�궛�옄 �궘�젣
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& GetInstance();

    // �씪諛� 濡쒓렇 湲곕줉
    void LogEvent(const std::string& Entry);

    // 紐ъ뒪�꽣 泥섏튂 湲곕줉
    void RecordMonsterDefeated(const std::string& MonsterName);

    // �븘�씠�뀥 �궗�슜 湲곕줉
    void RecordItemUsed(const std::string& ItemName);

    // 怨⑤뱶 �쉷�뱷 湲곕줉
    void AddGold(int Amount);

    // 濡쒓렇 �쟾泥� 蹂닿린
    void ShowLogs() const;

    // �슂�빟 濡쒓렇 蹂닿린
    void ShowSummary() const;
};

#endif
