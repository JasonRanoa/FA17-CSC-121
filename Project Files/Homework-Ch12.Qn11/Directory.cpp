//
// Created by TheLoneWoof on 11/28/17.
//

#include "Directory.h"
#include <iostream>
#include <fstream>
using namespace std;

void Directory::lazyInit() {
    records = {
        "Hoshikawa Tanaka, 678-1223",
        "Joe Looney, 586-0097",
        "Geri Palmer, 223-8787",
        "Lynn Lopez, 887-1212",
        "Holly Gaddis, 223-8878",
        "Sam Wiggins, 486-0998",
        "Bob Kain, 586-8712",
        "Tim Haynes, 586-7676",
        "Warren Gaddis, 223-9037",
        "Jean James, 678-4939",
        "Ron Palmer, 486-2783"
    };
}

void Directory::displayAllRecords() {
    for (string s : records) {
        cout << s << endl;
    }
}

vector<string> Directory::searchByName(string nameArg) {
    vector<string> matches;

    for (string r : records) {
        int pos = 0;
        //int last = r.find(',');
        //if (last == string::npos) last = r.length();
        int last = r.length();

        bool isFound = false;
        do {
            int x = pos, a;
            for (a = 0; a < nameArg.length() && x < last; a++, x++) {
                if (toupper(nameArg[a]) != toupper(r[x])) break;
            }
            if (a == nameArg.length()) {
                matches.push_back(r);
                isFound = true;
                break;
            }

            int temp_pos = pos;
            pos = r.find(toupper(nameArg[0]), temp_pos + 1);
            if (pos == string::npos) {
                pos = r.find(tolower(nameArg[0]), temp_pos + 1);
            }
        } while ( !isFound && pos != string::npos && pos < last);
    }

    return matches;
}

void Directory::saveToFile(string filename) {
    fstream file(filename, ios::out | ios::binary);
    if (!file) return;

    for (string r : records) {
        int l = r.length();
        file.write(reinterpret_cast<char *>(&l), sizeof(l));
        file.write(r.data(), l);
    }

    file.close();
}

void Directory::loadDirFromFile(string filename) {
    const int BUFFER_SIZE = 256;
    static char buffer[256];
    fstream file(filename, ios::in | ios::binary);

    if (!file) return;

    while(file.good() && file.peek() != EOF) {
        int l = 0;
        file.read(reinterpret_cast<char *>(&l), sizeof(l));
        file.read(buffer, l);
        buffer[l] = '\0';

        records.push_back(static_cast<string>(buffer));
    }

    file.close();
}