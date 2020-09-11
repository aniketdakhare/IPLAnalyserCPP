#pragma once
#include <list>
#include "SortedPlayerData.h"
#include "../model/utility/IPLAdapterFactory.h"
#include "../model/Enums/PlayerType.h"
#include "../Model/Enums/SortType.h"
#include "../Libraries/CSVReader.h"

using namespace std;

class IPLAnalyser : SortedPlayerData
{
    private:
        list<IPLPlayerDetails> iplMostRunsList;
        list<IPLPlayerDetails> iplMostWicketsList;

    public:
        void loadIPLData(string fileName, PlayerType playerType);
        list<IPLPlayerDetails> getSortedData(SortType sortType);
};

void IPLAnalyser :: loadIPLData(string fileName, PlayerType playerType)
{
    IPLAdapterFactory iplAdapterFactory;

    switch (playerType)
    {
        case BATSMAN:
            iplMostRunsList = iplAdapterFactory.getIPLData(fileName, playerType);
            break;
        case BOWLER:
            iplMostWicketsList = iplAdapterFactory.getIPLData(fileName, playerType);
            break;
    }
}

list<IPLPlayerDetails> IPLAnalyser :: getSortedData(SortType sortType)
{
    list<IPLPlayerDetails> playersList;
    switch(sortType)
    {
        case BATTING_AVERAGE:
            sortDataByBattingAverage(playersList, iplMostRunsList);
            break;
        case BATTING_STRIKE_RATE:
            sortDataByBattingStrikeRate(playersList, iplMostRunsList);
            break;
        case FOURS_AND_SIXES:
            sortDataByFoursAndSixes(playersList, iplMostRunsList);
            break;
        case STRIKE_RATE_WITH_SIX_AND_FOUR:
            sortDataByStrikeRateWithSixAndFour(playersList, iplMostRunsList);
            break;
        case BATTING_AVERAGE_WITH_STRIKE_RATE:
            sortDataByBattingAverageWithStrikeRate(playersList, iplMostRunsList);
            break;
        case RUNS_WITH_BATTING_AVERAGE:
            sortDataByRunsWithBattingAverage(playersList, iplMostRunsList);
            break;
        case BOWLING_AVERAGE:
            sortDataByBowlingAverage(playersList, iplMostWicketsList);
            break;
        case BOWLING_STRIKE_RATE:
            sortDataByBowlingStrikRate(playersList, iplMostWicketsList);
            break;
        case ECONOMY_RATE:
            sortDataByBowlingEconomyRate(playersList, iplMostWicketsList);
            break;
        case STRIKE_RATE_WITH_FOUR_AND_FIVE_WICKETS:
            sortDataByStrikeRateWithFourAndFiveWickets(playersList, iplMostWicketsList);
            break;
        case BOWLING_AVERAGE_WITH_STRIKE_RATE:
            sortDataByBowlingAverageWithStrikeRate(playersList, iplMostWicketsList);
            break;
        case WICKETS_WITH_BOWLING_AVERAGE:
            sortDataByWicketsWithBowlingAverage(playersList, iplMostWicketsList);
            break;
        case BATTING_AND_BOWLING_AVERAGE:
            sortDataByBowlingAndBattingAverage(playersList, iplMostRunsList, iplMostWicketsList);
            break;
        case MOST_RUNS_AND_WICKETS:
            sortDataByWicketsAndRuns(playersList, iplMostRunsList, iplMostWicketsList);
            break;
    }
    
    return playersList;
}