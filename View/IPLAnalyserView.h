#pragma once
#include <iostream>
#include <list>
#include "../Model/IPLMostRunsCSV.h"

using namespace std;

class IPLAnalyserView {
private:
    public:
    IPLAnalyserView() {}

    void displayWelcomeMessage();
    void displayTopAvgBatsman(list<IPLBatsmanData> topBatsmans, string heading);
    int getChoiceOfSorting();
    void defaultMassege();
};

void IPLAnalyserView::displayWelcomeMessage() {
    cout << "Welcome To IPL Analyser" << endl;
}

void IPLAnalyserView::displayTopAvgBatsman(list<IPLBatsmanData> topBatsmans, string heading)
{
    cout << heading << endl;
    int count = 0;
    for (auto playerDetails = topBatsmans.begin(); count < 10 ; playerDetails++ , count++)
    {
        cout << "\nNAME: " << playerDetails->playerName << "\nAVERAGE: " << playerDetails->average << "\nSTRIKE RATE: " << playerDetails->strikeRate << endl;
    }   
}

int IPLAnalyserView :: getChoiceOfSorting()
{
    int choice;
    cout << "\nSelect Choice for displaying data: \n1: Top batting averages of the Cricketers \n2: Top Striking rate of batsman \n3: Exit" << endl;
    cin >> choice;
    return choice;
}

void IPLAnalyserView :: defaultMassege()
{
    cout << "\nInvalid Input" << endl;
}