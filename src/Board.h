#pragma once
#include <array>
#include <vector>

enum class CheckerColor { White, Black };
enum class CheckerType { Regular, King };

class Checker {
private:
    CheckerType type;
    CheckerColor color;
    
public:
    Checker(CheckerColor color, CheckerType type = CheckerType::Regular);
    
    CheckerType GetType() const { return type; }
    CheckerColor GetColor() const { return color; }
    
    void PromoteToKing() { type = CheckerType::King; }
    
    bool IsKing() const { return type == CheckerType::King; }
    bool IsWhite() const { return color == CheckerColor::White; }
    bool IsBlack() const { return color == CheckerColor::Black; }
};

struct Move {
    int fromX, fromY, toX, toY;
    
    Move(int fx, int fy, int tx, int ty);
};

class Board {
private:
    std::array<std::array<Checker*, BOARD_SIZE>, BOARD_SIZE> grid;
    
    // спуск поля, флаг для многоходового взятия (специфика шашек)
    bool isMultiCaptureInProgress;
    
    bool IsValidPosition(int x, int y) const;
    
    // спуск метода, разделение общего метод на отдельные
    std::vector<Move> GetPossibleMovesForRegular(int x, int y) const;
    std::vector<Move> GetPossibleMovesForKing(int x, int y) const;
    
    // подъём метода, общие проверки для всех типов шашек
    bool IsWithinBoard(int x, int y) const;
    bool IsDiagonalMove(int fromX, int fromY, int toX, int toY) const;

public:
    Board();
    ~Board();
    void Initialize();
    
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

// подъём метода, общие функции для работы с доской
namespace BoardUtils {
    bool IsBlackCell(int x, int y);
    bool IsWhiteCell(int x, int y);
}