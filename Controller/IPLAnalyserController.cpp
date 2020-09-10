#include "../view/IPLAnalyserView.h"
#include "../model/IPLAnalyser.h"

#define MOST_RUNS_FILE_PATH "../resources/IPL2019FactsheetMostRuns.csv"

using namespace std;

class IPLAnalyserController 
{
    IPLAnalyserView iplIO;
    IPLAnalyser iplAnalyser;

    private:
        list<IPLBatsmanData> getSortedListOfPlayersData()
        {
            list<IPLBatsmanData> sortedList;
            int choice = iplIO.getChoiceOfSorting();
            
            switch (choice)
            {
                case AVERAGE:
                    sortedList = iplAnalyser.getSortedData(AVERAGE);
                    break;
                case STRIKE_RATE:
                    sortedList = iplAnalyser.getSortedData(STRIKE_RATE);
                    break;
                case FOURS_AND_SIXES:
                    sortedList = iplAnalyser.getSortedData(FOURS_AND_SIXES);
                    break;
                case STRIKE_RATE_WITH_SIX_AND_FOUR:
                    sortedList = iplAnalyser.getSortedData(STRIKE_RATE_WITH_SIX_AND_FOUR);
                    break;
                case BATTING_AVERAGE_WITH_STRIKE_RATE:
                    sortedList = iplAnalyser.getSortedData(BATTING_AVERAGE_WITH_STRIKE_RATE);
                    break;
                case 6:
                    exit(0);
                default:
                    iplIO.defaultMassege();
            }
            
            return sortedList;;
        }

    public:
        void displaySortedData() 
        {
            iplIO.displayWelcomeMessage();
            iplAnalyser.loadIPLData(MOST_RUNS_FILE_PATH); 

            while (true)
            {
                iplIO.displayTopAvgBatsman(getSortedListOfPlayersData());
            }
        }
};

int main() 
{
    IPLAnalyserController controller;

    controller.displaySortedData();
    return 0;
}