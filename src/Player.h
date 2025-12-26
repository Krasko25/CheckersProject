#pragma once
#include <string>
#include <chrono>

using DateTime = std::chrono::system_clock::time_point;

class Player {
private:
    int id;
    std::string name;
    std::string avatarPath;
    int wins;
    int losses;
    int draws;
    DateTime createdDate;

public:
    Player(int id, const std::string& name, const std::string& avatarPath = "");
    ~Player() = default;
    
    int GetId() const { return id; }
    const std::string& GetName() const { return name; }
    const std::string& GetAvatarPath() const { return avatarPath; }
    int GetWins() const { return wins; }
    int GetLosses() const { return losses; }
    int GetDraws() const { return draws; }
    DateTime GetCreatedDate() const { return createdDate; }
    
    void SetName(const std::string& newName);
    void SetAvatarPath(const std::string& newPath);
    // методы изменения статистики
    void AddWin() { wins++; }
    void AddLoss() { losses++; }
    void AddDraw() { draws++; }
    
    int GetTotalGames() const { return wins + losses + draws; }
