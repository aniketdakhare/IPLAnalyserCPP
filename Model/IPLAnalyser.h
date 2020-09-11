#pragma once
#include <list>
#include "../model/utility/IPLAdapterFactory.h"
#include "../model/Enums/PlayerType.h"
#include "../Model/Enums/SortType.h"
#include "../Libraries/CSVReader.h"

using namespace std;

class IPLAnalyser
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
            playersList = iplMostRunsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return firstBatsman.battingAverage > secondBatsman.battingAverage; });
            break;
        case BATTING_STRIKE_RATE:
            playersList = iplMostRunsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return firstBatsman.battingStrikeRates > secondBatsman.battingStrikeRates; });
            break;
        case FOURS_AND_SIXES:
            playersList = iplMostRunsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return (firstBatsman.fours + firstBatsman.sixes) > (secondBatsman.fours +secondBatsman.sixes); });
            break;
        case STRIKE_RATE_WITH_SIX_AND_FOUR:
            playersList = iplMostRunsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return firstBatsman.battingStrikeRates > secondBatsman.battingStrikeRates && (firstBatsman.fours + firstBatsman.sixes) > (secondBatsman.fours +secondBatsman.sixes); });
            break;
        case BATTING_AVERAGE_WITH_STRIKE_RATE:
            playersList = iplMostRunsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return firstBatsman.battingAverage > secondBatsman.battingAverage && firstBatsman.battingStrikeRates > secondBatsman.battingStrikeRates; });
            break;
        case RUNS_WITH_BATTING_AVERAGE:
            playersList = iplMostRunsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return firstBatsman.runs > secondBatsman.runs && firstBatsman.battingAverage > secondBatsman.battingAverage; });
            break;
        case BOWLING_AVERAGE:
            playersList = iplMostWicketsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return (firstBatsman.bowlingAverage != 0 && secondBatsman.bowlingAverage != 0) ? firstBatsman.bowlingAverage < secondBatsman.bowlingAverage : bool(); });
            break;
        case BOWLING_STRIKE_RATE:
            playersList = iplMostWicketsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return (firstBatsman.bowlingStrikeRates != 0 && secondBatsman.bowlingStrikeRates != 0) ? firstBatsman.bowlingStrikeRates < secondBatsman.bowlingStrikeRates : bool(); });
            break;
        case ECONOMY_RATE:
            playersList = iplMostWicketsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return firstBatsman.bowlingStrikeRates < secondBatsman.bowlingStrikeRates; });
            break;
        case STRIKE_RATE_WITH_FOUR_AND_FIVE_WICKETS:
            playersList = iplMostWicketsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return ((firstBatsman.bowlingStrikeRates != 0 && secondBatsman.bowlingStrikeRates != 0) ? firstBatsman.bowlingStrikeRates < secondBatsman.bowlingStrikeRates : bool()) && 
            (firstBatsman.fiveWickets + firstBatsman.fourWickets) > (secondBatsman.fiveWickets + secondBatsman.fourWickets); });
            break;
        case BOWLING_AVERAGE_WITH_STRIKE_RATE:
            playersList = iplMostWicketsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return ((firstBatsman.bowlingAverage != 0 && secondBatsman.bowlingAverage != 0) ? firstBatsman.bowlingAverage < secondBatsman.bowlingAverage : bool()) &&
            ((firstBatsman.bowlingStrikeRates != 0 && secondBatsman.bowlingStrikeRates != 0) ? firstBatsman.bowlingStrikeRates < secondBatsman.bowlingStrikeRates : bool()); });
            break;
        case WICKETS_WITH_BOWLING_AVERAGE:
            playersList = iplMostWicketsList;
            playersList.sort([](const IPLPlayerDetails firstBatsman, const IPLPlayerDetails secondBatsman)
            {return ((firstBatsman.bowlingAverage != 0 && secondBatsman.bowlingAverage != 0) ? firstBatsman.bowlingAverage < secondBatsman.bowlingAverage : bool()) &&
            firstBatsman.wickets > secondBatsman.wickets; });
            break;
    }
    
    return playersList;
}