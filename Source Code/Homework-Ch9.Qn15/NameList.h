//
// Created by TheLoneWoof on 10/12/17.
//

#ifndef HOMEWORK_CH9_QN15_NAMELIST_H
#define HOMEWORK_CH9_QN15_NAMELIST_H

#include <string>
#include <vector>

class NameList {

private:
    std::vector<std::string> names;
    bool isSorted = false;

public:
    NameList() {
        names.clear();
        isSorted = false;
    }
    bool sorted() {
        return isSorted;
    }
    void addName(std::string);
    bool loadNames(std::string);
    void sortNames();
    std::string stringifyNames(std::string = "");

};


#endif //HOMEWORK_CH9_QN15_NAMELIST_H
