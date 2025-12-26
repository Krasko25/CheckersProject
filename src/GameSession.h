#pragma once
#include "Player.h"
#include "Board.h"
#include <chrono>
#include <string>
#include <vector>

enum class GameMode { Unlimited, Rapid_3min, Blitz_5min, Classic_10min, Long_25min, Rapid_3min_2sec, Blitz_5min_3sec };

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
    
    // таймеры
    std::chrono::seconds timeWhite;
    std::chrono::seconds timeBlack;
    
    std::vector<std::string> moveHistory;
public:
    GameSession(Player* p1 = nullptr, Player* p2 = nullptr, 
                GameMode mode = GameMode::Classic_10min);

    void Start();
    bool MakeMove(int fromX, int fromY, int toX, int toY);
    void Surrender(CheckerColor color);
    
    // геттеры
    GameState GetState() const { return state; }
    GameResult GetResult() const;
    Player* GetCurrentPlayer() const;

    // таймеры
    bool HasTimer() const { return mode != GameMode::Unlimited; }
    int GetTimeWhite() const { return static_cast<int>(timeWhite.count()); }
    int GetTimeBlack() const { return static_cast<int>(timeBlack.count()); }
    void UpdateTimer();
    
    std::string GetModeName() const;
    
    // Для истории (используется GameHistory)
    struct GameInfo {
        std::string player1;
        std::string player2;
        std::string winner;
        std::string mode;
        std::string duration; // "5:30"
        int moves;
    };
    
    GameInfo GetGameInfo() const;
};
