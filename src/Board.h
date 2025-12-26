#pragma once
#include <array>
#include <vector>
#include "Checker.h"

struct Move {
    int fromX, fromY, toX, toY;
    bool isCapture;
    
    Move(int fx, int fy, int tx, int ty, bool capture = false);
};

class Board {
private:
    std::array<std::array<Checker*, 8>, 8> grid;
    
    // замена временной переменной (valid заменена на выражение)
    bool IsValidPosition(int x, int y) const;
    
    // Встраивание метода (CanCaptureFrom встроен в GetPossibleMovesForChecker)
    std::vector<Move> GetPossibleMovesForChecker(int x, int y) const;
    
    // Добавление параметра метода (добавлен параметр validateMove)
    bool ExecuteMove(int fromX, int fromY, int toX, int toY, bool validateMove = true);

public:
    Board();
    ~Board();
    void Initialize();
    
    Checker* GetCheckerAt(int x, int y) const;
    void SetCheckerAt(int x, int y, Checker* checker);
    
    bool MakeMove(int fromX, int fromY, int toX, int toY, bool forceMove = false);
    
    void RemoveChecker(int x, int y);
    void PromoteToKing(int x, int y);
    bool IsGameOver() const;
    int CountCheckers(CheckerColor color) const;
    
    CheckerColor GetWinner() const;
    bool HasLegalMoves(CheckerColor color) const;
    
    // Выделение метода
    std::vector<Move> GetAllPossibleMoves(CheckerColor color) const;
};