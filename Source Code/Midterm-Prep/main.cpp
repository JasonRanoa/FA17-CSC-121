#include "ArrayHelper.h"
#include "Menu.h"
#include <iostream>
using namespace std;

bool safeGetch(char&, bool = true);
bool safeGetInteger(int&);
string stringifyArray(int[], int);

void printIntroduction();
void populateArray(int[], int);
void sortArray(int[], int);
void doArraySearching(int[], int);
void printBye();

int main() {
    const unsigned size = 15; // Size can be changed. Code can adapt.
    int numbers[size];

    printIntroduction();
    populateArray(numbers, size);
    sortArray(numbers, size);
    doArraySearching(numbers, size);
    printBye();

    return 0;
}

bool safeGetch(char &store, bool convertUp) {
    bool isGood = false;
    string raw_input;

    getline(cin, raw_input);
    for (char c : raw_input) {
        if (isspace(c)) continue;
        else if (isalnum(c) || ispunct(c)) {
            isGood = true;
            store = ( convertUp ) ? static_cast<char>(toupper(c)) : c;
            break;
        } else break;
    }

    return isGood;
}

bool safeGetInteger(int &n) {
    bool isGood = false;
    string raw_input;

    getline(cin, raw_input);
    try {
        n = stoi(raw_input);
        return true;
    } catch (exception &e) {
        return false;
    }
}

void printIntroduction() {
    cout << "This program allows the user to do the ff." << endl;
    cout << "  1. Populate an integer array using various methods." << endl;
    cout << "  2. Do selection and bubble sorting algorithms." << endl;
    cout << "  3. Search a given integer in the array." << endl;
    cout << "  4. Choose run path from a given list of options." << endl;
    cout << endl;
}

string stringifyArray(int numbers[], int size) {
    ArrayHelper ah;
    return "Array: [ " + ah.stringifyArray(numbers, size) + " ]";
}

void populateArray(int numbers[], int size) {
    Menu pop;
    char user_choice;
    ArrayHelper ah;
    bool isPopulated = false;
    string filename;

    pop.addItem( 'A', "Randomize array members." );
    pop.addItem( 'B', "Read standard file for array data." );
    pop.addItem( 'C', "Open custom file." );
    pop.addItem( 'D', "Enter array data as prompted." );

    cout << "The array of size " << size << " needs to populated." << endl;
    while (!isPopulated) {
        cout << "Please select a population method." << endl;
        cout << pop.stringify(2);
        cout << endl;

        cout << "Response? ";
        safeGetch(user_choice);
        while (!pop.isValidIdx(user_choice)) {
            cout << "   Invalid. Try again: ";
            safeGetch(user_choice);
        }
        cout << endl;

        switch (user_choice) {
            case 'A':
                cout << "The array members are now randomized." << endl;
                ah.randomizeArray(numbers, size);
                isPopulated = true;
                break;
            case 'B':
                cout << "The file, array.txt, will be used to fill the array." << endl;
                ah.populateArrayFromFile(numbers, size);
                isPopulated = true;
                break;
            case 'C':
                cout << "Please enter a filename: ";
                getline(cin, filename);
                if (ah.populateArrayFromFile(numbers, size, filename)) {
                    cout << "The file is found and the array populated." << endl;
                    isPopulated = true;
                } else {
                    cout << "Sorry. The program can't use that file. :(" << endl << endl;
                }
                break;
            case 'D':
                cout << "Enter integers as prompted." << endl;
                for (int i = 0; i < size; i++) {
                    cout << "  Integer " << i + 1 << ": ";
                    while (!safeGetInteger(numbers[i])) {
                        cout << "    Sorry. The program can't take that. Try again: ";
                    }
                }
                cout << "The array is now populated." << endl;
                isPopulated = true;
                break;
        }
    }
    cout << endl;

    cout << "The current array members, as they are saved:" << endl;
    cout << stringifyArray(numbers, size) << endl;
    cout << endl;
}

