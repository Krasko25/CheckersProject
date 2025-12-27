#pragma once

// подъем метода, вынос общих статистических методов
class StatisticsHelper {
public:
    static double CalculateWinRate(int wins, int totalGames);
    static double CalculateLossRate(int losses, int totalGames);
    static double CalculateDrawRate(int draws, int totalGames);
};