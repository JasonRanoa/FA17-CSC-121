//
// Created by TheLoneWoof on 10/12/17.
//

#include "NameList.h"
#include <fstream>
#include <sstream>
using namespace std;

void NameList::addName(string name) {
    names.push_back(name);
}

bool NameList::loadNames(string filename) {
    ifstream data;
    string tempName;

    data.open(filename);
    if (!data) return false;

    while(data.good()) {
        getline(data, tempName);
        if (tempName.length() <= 0) continue;
        // To deal with return chars in Mac.
        if(tempName.back() == '\r') tempName.pop_back();
        addName(tempName);
    }

    return true;
}

void NameList::sortNames() {
    string first_val;
    int first_idx;

    for (int i = 0; i < names.size(); i++) {
        first_idx = i;
        first_val = names[i];
        for (int j = i + 1; j < names.size(); j++) {
            if (names[j] < first_val) {
                first_idx = j;
                first_val = names[j];
            }
        }
        if (first_val != names[i]) {
            names[first_idx] = names[i];
            names[i] = first_val;
        }
    }
}

string NameList::stringifyNames(string prefix) {
    stringstream ss;
    for (string name : names) {
        ss << prefix << name << endl;
    }
    return ss.str();
}