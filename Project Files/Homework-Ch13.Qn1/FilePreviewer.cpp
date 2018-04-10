//
// Created by TheLoneWoof on 11/7/17.
//

#include "FilePreviewer.h"
using namespace std;

FilePreviewer::FilePreviewer() {
    isGood = false;
    isEndReached = false;
    preview.clear();
}

FilePreviewer::FilePreviewer(string filename) {
    isGood = false;
    isEndReached = false;
    preview.clear();
    loadFile(filename);
}

FilePreviewer::~FilePreviewer() {
    if (file) {
        file.close();
    }
}

void FilePreviewer::extractLines() {
    int limit = 10;
    string temp;

    for (int i = 0; i < limit && file.good(); i++) {
        getline(file, temp);
        preview.push_back(temp);
    }

    isEndReached = !file.good();

    file.clear();
    file.seekg(0, ios::beg);
}

bool FilePreviewer::loadFile(string filename) {
    file.open(filename);
    isGood = file.good();
    extractLines();

    return isGood;
}

bool FilePreviewer::good() {
    return isGood;
}

vector<string> FilePreviewer::getPreview() {
    return preview;
}

bool FilePreviewer::endReached() {
    return isEndReached;
}
