#include "FilePreviewer.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    FilePreviewer fp;
    string filename;

    cout << "This program previews the first 10 lines of text in a file." << endl;
    cout << "Enter filename as prompted." << endl;
    {
        cout << endl;
        cout << "For reference, three files are loaded for testing." << endl;
        cout << "  1. lor.txt         Only 5 lines of text." << endl;
        cout << "  2. lorem.txt       More than 10 lines of text." << endl;
        cout << "  3. loremten.txt    Exactly 10 lines of text." << endl;
    }
    cout << endl;

    cout << "Filename? ";
    cin >> filename;
    cout << endl;

    if (fp.loadFile(filename)) {
        int i = 0;

        cout << "Here's the preview of " << filename << "..." << endl;
        for (string s : fp.getPreview()) {
            cout  << setw(4) << ++i << "|  " << s << endl;
        }

        if (fp.endReached()) {
            cout << "The entire file is displayed." << endl;
        } else {
            cout << "Only first 10 lines are shown." << endl;
        }
    } else {
        cout << "Cannot open file. Sorry. :(" << endl;
    }

    return 0;
}