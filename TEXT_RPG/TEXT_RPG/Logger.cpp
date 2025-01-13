// src/Logger.cpp
#include "Logger.h"
#include <iostream>

// GetInstance �޼��� ����
Logger& Logger::GetInstance() {
    static Logger Instance;
    return Instance;
}

// LogEvent �޼��� ����
void Logger::LogEvent(const std::string& Entry) {
    Logs.push_back(Entry);
    std::cout << Entry << std::endl; // �ǽð����� �ֿܼ� ���
}

// RecordMonsterDefeated �޼��� ����
void Logger::RecordMonsterDefeated(const std::string& MonsterName) {
    MonstersDefeated[MonsterName]++; // ���� óġ �� ++
    LogEvent("Monster defeated: " + MonsterName); // �α� ��� �߰� (���� ����)
}

// RecordItemUsed �޼��� ����
void Logger::RecordItemUsed(const std::string& ItemName) {
    ItemsUsed[ItemName]++; // ������ ��� �� ++
    LogEvent("Item used: " + ItemName); // �α� ��� �߰� (���� ����)
}

// AddGold �޼��� ����
void Logger::AddGold(int Amount) {
    TotalGoldAcquired += Amount; // �� ��� ȹ�淮
    LogEvent("Gold acquired: " + std::to_string(Amount)); // �α� ��� �߰� (���� ����)
}

// ShowLogs �޼��� ����
void Logger::ShowLogs() const {
    std::cout << "----- ���� �α� -----" << std::endl;
    for (const auto& Entry : Logs) {
        std::cout << Entry << std::endl;
    }
}

// ShowSummary �޼��� ����
void Logger::ShowSummary() const {
    std::cout << "\n----- ���� ��� -----" << std::endl;

    // ���� óġ ����
    std::cout << "óġ�� ����:" << std::endl;
    if (MonstersDefeated.empty()) {
        std::cout << "����" << std::endl;
    }
    else {
        for (const auto& Pair : MonstersDefeated) {
            const std::string& Monster = Pair.first;
            int Count = Pair.second;
            std::cout << Monster << " - " << Count << "����" << std::endl;
        }
    }

    // ������ ��� ����
    std::cout << "����� ������:" << std::endl;
    if (ItemsUsed.empty()) {
        std::cout << "����" << std::endl;
    }
    else {
        for (const auto& Pair : ItemsUsed) {
            const std::string& Item = Pair.first;
            int Count = Pair.second;
            std::cout << Item << " - " << Count << "��" << std::endl;
        }
    }

    // �� ��� ȹ��
    std::cout << "�� ��� ȹ��: " << TotalGoldAcquired << "���" << std::endl;
}
