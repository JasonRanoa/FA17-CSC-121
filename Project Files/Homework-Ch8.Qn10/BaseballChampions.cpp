//
// Created by TheLoneWoof on 10/9/17.
//

#include "BaseballChampions.h"
#include <iostream>
#include <fstream>
using namespace std;

bool BaseballChampions::init() {
    ifstream teamFile, listFile;
    string tempStr;
    teamFile.open("teams.txt");

    if (teamFile) {
        while (teamFile.good()) {
            getline(teamFile, tempStr);
            // Removes '\r' characters from Mac text files.
            // string::pop_back() removes last character.
            if (tempStr.back() == '\r') {
                tempStr.pop_back();
            }
            teams.push_back(tempStr);
        }
        teamFile.close();
    } else {
        return false; // Fail.
    }

    listFile.open("WorldSeriesWinners.txt");
    if (listFile) {
        while (listFile.good()) {
            getline(listFile, tempStr);
            // Removes '\r' characters from Mac text files.
            // string::pop_back() removes last character.
            if (tempStr.back() == '\r') {
                tempStr.pop_back();
            }
            raw_championHistory.push_back(tempStr);
        }
        listFile.close();
    } else {
        return false; // Fail
    }

    return true;
}

BaseballChampions::BaseballChampions() {
    isGood = init();
}

bool BaseballChampions::good() {
    return isGood;
}

vector<string> BaseballChampions::getTeams() {
    return teams;
}

bool BaseballChampions::validateTeamName(string tryTeam) {
    bool isFound = false;
    for (string team : teams) {
        if (team == tryTeam) {
            isFound = true;
            break;
        }
    }
    return isFound;
}

int BaseballChampions::countTeamWins(string teamName) {
    int winCount = 0;
    for (string teamWin : raw_championHistory) {
        if (teamWin == teamName) {
            winCount++;
        }
    }
    return winCount;
}