void sortArray(int numbers[], int size) {
    Menu sm;
    char user_choice;
    ArrayHelper ah;
    string prevArrayStr = stringifyArray(numbers, size);

    sm.addItem( 'A', "Do the SELECTION SORTING algorithm." );
    sm.addItem( 'B', "Use the BUBBLE SORTING algorithm." );
    sm.addItem( '?', "Surprise Me! Choose a random one." );
    sm.addItem( 'X', "Skip the sorting. (Not recommended)" );

    cout << "Please choose a sorting algorithm." << endl;
    cout << sm.stringify(2);
    cout << endl;

    cout << "Response? ";
    safeGetch(user_choice);
    while (!sm.isValidIdx(user_choice)) {
        cout << "   Invalid. Try again: ";
        safeGetch(user_choice);
    }
    cout << endl;

    if (user_choice == '?') {
        srand(time(NULL));
        cout << "Choosing randomly..." << endl;
        user_choice = static_cast<bool>(rand() % 2) ? 'A' : 'B';
    }

    switch (user_choice) {
        case 'A':
            cout << "Thou shalt has chosen SELECTION SORTING." << endl;
            cout << "Please give thy program a minute." << endl;
            ah.selectionSort(numbers, size);
            break;
        case 'B':
            cout << "Pop! BUBBLE SORTING is now a go!" << endl;
            cout << "Please give the program some time." << endl;
            ah.bubbleSort(numbers, size);
            break;
        case 'X':
            cout << "Oh. Okay." << endl;
            cout << "Just remember that binary search "
                 << "won't work with an unsorted list." << endl;
            break;
    }
    cout << endl;

    cout << "Methods have been executed." << endl;
    cout << "  Previous " << prevArrayStr << endl;
    cout << " Resulting " << stringifyArray(numbers, size) << endl;
    cout << endl;
}

void doArraySearching(int numbers[], int size) {
    Menu get, search;
    char user_choice;
    int target_val = 0, target_idx = -1;
    bool isFound = false;
    ArrayHelper ah;

    get.addItem( 'A', "Provide an integer yourself." );
    get.addItem( 'B', "Generate a random integer." );
    get.addItem( 'C', "Extract a random integer from the list." );

    cout << "The program needs a target for the search." << endl;
    cout << "Please choose a method." << endl;
    cout << get.stringify(2);
    cout << endl;

    cout << "Response? ";
    safeGetch(user_choice);
    while (!get.isValidIdx(user_choice)) {
        cout << "   Invalid. Try again: ";
        safeGetch(user_choice);
    }
    cout << endl;

    switch (user_choice) {
        case 'A':
            cout << "Please enter an integer as prompted." << endl;
            cout << "For reference, " << endl;
            cout << "  " << stringifyArray(numbers, size) << endl << endl;
            cout << "Value of Target? ";
            while (!safeGetInteger(target_val)) {
                cout << "    Value can't be extracted. Try again: ";
            }
            break;
        case 'B':
            cout << "Okay, then. Generating a random number..." << endl;
            srand(time(NULL));
            target_val = rand() % 1000; // From 0 to 999
            break;
        case 'C':
            cout << "Extracting a random array member..." << endl;
            target_val = ah.getRandomMember(numbers, size);
            break;
    }
    cout << endl;

    cout << "The program must now look for " << target_val
         << " in the array." << endl;

    search.addItem( 'L', "Do a LINEAR SEARCH liek a caveman" );
    search.addItem( 'B', "Use a BINARY SEARCH algorithm." );
    search.addItem( '?', "Surprise me! Choose randomly." );

    cout << "Please choose a searching algorithm." << endl;
    cout << search.stringify(2);
    cout << endl;

    cout << "Response? ";
    safeGetch(user_choice);
    while (!search.isValidIdx(user_choice)) {
        cout << "   Invalid. Try again: ";
        safeGetch(user_choice);
    }
    cout << endl;

    if (user_choice == '?') {
        srand(time(NULL));
        cout << "Choosing randomly..." << endl;
        user_choice = static_cast<bool>(rand() % 2) ? 'L' : 'B';
    }

    switch (user_choice) {
        case 'L':
            cout << "LINEAR SEARCHING it is, then. " << endl;
            target_idx = ah.linearSearch(numbers, size, target_val);
            break;
        case 'B':
            cout << "Yay! BINARY SEARCHING for the win. " << endl;
            target_idx = ah.binarySearch(numbers, size, target_val);
            break;
    }
    cout << endl;

    if ( target_idx == -1 ) { // Failure
        cout << "Sorry, bud. " << endl
             << "The search algorithm did NOT find the value " << target_val
             << " in the array." << endl;
    } else if ( numbers[target_idx] == target_val ) {
        cout << "YES! The searching algorithm is successful." << endl;
        cout << "Value " << target_val << " is found at index " << target_idx << endl;
    } else { // False Positive
        cout << "Oh no. The searching algorithm gave the the wrong index."
             << endl;
        cout << "It returned value " << numbers[target_idx]
             << " @ index " << target_idx << endl;
    }
    cout << "    For reference, here's the search space." << endl;
    cout << "    " << stringifyArray(numbers, size) << endl;
    cout << endl;
}

void printBye() {
    string ta;
    cout << "The program has done executing. " << endl;
    cout << "Please press [ENTER] to exit. ";
    getline(cin, ta);
}