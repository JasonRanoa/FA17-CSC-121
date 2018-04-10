//
// Created by TheLoneWoof on 10/26/17.
//

#include "FileReader.h"
#include <iostream>

FileReader::~FileReader() {
    if (isOpen) {
        file.close();
    }
}

bool FileReader::openFile(std::string filename) {
    file.open(filename, std::ios::in);
    if (!file) {
        isOpen = false;
    } else {
        isOpen = true;
    }
    return isOpen;
}

void FileReader::outputGetLine() {
    std::string s;
    getline(file, s);
    while (!file.fail()) {
        std::cout << s << std::endl;
        getline(file, s);
    }
    file.clear();
    file.seekg(0, std::ios::beg);
}

void FileReader::outputGetChar() {
    char c;
    file.clear();
    c = file.get();
    while (c != EOF) {
        std::cout << c;
        c = file.get();
    }
    std::cout << std::endl;
    file.clear();
    file.seekg(0, std::ios::beg);
}

