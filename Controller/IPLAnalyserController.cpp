#include "../view/IPLAnalyserView.h"
#include "../model/IPLAnalyser.h"

#define MOST_RUNS_FILE_PATH "../resources/IPL2019FactsheetMostRuns.csv"
#define MOST_WICKETS_FILE_PATH "../resources/IPL2019FactsheetMostWkts.csv"

using namespace std;

class IPLAnalyserController 
{
    IPLAnalyserView iplIO;
    IPLAnalyser iplAnalyser;

    public:
        void displaySortedListOfPlayersData()
        {
            list<IPLPlayerDetails> sortedList;
            iplIO.displayWelcomeMessage();
            iplAnalyser.loadIPLData(MOST_RUNS_FILE_PATH, BATSMAN);
            iplAnalyser.loadIPLData(MOST_WICKETS_FILE_PATH, BOWLER); 
            
            while (true)
            {
                int choice = iplIO.getChoiceOfSorting();
                switch (choice)
                {
                    case BATTING_AVERAGE:
                        sortedList = iplAnalyser.getSortedData(BATTING_AVERAGE);
                        iplIO.displayBatsman(sortedList);
                        break;
                    case BATTING_STRIKE_RATE:
                        sortedList = iplAnalyser.getSortedData(BATTING_STRIKE_RATE);
                        iplIO.displayBatsman(sortedList);
                        break;
                    case FOURS_AND_SIXES:
                        sortedList = iplAnalyser.getSortedData(FOURS_AND_SIXES);
                        iplIO.displayBatsman(sortedList);
                        break;
                    case STRIKE_RATE_WITH_SIX_AND_FOUR:
                        sortedList = iplAnalyser.getSortedData(STRIKE_RATE_WITH_SIX_AND_FOUR);
                        iplIO.displayBatsman(sortedList);
                        break;
                    case BATTING_AVERAGE_WITH_STRIKE_RATE:
                        sortedList = iplAnalyser.getSortedData(BATTING_AVERAGE_WITH_STRIKE_RATE);
                        iplIO.displayBatsman(sortedList);
                        break;
                    case RUNS_WITH_BATTING_AVERAGE:
                        sortedList = iplAnalyser.getSortedData(RUNS_WITH_BATTING_AVERAGE);
                        iplIO.displayBatsman(sortedList);
                        break;
                    case BOWLING_AVERAGE:
                        sortedList = iplAnalyser.getSortedData(BOWLING_AVERAGE);
                        iplIO.displayBowler(sortedList);
                        break;
                    case BOWLING_STRIKE_RATE:
                        sortedList = iplAnalyser.getSortedData(BOWLING_STRIKE_RATE);
                        iplIO.displayBowler(sortedList);
                        break;
                    case ECONOMY_RATE:
                        sortedList = iplAnalyser.getSortedData(ECONOMY_RATE);
                        iplIO.displayBowler(sortedList);
                        break;
                    case STRIKE_RATE_WITH_FOUR_AND_FIVE_WICKETS:
                        sortedList = iplAnalyser.getSortedData(STRIKE_RATE_WITH_FOUR_AND_FIVE_WICKETS);
                        iplIO.displayBowler(sortedList);
                        break;
                    case BOWLING_AVERAGE_WITH_STRIKE_RATE:
                        sortedList = iplAnalyser.getSortedData(BOWLING_AVERAGE_WITH_STRIKE_RATE);
                        iplIO.displayBowler(sortedList);
                        break;
                    case WICKETS_WITH_BOWLING_AVERAGE:
                        sortedList = iplAnalyser.getSortedData(WICKETS_WITH_BOWLING_AVERAGE);
                        iplIO.displayBowler(sortedList);
                        break;
                    case 13:
                        exit(0);
                    default:
                        iplIO.defaultMassege();
                }
            }             
        }
};

int main() 
{
    IPLAnalyserController controller;

    controller.displaySortedListOfPlayersData();
    return 0;
}