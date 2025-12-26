#pragma once
#include <vector>
#include <string>
#include "Player.h"

class PlayerManager {
private:
    std::vector<Player> players;
    int nextId;
    
    bool IsNameUnique(const std::string& name) const;
    void SaveToFile() const;
    void LoadFromFile();

public:
    PlayerManager();
    
    Player* CreatePlayer(const std::string& name, const std::string& avatarPath = "");
    bool DeletePlayer(int playerId);
    Player* GetPlayerById(int playerId);
    Player* GetPlayerByName(const std::string& name);
    
    void UpdatePlayerStats(int playerId, bool won, bool draw);
    const std::vector<Player>& GetAllPlayers() const { return players; }
};
