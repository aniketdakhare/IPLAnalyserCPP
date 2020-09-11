#pragma once
#include <list>
#include "IPLPlayerDetails.h"
using namespace std;

class SortedPlayerData
{
    private:
        list<IPLPlayerDetails> getAllrounderPlayers(list<IPLPlayerDetails> , list<IPLPlayerDetails>);

    protected:
        void sortDataByBattingAverage(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByBattingStrikeRate(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByFoursAndSixes(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByStrikeRateWithSixAndFour(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByBattingAverageWithStrikeRate(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByRunsWithBattingAverage(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByBowlingAverage(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByBowlingStrikRate(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByBowlingEconomyRate(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByStrikeRateWithFourAndFiveWickets(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByBowlingAverageWithStrikeRate(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByWicketsWithBowlingAverage(list<IPLPlayerDetails>& , list<IPLPlayerDetails>);
        void sortDataByBowlingAndBattingAverage(list<IPLPlayerDetails>& , list<IPLPlayerDetails> , list<IPLPlayerDetails>);
        void sortDataByWicketsAndRuns(list<IPLPlayerDetails>& , list<IPLPlayerDetails> , list<IPLPlayerDetails>);
};

void SortedPlayerData :: sortDataByBattingAverage(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostRunsList)
{
    playersList = iplMostRunsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return firstPlayer.battingAverage > secondPlayer.battingAverage; });
}

void SortedPlayerData :: sortDataByBattingStrikeRate(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostRunsList)
{
    playersList = iplMostRunsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return firstPlayer.battingStrikeRates > secondPlayer.battingStrikeRates; });
}

void SortedPlayerData :: sortDataByFoursAndSixes(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostRunsList)
{
    playersList = iplMostRunsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return (firstPlayer.fours + firstPlayer.sixes) > (secondPlayer.fours +secondPlayer.sixes); });
}

void SortedPlayerData :: sortDataByStrikeRateWithSixAndFour(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostRunsList)
{
    playersList = iplMostRunsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return firstPlayer.battingStrikeRates > secondPlayer.battingStrikeRates && 
    (firstPlayer.fours + firstPlayer.sixes) > (secondPlayer.fours +secondPlayer.sixes); });
}

void SortedPlayerData :: sortDataByBattingAverageWithStrikeRate(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostRunsList)
{
    playersList = iplMostRunsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return firstPlayer.battingAverage > secondPlayer.battingAverage && firstPlayer.battingStrikeRates > secondPlayer.battingStrikeRates; });
}

void SortedPlayerData :: sortDataByRunsWithBattingAverage(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostRunsList)
{
    playersList = iplMostRunsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return firstPlayer.runs > secondPlayer.runs && firstPlayer.battingAverage > secondPlayer.battingAverage; });
}

void SortedPlayerData :: sortDataByBowlingAverage(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostWicketsList)
{
    playersList = iplMostWicketsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return (firstPlayer.bowlingAverage != 0 && secondPlayer.bowlingAverage != 0) ? firstPlayer.bowlingAverage < secondPlayer.bowlingAverage : bool(); });
}

void SortedPlayerData :: sortDataByBowlingStrikRate(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostWicketsList)
{
    playersList = iplMostWicketsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return (firstPlayer.bowlingStrikeRates != 0 && secondPlayer.bowlingStrikeRates != 0) ? firstPlayer.bowlingStrikeRates < secondPlayer.bowlingStrikeRates : bool(); });
}

void SortedPlayerData :: sortDataByBowlingEconomyRate(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostWicketsList)
{
    playersList = iplMostWicketsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return firstPlayer.bowlingStrikeRates < secondPlayer.bowlingStrikeRates; });
}

void SortedPlayerData :: sortDataByStrikeRateWithFourAndFiveWickets(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostWicketsList)
{
    playersList = iplMostWicketsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return ((firstPlayer.bowlingStrikeRates != 0 && secondPlayer.bowlingStrikeRates != 0) ? firstPlayer.bowlingStrikeRates < secondPlayer.bowlingStrikeRates : bool()) && 
    (firstPlayer.fiveWickets + firstPlayer.fourWickets) > (secondPlayer.fiveWickets + secondPlayer.fourWickets); });
}

void SortedPlayerData :: sortDataByBowlingAverageWithStrikeRate(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostWicketsList)
{
    playersList = iplMostWicketsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return ((firstPlayer.bowlingAverage != 0 && secondPlayer.bowlingAverage != 0) ? firstPlayer.bowlingAverage < secondPlayer.bowlingAverage : bool()) &&
    ((firstPlayer.bowlingStrikeRates != 0 && secondPlayer.bowlingStrikeRates != 0) ? firstPlayer.bowlingStrikeRates < secondPlayer.bowlingStrikeRates : bool()); });
}

void SortedPlayerData :: sortDataByWicketsWithBowlingAverage(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostWicketsList)
{
    playersList = iplMostWicketsList;
    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return ((firstPlayer.bowlingAverage != 0 && secondPlayer.bowlingAverage != 0) ? firstPlayer.bowlingAverage < secondPlayer.bowlingAverage : bool()) &&
    firstPlayer.wickets > secondPlayer.wickets; });
}

list<IPLPlayerDetails> SortedPlayerData :: getAllrounderPlayers(list<IPLPlayerDetails> iplMostRunsList, list<IPLPlayerDetails> iplMostWicketsList)
{
    list<IPLPlayerDetails> playersList;
    for (auto battingData = iplMostRunsList.begin(); battingData != iplMostRunsList.end(); battingData++)
    {
        for (auto bowlingData = iplMostWicketsList.begin(); bowlingData != iplMostWicketsList.end(); bowlingData++)
        {
            if (battingData->player == bowlingData->player)
            {
                IPLPlayerDetails playerDetails;
                playerDetails.player = battingData->player;
                playerDetails.battingAverage = battingData->battingAverage;
                playerDetails.bowlingAverage = bowlingData->bowlingAverage;
                playerDetails.runs = battingData->runs;
                playerDetails.wickets = bowlingData->wickets;
                playersList.push_back(playerDetails);
            }
        }
    }

    return playersList;
}

void SortedPlayerData :: sortDataByBowlingAndBattingAverage(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostRunsList, list<IPLPlayerDetails> iplMostWicketsList)
{
    playersList = getAllrounderPlayers(iplMostRunsList, iplMostWicketsList);

    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return ((firstPlayer.bowlingAverage != 0 && secondPlayer.bowlingAverage != 0) ? firstPlayer.bowlingAverage < secondPlayer.bowlingAverage : bool()) &&
    firstPlayer.battingAverage > secondPlayer.battingAverage; });
}

void SortedPlayerData :: sortDataByWicketsAndRuns(list<IPLPlayerDetails>& playersList, list<IPLPlayerDetails> iplMostRunsList, list<IPLPlayerDetails> iplMostWicketsList)
{
    playersList = getAllrounderPlayers(iplMostRunsList, iplMostWicketsList);

    playersList.sort([](const IPLPlayerDetails firstPlayer, const IPLPlayerDetails secondPlayer)
    {return  firstPlayer.wickets > secondPlayer.wickets && firstPlayer.runs > secondPlayer.runs; });
}