#pragma once
#include <iostream>
#include <list>
#include "IPLMostRunsCSV.h"
#include "../Libraries/CSVReader.h"

using namespace std;

class IPLAnalyser
{
    private:
        list<IPLBatsmanData> iplMostRunsList;
    public:
        void loadIPLData(string fileName);
        list<IPLBatsmanData> getSortedDataAsPerBattingAverage();
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

list<IPLBatsmanData> IPLAnalyser :: getSortedDataAsPerBattingAverage()
{
    iplMostRunsList.sort([](const IPLBatsmanData firstBatsman, const IPLBatsmanData secondBatsman)
    {return (firstBatsman.average == secondBatsman.average) ? &firstBatsman > &secondBatsman : firstBatsman.average > secondBatsman.average; });
    return iplMostRunsList;
}