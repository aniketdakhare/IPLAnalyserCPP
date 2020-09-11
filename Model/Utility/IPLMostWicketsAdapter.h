#pragma once
#include <list>
#include "D:\CPP\ClassAssignment\IPL\IPLAnalyserCPP\Model\Utility\IPLAdapter.h"
#include "D:\CPP\ClassAssignment\IPL\IPLAnalyserCPP\Model\IPLPlayerDetails.h"
#include "D:\CPP\ClassAssignment\IPL\IPLAnalyserCPP\Libraries\CSVReader.h"

using namespace std;

class IPLMostWicketsAdapter : public IPLAdapter
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
                player.wickets = stoi((*playerDetails).at(6));
                player.bowlingAverage = stod((*playerDetails).at(8));
                player.economyRates = stod((*playerDetails).at(9));
                player.bowlingStrikeRates = stod((*playerDetails).at(10));
                player.fourWickets = stoi((*playerDetails).at(11));
                player.fiveWickets = stoi((*playerDetails).at(12));

                iplPlayersList.push_back(player);
            }
            return iplPlayersList;
        }
};