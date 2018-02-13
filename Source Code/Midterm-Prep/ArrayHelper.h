//
// Created by TheLoneWoof on 10/5/17.
//

#ifndef MIDTERM_PREP_ARRAYHELPER_H
#define MIDTERM_PREP_ARRAYHELPER_H

#include <string>

class ArrayHelper {
public:
    // General Methods
    std::string stringifyArray(int[], int, int = 0, std::string = ", ");
    void randomizeArray(int[], int, int = 100, int = 999, int = time(NULL));
    int getRandomMember(int[], int, int = time(NULL)); // Returns value.

    // File IO Methods
    bool populateArrayFromFile(int[], int, std::string = "array.txt");
    bool makeFileForArray(int[], int, std::string = "array.txt");

    // Sorting Algorithms
    void selectionSort(int[], int);
    void bubbleSort(int[], int);

    // Searching Algorithms
    // Return index of member if found. -1 if otherwise.
    int linearSearch(int[], int, int);
    int binarySearch(int[], int, int);
};

#endif //MIDTERM_PREP_ARRAYHELPER_H
