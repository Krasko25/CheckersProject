#pragma once
#include <vector>
#include <string>
#include "Player.h"

class PlayerManager {
private:
    std::vector<Player> players;
    int nextId;
    
    // Встраивание метода (IsNameUnique в CreatePlayer)
    // Удаление параметра метода (avatarPath)
    Player* FindPlayerByName(const std::string& name);
    
    void SaveToFile() const;
    void LoadFromFile();

public:
    PlayerManager();
    
    // Замена параметра метода (avatarPath сделан обязательным)
    Player* CreatePlayer(const std::string& name, const std::string& avatarPath);
    bool DeletePlayer(int playerId);
    Player* GetPlayerById(int playerId);
    
    // Удаление параметра метода (удален avatarPath)
    Player* GetPlayerByName(const std::string& name);
    
    // Замена параметра метода
    enum class GameResult { Win, Loss, Draw };
    void UpdatePlayerStats(int playerId, GameResult result);
    
    const std::vector<Player>& GetAllPlayers() const { return players; }
    
    // Перемещение метода (метод GetTotalGames перемещен из Player)
    int GetTotalGamesPlayed() const;
};