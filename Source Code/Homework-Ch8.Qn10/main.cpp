#include <iostream>
#include <string>
#include "BaseballChampions.h"
using namespace std;

int main() {
    BaseballChampions bs;
    string teamName;

    if (!bs.good()) {
        cout << "There's something wrong with the files.";
        return -1;
    }

    cout << "Hi!" << endl;
    cout << "This program looks up the number of times " << endl
         << "a baseball team has won the World Series." << endl;
    cout << endl;

    cout << "Here's a list of baseball teams. " << endl;
    for (string team : bs.getTeams()) {
        cout << "  " << team << endl;
    }
    cout << endl;

    cout << "Please enter a team name: ";
    getline(cin, teamName);
    while (!bs.validateTeamName(teamName)) {
        cout << "  Not found. Try again: ";
        getline(cin, teamName);
    }
    cout << endl;

    cout << "The team, " << teamName << ", has won " << endl
         << "the World Series " <<  bs.countTeamWins(teamName)
         << " time(s) from 1950 to 2014." << endl;
    cout << endl;

    return 0;
}