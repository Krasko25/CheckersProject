#pragma once
#include "Player.h"
#include "Board.h"
#include <chrono>
#include <string>
#include <vector>

enum class GameMode { 
    Unlimited, 
    Rapid_3min, 
    Blitz_5min, 
    Classic_10min, 
    Long_25min, 
    Rapid_3min_2sec, 
    Blitz_5min_3sec 
};

enum class GameState { NotStarted, InProgress, Finished };

enum class GameResult { WhiteWins, BlackWins, Draw };

class GameSession {
private:
    Player* playerWhite;
    Player* playerBlack;
    Board board;
    
    GameMode mode;
    GameState state;
    CheckerColor currentPlayer;
    
    std::chrono::seconds timeWhite;
    std::chrono::seconds timeBlack;
    std::chrono::system_clock::time_point startTime;
    
    std::vector<std::string> moveHistory;
    
    // Встраивание метода (метод GetPlayerByColor встроен в GetCurrentPlayer)
    Player* GetCurrentPlayer() const;
    
public:
    // Замена параметра метода (mode сделан обязательным)
    GameSession(Player* p1, Player* p2, GameMode mode);
    
    void Start();
    
    bool MakeMove(int fromX, int fromY, int toX, int toY);
    
    // Удаление параметра метода (удален параметр color, определяется автоматически)
    void Surrender();
    
    GameState GetState() const { return state; }
    GameResult GetResult() const;
    
    // Замена временной переменной (переменная hasTimer заменена на выражение)
    bool HasTimer() const { return mode != GameMode::Unlimited; }
    
    int GetTimeWhite() const { return static_cast<int>(timeWhite.count()); }
    int GetTimeBlack() const { return static_cast<int>(timeBlack.count()); }
    
    // Добавление параметра метода (добавлен updateBoth)
    void UpdateTimer(bool updateBoth = false);
    
    std::string GetModeName() const;
    
    struct GameInfo {
        std::string player1;
        std::string player2;
        std::string winner;
        std::string mode;
        std::string duration;
        int moves;
    };
    
    // Замена параметра метода (добавлен includeMoves)
    GameInfo GetGameInfo(bool includeMoves = false) const;
    
    // Перемещение метода
    std::chrono::seconds CalculateDuration() const;
};