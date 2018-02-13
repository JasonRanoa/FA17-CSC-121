#include "NameList.h"
#include <iostream>
using namespace std;

int main() {
    NameList nl;

    if ( !nl.loadNames("names.dat") ) {
        cout << "Can't open file. :(" << endl;
        return -1;
    }

    nl.sortNames();
    cout << "Here is the sorted list." << endl;
    std::cout << nl.stringifyNames("  ");
    cout << "End of list." << endl;

    return 0;
}