//
// Created by TheLoneWoof on 10/5/17.
//

#include "Stuff.h"
#include <iostream>
#include <iomanip>

void Stuff::printArray(int nlist[], int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << std::fixed << std::setw(5);
        std::cout << nlist[i];
        if (i != size - 1) std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
}

void Stuff::populateArrayRand(int nlist[], int size) {
    static unsigned seed = time(NULL);
    int max = 999, min = 100;

    srand(seed++);
    // Populate the list with random numbers from 1 - 100.
    for (int i = 0; i < size; i++) {
        nlist[i] = ( rand() % ( max - min ) ) + min + 1;
    }
}

int Stuff::getRandMember(int nlist[], int size) {
    return nlist[(rand() % size)];
}

void Stuff::bubbleSort(int nlist[], int size) {
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

void Stuff::selectionSort(int nlist[], int size) {
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

int Stuff::linearSearch(int nlist[], int size, int target) {
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

int Stuff::binarySearch(int nlist[], int size, int target) {
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
