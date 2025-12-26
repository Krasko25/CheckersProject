#pragma once
#include <array>
#include <vector>
#include "Checker.h"

struct Move {
    int fromX, fromY, toX, toY;
};

class Board {
private:
    std::array<std::array<Checker*, 8>, 8> grid;
    
    bool IsValidPosition(int x, int y) const;
    std::vector<Move> GetPossibleMovesForChecker(int x, int y) const;
    bool CanCaptureFrom(int x, int y) const;

public:
    Board();
    ~Board();
    void Initialize();  // расстановка шашек в начальную позицию
    
    Checker* GetCheckerAt(int x, int y) const;
    void SetCheckerAt(int x, int y, Checker* checker);
    bool MakeMove(int fromX, int fromY, int toX, int toY);
    void RemoveChecker(int x, int y);
    void PromoteToKing(int x, int y);
    bool IsGameOver() const;
    int CountCheckers(CheckerColor color) const;
    
    CheckerColor GetWinner() const;
    bool HasLegalMoves(CheckerColor color) const;
};
