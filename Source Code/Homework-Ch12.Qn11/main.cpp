#include "Directory.h"
#include <iostream>
using namespace std;

int main() {
    Directory dir;
    string searchTerm;
    // dir.lazyInit();
    // dir.saveToFile("dat.dat");
    // dir.displayAllRecords();
    dir.loadDirFromFile("dat.dat");

    cout << "This program searches for records that " << endl
         << "matches a full name or a partial name." << endl
         << "Please enter a name as prompted." << endl << endl;

    cout << "    Search? ";
    getline(cin, searchTerm);
    cout << endl;

    vector<string> results = dir.searchByName(searchTerm);
    if (results.size() == 0) {
        cout << "We're sorry. There are no matches." << endl;
    } else {
        cout << "The following records are found: " << endl;
        for (string r : results) {
            cout << "    " << r << endl;
        }
    }



    return 0;
}