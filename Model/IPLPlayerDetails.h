#pragma once
#include <string>

using namespace std;

class IPLPlayerDetails
{
    public:
        string player;
        double battingAverage;
        double bowlingAverage;
        double battingStrikeRates;
        double bowlingStrikeRates;
        int fours;
        int sixes;
        int runs;
        int fourWickets;
        int fiveWickets;
        double economyRates;
        int wickets;
};