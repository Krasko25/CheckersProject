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
    
    // Выделение метода (новый метод)
    std::string GetFormattedDate() const;
};

class GameHistory {
private:
    std::vector<GameRecord> records;
    std::string filePath;
    
public:
    // Добавление параметра метода (добавлен filePath)
    GameHistory(const std::string& filePath = "game_history.dat");

    // Замена параметра метода (параметры разделены вместо структуры)
    void AddRecord(const std::string& player1, const std::string& player2, 
                   const std::string& winner, const std::string& score, 
                   const std::string& mode);
    
    const std::vector<GameRecord>& GetAllRecords() const { return records; }
    
    bool Load();
    bool Save();
    
    std::vector<GameRecord> GetRecordsByPlayer(const std::string& playerName) const;
};