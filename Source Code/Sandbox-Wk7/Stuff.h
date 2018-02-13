//
// Created by TheLoneWoof on 10/5/17.
//

#ifndef SANDBOX_WK7_STUFF_H
#define SANDBOX_WK7_STUFF_H

#include <string>

class Stuff {

public:
    // Array Helper Methods
    void printArray(int[], int);
    void populateArrayRand(int[], int);
    int getRandMember(int[], int);

    // Sorting Algorithms
    void bubbleSort(int[], int);
    void selectionSort(int[], int);

    // Searching Algorithms
    // Returns the index of search item. -1 if not found.
    int linearSearch(int[], int, int);
    int binarySearch(int[], int, int);
};


#endif //SANDBOX_WK7_STUFF_H
