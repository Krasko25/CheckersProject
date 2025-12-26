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
    
    bool IsValidPosition(int x, int y) const;
    
    //декомпозиция условного оператора, разделяем логику
    std::vector<Move> GetPossibleMovesForChecker(int x, int y) const;
    std::vector<Move> GetCaptureMoves(int x, int y) const;
    std::vector<Move> GetRegularMoves(int x, int y) const;
    
    bool ExecuteMove(int fromX, int fromY, int toX, int toY, bool validateMove = true);

    // консолидация условного выражения
    bool IsMoveWithinBoard(int fromX, int fromY, int toX, int toY) const;

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
    
    std::vector<Move> GetAllPossibleMoves(CheckerColor color) const;
};