//
// Created by TheLoneWoof on 11/28/17.
//

#ifndef HOMEWORK_CH12_QN11_DIRECTORY_H
#define HOMEWORK_CH12_QN11_DIRECTORY_H

#include <vector>
#include <string>

class Directory {

private:
    std::vector<std::string> records;

public:
    void lazyInit();
    void displayAllRecords();
    std::vector<std::string> searchByName(std::string);

    void saveToFile(std::string);
    void loadDirFromFile(std::string);


};


#endif //HOMEWORK_CH12_QN11_DIRECTORY_H
