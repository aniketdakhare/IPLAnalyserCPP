#include "../view/IPLAnalyserView.h"
#include "../model/IPLAnalyser.h"

#define MOST_RUNS_FILE_PATH "../resources/IPL2019FactsheetMostRuns.csv"

using namespace std;

class IPLAnalyserController 
{
    IPLAnalyserView iplIO;
    IPLAnalyser iplAnalyser;

    public:
        void displaySortedData() 
        {
            list<IPLBatsmanData> sortedList;
            iplIO.displayWelcomeMessage();
            iplAnalyser.loadIPLData(MOST_RUNS_FILE_PATH); 

            while (true)
            {
                SortType sortType;
                string heading;
                int choice = iplIO.getChoiceOfSorting();

                switch (choice)
                {
                    case 1:
                        sortType = SortType::AVERAGE;
                        heading = "\n#### TOP BATTING AVERAGES ####";
                        break;
                    case 2:
                        sortType = SortType::STRIKE_RATE;
                        heading = "\n#### TOP STRIKE RATE ####";
                        break;
                    case 3:
                        exit(0);
                    default:
                        iplIO.defaultMassege();
                }

                iplIO.displayTopAvgBatsman(iplAnalyser.getSortedData(sortType), heading);
            }
        }
};

int main() 
{
    IPLAnalyserController controller;

    controller.displaySortedData();
    return 0;
}