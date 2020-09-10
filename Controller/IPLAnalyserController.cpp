#include <iostream>
#include "../view/IPLAnalyserView.h"
#include "../model/IPLAnalyser.h"

#define MOST_RUNS_FILE_PATH "../resources/IPL2019FactsheetMostRuns.csv"

using namespace std;

class IPLAnalyserController 
{
    IPLAnalyserView iplIO;
    IPLAnalyser iplAnalyser;

    public:
        void displayTopAvgBtasmanData() 
        {
            iplIO.displayWelcomeMessage();
            iplAnalyser.loadIPLData(MOST_RUNS_FILE_PATH); 
            iplIO.displayTopAvgBatsman(iplAnalyser.getSortedDataAsPerBattingAverage());
        }
};

int main() 
{
    IPLAnalyserController controller;

    controller.displayTopAvgBtasmanData();
    return 0;
}