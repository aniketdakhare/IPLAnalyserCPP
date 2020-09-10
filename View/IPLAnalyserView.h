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
    void displayTopAvgBatsman(list<IPLBatsmanData> topBatsmans);
    int getChoiceOfSorting();
    void defaultMassege();
};

void IPLAnalyserView::displayWelcomeMessage() {
    cout << "Welcome To IPL Analyser" << endl;
}

void IPLAnalyserView::displayTopAvgBatsman(list<IPLBatsmanData> topBatsmans)
{
    int count = 0;
    for (auto playerDetails = topBatsmans.begin(); count < 10 ; playerDetails++ , count++)
    {
        cout << "\nNAME: " << playerDetails->playerName << "\nAVERAGE: " << playerDetails->average << "\nSTRIKE RATE: " << playerDetails->strikeRate
        << "\n4's: " << playerDetails->fours << "\n6's: " << playerDetails->sixes << endl;
    }   
}

int IPLAnalyserView :: getChoiceOfSorting()
{
    int choice;
    cout << "\nSelect Choice for displaying data: \n1: Top batting averages of the Cricketers \n2: Top Striking rate of batsman"
    << "\n3: Cricketers who hit maximum 6s and 4s \n4: Exit" << endl;
    cin >> choice;
    return choice;
}

void IPLAnalyserView :: defaultMassege()
{
    cout << "\nInvalid Input" << endl;
}