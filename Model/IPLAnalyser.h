#pragma once
#include <list>
#include "IPLMostRunsCSV.h"
#include "SortType.h"
#include "../Libraries/CSVReader.h"

using namespace std;

class IPLAnalyser
{
    private:
        list<IPLBatsmanData> iplMostRunsList;
    public:
        void loadIPLData(string fileName);
        list<IPLBatsmanData> getSortedData(SortType sortType);
};

void IPLAnalyser :: loadIPLData(string fileName)
{
    CSVReader csvReader;    
    list<vector<string>> iplMostRunsCSVList = csvReader.readFile(fileName);

    for (auto playerDetails = iplMostRunsCSVList.begin(); playerDetails != iplMostRunsCSVList.end(); playerDetails++)
    {
        IPLBatsmanData batsman;
        batsman.playerName = (*playerDetails).at(1);
        batsman.runs = stoi((*playerDetails).at(5));
        batsman.average = stod((*playerDetails).at(7));
        batsman.strikeRate = stod((*playerDetails).at(9));
        batsman.fours = stoi((*playerDetails).at(12));
        batsman.sixes = stoi((*playerDetails).at(13));

        iplMostRunsList.push_back(batsman);
    }
}

list<IPLBatsmanData> IPLAnalyser :: getSortedData(SortType sortType)
{
    list<IPLBatsmanData> playersList = iplMostRunsList;
    switch(sortType)
    {
        case AVERAGE:
            playersList.sort([](const IPLBatsmanData firstBatsman, const IPLBatsmanData secondBatsman)
            {return firstBatsman.average > secondBatsman.average; });
            break;
        case STRIKE_RATE:
            playersList.sort([](const IPLBatsmanData firstBatsman, const IPLBatsmanData secondBatsman)
            {return firstBatsman.strikeRate > secondBatsman.strikeRate; });
            break;
        case FOURS_AND_SIXES:
            playersList.sort([](const IPLBatsmanData firstBatsman, const IPLBatsmanData secondBatsman)
            {return (firstBatsman.fours + firstBatsman.sixes) > (secondBatsman.fours +secondBatsman.sixes); });
            break;
        case STRIKE_RATE_WITH_SIX_AND_FOUR:
            playersList.sort([](const IPLBatsmanData firstBatsman, const IPLBatsmanData secondBatsman)
            {return firstBatsman.strikeRate > secondBatsman.strikeRate && (firstBatsman.fours + firstBatsman.sixes) > (secondBatsman.fours +secondBatsman.sixes); });
            break;
        case BATTING_AVERAGE_WITH_STRIKE_RATE:
            playersList.sort([](const IPLBatsmanData firstBatsman, const IPLBatsmanData secondBatsman)
            {return firstBatsman.average > secondBatsman.average && firstBatsman.strikeRate > secondBatsman.strikeRate; });
            break;
        case RUNS_WITH_BATTING_AVERAGE:
            playersList.sort([](const IPLBatsmanData firstBatsman, const IPLBatsmanData secondBatsman)
            {return firstBatsman.runs > secondBatsman.runs && firstBatsman.average > secondBatsman.average; });
            break;
    }
    
    return playersList;
}