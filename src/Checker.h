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
    
    // Встраивание метода (метод PromoteToKing встроен в SetType)
    void SetType(CheckerType newType) { type = newType; }
    
    // Замена временной переменной (переменные isKing, isWhite, isBlack удалены)
    bool IsKing() const { return type == CheckerType::King; }
    
    // Встраивание метода (методы IsWhite/IsBlack встроены в проверки)
    bool IsColor(CheckerColor checkColor) const { return color == checkColor; }
};