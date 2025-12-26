#pragma once
#include <vector>
#include <string>
#include <chrono>

struct GameRecord {
    std::string player1Name;
    std::string player2Name;
    std::string winner;
    std::string score;
    std::string mode;
    std::chrono::system_clock::time_point date;
};

class GameHistory {
private:
    std::vector<GameRecord> records;
    
public:
    GameHistory();

    void AddRecord(const GameRecord& record);
    const std::vector<GameRecord>& GetAllRecords() const { return records; }
    
    bool Load();
    bool Save();
    
    std::vector<GameRecord> GetRecordsByPlayer(const std::string& playerName) const;
};
