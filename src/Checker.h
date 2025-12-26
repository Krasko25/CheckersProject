#pragma once

enum class CheckerType { Regular, King };
enum class CheckerColor { White, Black };

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
