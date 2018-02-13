//
// Created by TheLoneWoof on 11/7/17.
//

#ifndef HOMEWORK_CH13_QN1_FILEPREVIEWER_H
#define HOMEWORK_CH13_QN1_FILEPREVIEWER_H

#include <fstream>
#include <string>
#include <vector>

class FilePreviewer {

private:
    std::ifstream file;
    std::vector<std::string> preview;
    bool isEndReached;
    bool isGood;

    void extractLines();

public:
    FilePreviewer();
    FilePreviewer(std::string);
    ~FilePreviewer();

    bool loadFile(std::string);
    bool good();
    bool endReached();
    std::vector<std::string> getPreview();
};


#endif //HOMEWORK_CH13_QN1_FILEPREVIEWER_H
