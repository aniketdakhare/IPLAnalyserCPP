#pragma once
#include <iostream>
#include <list>
#include "../Model/IPLPlayerDetails.h"

using namespace std;

class IPLAnalyserView {
private:
    public:
    IPLAnalyserView() {}

    void displayWelcomeMessage();
    void displayBatsman(list<IPLPlayerDetails> topBatsmans);
    void displayBowler(list<IPLPlayerDetails> topBowlers);
    int getChoiceOfSorting();
    void defaultMassege();
};

void IPLAnalyserView::displayWelcomeMessage()
{
    cout << "Welcome To IPL Analyser" << endl;
}

void IPLAnalyserView::displayBatsman(list<IPLPlayerDetails> topBatsmans)
{
    int count = 0;
    for (auto playerDetails = topBatsmans.begin(); count < 10 ; playerDetails++ , count++)
    {
        cout << "\nNAME: " << playerDetails->player << "\nAVERAGE: " << playerDetails->battingAverage << "\nSTRIKE RATE: " << playerDetails->battingStrikeRates
        << "\nRuns: " << playerDetails->runs << "\n4's: " << playerDetails->fours << "\n6's: " << playerDetails->sixes << endl;
    }   
}

void IPLAnalyserView::displayBowler(list<IPLPlayerDetails> topBowler)
{
    int count = 0;
    for (auto playerDetails = topBowler.begin(); count < 10 ; playerDetails++ , count++)
    {
        cout << "\nNAME: " << playerDetails->player << "\nAVERAGE: " << playerDetails->bowlingAverage << "\nSTRIKE RATE: " << playerDetails->bowlingStrikeRates
        << "\nWickets: " << playerDetails->wickets << "\n4w: " << playerDetails->fourWickets << "\n5w: " << playerDetails->fiveWickets 
        << "\nEconomy Rate: " << playerDetails->economyRates << endl;
    }   
}


int IPLAnalyserView :: getChoiceOfSorting()
{
    int choice;
    cout << "\nSelect Choice for displaying data: \n1: Top batting averages of the Cricketers \n2: Top Striking rate of batsman"
    << "\n3: Cricketers who hit maximum 6s and 4s \n4: Cricketers who had best striking rates with 6s and 4s"
    << "\n5: Cricketers who had great averages with the best striking rates possible"
    << "\n6: Cricketers who hit maximum runs with best averages \n7: Top bowling averages of the Cricketers "
    << "\n8: Top Striking Rates of the Bowlers \n9: Bowlers who had the best economy rate"
    << "\n10: Cricketers who had best striking rates with 5w and 4w \n11: Exit" << endl;
    cin >> choice;
    return choice;
}

void IPLAnalyserView :: defaultMassege()
{
    cout << "\nInvalid Input" << endl;
}