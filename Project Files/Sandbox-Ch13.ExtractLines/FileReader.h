//
// Created by TheLoneWoof on 10/26/17.
//

#ifndef SANDBOX_CH13_EXTRACTLINES_FILEREADER_H
#define SANDBOX_CH13_EXTRACTLINES_FILEREADER_H

#include <fstream>
#include <string>

class FileReader {

private:
    std::fstream file;
    bool isOpen = false;

public:
    ~FileReader();
    bool openFile(std::string);
    void outputGetLine();
    void outputGetChar();
};


#endif //SANDBOX_CH13_EXTRACTLINES_FILEREADER_H
