#pragma once
#include <iostream>
#include <list>
#include "../model/IPLMostRunsCSV.h"

using namespace std;

class IPLAnalyserView {
private:
    public:
    IPLAnalyserView() {}

    void displayWelcomeMessage();
    void displayTopAvgBatsman(list<IPLBatsmanData> topBatsmans);
};

void IPLAnalyserView::displayWelcomeMessage() {
    cout << "Welcome To IPL Analyser" << endl;
}

void IPLAnalyserView::displayTopAvgBatsman(list<IPLBatsmanData> topBatsmans)
{
    int count = 0;
    for (auto playerDetails = topBatsmans.begin(); count < 10  ; playerDetails++ , count++)
    {
        cout << "\nNAME: " << playerDetails->playerName << "\nAVERAGE: " << playerDetails->average << endl;
    }   
}