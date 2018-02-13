//
// Created by TheLoneWoof on 10/9/17.
//

#ifndef HOMEWORK_CH8_QN10_BASEBALLCHAMPIONS_H
#define HOMEWORK_CH8_QN10_BASEBALLCHAMPIONS_H

#include <string>
#include <vector>

class BaseballChampions {

private:
    bool isGood = false;
    std::vector<std::string> teams;
    std::vector<std::string> raw_championHistory;
    bool init();

public:
    BaseballChampions();
    bool good();
    std::vector<std::string> getTeams();

    bool validateTeamName(std::string);
    int countTeamWins(std::string);
};


#endif //HOMEWORK_CH8_QN10_BASEBALLCHAMPIONS_H
