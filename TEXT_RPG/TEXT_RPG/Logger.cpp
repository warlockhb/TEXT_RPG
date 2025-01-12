// src/Logger.cpp
#include "Logger.h"
#include <iostream>

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::logEvent(const std::string& entry) {
    logs.push_back(entry);
    std::cout << entry << std::endl; // �ǽð����� �ֿܼ� ���
}

void Logger::recordMonsterDefeated(const std::string& monsterName) {
    monstersDefeated[monsterName]++; //���� óġ �� ++
}

void Logger::recordItemUsed(const std::string& itemName) {
    itemsUsed[itemName]++; //������ ��� �� ++
}

void Logger::addGold(int amount) {
    totalGoldAcquired += amount;// �� ��� ȹ�淮
}

void Logger::showLogs() const {
    std::cout << "----- ���� �α� -----" << std::endl;
    for (const auto& entry : logs) {
        std::cout << entry << std::endl;
    }
}

void Logger::showSummary() const {
    std::cout << "\n----- ���� ��� -----" << std::endl;

    // ���� óġ ����
    std::cout << "óġ�� ����:" << std::endl;
    if (monstersDefeated.empty()) {
        std::cout << "����" << std::endl;
    }
    else {
        for (const auto& pair : monstersDefeated) {
            const std::string& monster = pair.first;
            int count = pair.second;
            std::cout << monster << " - " << count << "����" << std::endl;
        }
    }

    // ������ ��� ����
    std::cout << "����� ������:" << std::endl;
    if (itemsUsed.empty()) {
        std::cout << "����" << std::endl;
    }
    else {
        for (const auto& pair : itemsUsed) {
            const std::string& item = pair.first;
            int count = pair.second;
            std::cout << item << " - " << count << "��" << std::endl;
        }
    }

    // �� ��� ȹ��
    std::cout << "�� ��� ȹ��: " << totalGoldAcquired << "���" << std::endl;
}
