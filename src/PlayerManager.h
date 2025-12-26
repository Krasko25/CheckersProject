#pragma once
#include <vector>
#include <string>
#include "Player.h"

class PlayerManager {
private:
    std::vector<Player> players;
    int nextId;
    
    Player* FindPlayerByName(const std::string& name);
    
    void SaveToFile() const;
    void LoadFromFile();

    // Консолидация дублирующихся условных фрагментов
    bool CanCreatePlayer(const std::string& name, const std::string& avatarPath) const;

public:
    PlayerManager();
    
    Player* CreatePlayer(const std::string& name, const std::string& avatarPath);
    
    bool DeletePlayer(int playerId);
    Player* GetPlayerById(int playerId);
    
    Player* GetPlayerByName(const std::string& name);
    
    enum class GameResult { Win, Loss, Draw };
    void UpdatePlayerStats(int playerId, GameResult result);
    
    const std::vector<Player>& GetAllPlayers() const { return players; }
    
    int GetTotalGamesPlayed() const;
};