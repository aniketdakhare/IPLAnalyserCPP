#pragma once
#include <list>
#include "D:\CPP\ClassAssignment\IPL\IPLAnalyserCPP\Model\Utility\IPLAdapter.h"
#include "D:\CPP\ClassAssignment\IPL\IPLAnalyserCPP\Model\IPLPlayerDetails.h"
#include "D:\CPP\ClassAssignment\IPL\IPLAnalyserCPP\Libraries\CSVReader.h"

using namespace std;

class IPLMostRunsAdapter : public IPLAdapter
{
    public:
        list<IPLPlayerDetails> loadIPLData(string fileName)
        {
            CSVReader csvReader;
            list<IPLPlayerDetails> iplPlayersList;
            list<vector<string>> iplMostRunsCSVList = csvReader.readFile(fileName);

            for (auto playerDetails = iplMostRunsCSVList.begin(); playerDetails != iplMostRunsCSVList.end(); playerDetails++)
            {
                IPLPlayerDetails player;
                player.player = (*playerDetails).at(1);
                player.runs = stoi((*playerDetails).at(5));
                player.battingAverage = stod((*playerDetails).at(7));
                player.battingStrikeRates = stod((*playerDetails).at(9));
                player.fours = stoi((*playerDetails).at(12));
                player.sixes = stoi((*playerDetails).at(13));

                iplPlayersList.push_back(player);
            }
            return iplPlayersList;
        }
};