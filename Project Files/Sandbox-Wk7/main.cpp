#include "VowelCounter.h"
#include "Stuff.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

    enum Department {Purchasing, Manufacturing, Warehouse, Sales};
    Department floor1, floor2;
    int dNum = 2;

    floor1 = Sales;
    dNum = Sales;
    dNum = floor1;
    floor2 = static_cast<Department>(dNum);

    /*
    string sentence;
    VowelCounter vw;

    cout << "Enter any sentence you wish and I will \n"
         << "tell you how many vowels and consonants are in it.\n\n";

    getline(cin, sentence);
    vw.setPhrase(sentence);
    vw.countStuff();

    cout << "\n";
    cout << "There are " << vw.getPhraseLength() << " characters in the sentence.\n";
    cout << "    " << vw.getVowelCount() << " of those are vowels.\n";
    cout << "    " << vw.getConsonantCount() << " of those are consonants.\n";

    return 0;
    */

    /*
    const int LIST_SIZE = 10;
    int numbers[LIST_SIZE];

    Stuff stuff;
    int target_val;
    int return_idx;

    // Bubble Sort
    cout << "BUBBLE SORT" << endl;
    cout << "The unsorted list: ";
    stuff.populateArrayRand(numbers, LIST_SIZE);
    stuff.printArray(numbers, LIST_SIZE);
    cout << "The sorted list:   ";
    stuff.bubbleSort(numbers, LIST_SIZE);
    stuff.printArray(numbers, LIST_SIZE);
    cout << endl;

    // Selection Sort
    cout << "SELECTION SORT" << endl;
    cout << "The unsorted list: ";
    stuff.populateArrayRand(numbers, LIST_SIZE);
    stuff.printArray(numbers, LIST_SIZE);
    cout << "The sorted list:   ";
    stuff.selectionSort(numbers, LIST_SIZE);
    stuff.printArray(numbers, LIST_SIZE);
    cout << endl;

    // Linear Search
    cout << "LINEAR SEARCH" << endl;
    target_val = stuff.getRandMember(numbers, LIST_SIZE);
    cout << "The target value:  " << target_val << endl;
    cout << "The search space:  ";
    stuff.printArray(numbers, LIST_SIZE);
    return_idx = stuff.linearSearch(numbers, LIST_SIZE, target_val);
    if (target_val == numbers[return_idx]) {
        cout << "    The value is found successfully @ index " << return_idx << endl;
    } else {
        cout << "    The value is NOT found." << endl;
        cout << "    Returned index is " << return_idx << endl;
    }
    cout << endl;

    // Binary Search
    cout << "BINARY SEARCH" << endl;
    target_val = stuff.getRandMember(numbers, LIST_SIZE);
    stuff.bubbleSort(numbers, LIST_SIZE); // just in case.
    cout << "The target value:  " << target_val << endl;
    cout << "The search space:  ";
    stuff.printArray(numbers, LIST_SIZE);
    return_idx = stuff.binarySearch(numbers, LIST_SIZE, target_val);
    if (target_val == numbers[return_idx]) {
        cout << "    The value is found successfully @ index " << return_idx << endl;
    } else {
        cout << "    The value is NOT found." << endl;
        cout << "    Returned index is " << return_idx << endl;
    }
    cout << endl;

     */

    return 0;
}
