//
// Created by TheLoneWoof on 10/5/17.
//

#include "ArrayHelper.h"
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace std;

// General Helper Functions

string ArrayHelper::stringifyArray(
    int nlist[], int size, int item_width, string delimiter
) {
    stringstream ss;

    for (int i = 0; i < size; i++) {
        ss << setw(item_width) << nlist[i];
        if (i != size - 1) ss << delimiter;
    }

    return ss.str();
}

void ArrayHelper::randomizeArray(
    int nlist[], int size, int min, int max, int seed
) {
    srand(seed);
    for (int i = 0; i < size; i++) {
        nlist[i] = ( rand() % (max - min) ) + min + 1;
    }
}

int ArrayHelper::getRandomMember(int nlist[], int size, int seed) {
    srand(seed);
    return nlist[rand() % size];
}

// File IO Methods

bool ArrayHelper::populateArrayFromFile(int nlist[], int size, string filename) {
    // This function only validates the values needed.
    // Any extra values are ignored.
    ifstream arrayFile;
    bool isGood = true;
    string raw_data;

    arrayFile.open(filename);
    if (arrayFile) {
        for (int i = 0; i < size && isGood; i++) {
            getline(arrayFile, raw_data);
            try {
                nlist[i] = stoi(raw_data);
            } catch (exception &e) {
                isGood = false;
            }
            // If EOF is reached and it's not the last
            // element yet.
            if (arrayFile.eof() && i != size - 1) {
                isGood = false;
                continue;
            }
        }
    } else isGood = false;

    return isGood;
}

bool ArrayHelper::makeFileForArray(int nlist[], int size, string filename) {
    ofstream arrayFile;

    arrayFile.open(filename);
    if (arrayFile) {
        arrayFile << stringifyArray(nlist, size, 0, "\n");
        arrayFile.close();

        return true;
    } else return false;
}

// Sorting Algorithms

void ArrayHelper::bubbleSort(int nlist[], int size) {
    int temp;
    bool hasSwaps;

    do {
        hasSwaps = false;
        for (int i = 0; i < size - 1; i++) {
            if (nlist[i] > nlist[i + 1]) {
                hasSwaps = true;
                temp = nlist[i];
                nlist[i] = nlist[i + 1];
                nlist[i + 1] = temp;
            }
        }
    } while (hasSwaps);
}

void ArrayHelper::selectionSort(int nlist[], int size) {
    int min_val, min_idx;

    for (int i = 0; i < size; i++) {
        min_idx = i;
        min_val = nlist[i];
        for (int j = i + 1; j < size; j++) {
            if (nlist[j] < min_val) {
                min_idx = j;
                min_val = nlist[j];
            }
        }
        if (min_val != nlist[i]) {
            nlist[min_idx] = nlist[i];
            nlist[i] = min_val;
        }
    }
}

// Searching Algorithms

int ArrayHelper::linearSearch(int nlist[], int size, int target) {
    bool isFound = false;
    int i;
    for (i = 0; i < size; i++) {
        if (nlist[i] == target) {
            isFound = true;
            break;
        }
    }

    if (isFound) return i;
    else return -1;
}

int ArrayHelper::binarySearch(int nlist[], int size, int target) {
    bool isFound = false;
    int min_idx = 0,
            mid_idx,
            max_idx = size - 1,
            target_idx = -1;

    // While the target is not found and
    // the min_idx is smaller than or equal to max_idx.
    //     i.e. there's a valid search space
    while (!isFound && min_idx <= max_idx) {
        // Calculate a midpoint.
        // Integer division. Returns an integer.
        mid_idx = (min_idx + max_idx) / 2;
        // if target is found at the middle, return mid_idx.
        if (nlist[mid_idx] == target ) {
            isFound = true;
            target_idx = mid_idx;
            // if target is less than middle value,
            // proceed to sublist: min_idx to the left of mid_idx.
        } else if (target < nlist[mid_idx]) {
            max_idx = mid_idx - 1;
            // if target is more than middle value,
            // process to sublist: right of mid_idx to last.
        } else {
            min_idx = mid_idx + 1;
        }
    }
    return target_idx;
}
