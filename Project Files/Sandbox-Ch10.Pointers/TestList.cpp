//
// Created by TheLoneWoof on 10/19/17.
//

#include "TestList.h"
#include <iostream>
#include <iomanip>

TestList::TestList() {
    size = 0;
    scores = nullptr;
}

TestList::TestList(int n) {
    size = n;
    scores = new double[n];
}

TestList::~TestList() {
    delete [] scores;
    scores = nullptr;
}

int TestList::getSize() {
    return size;
}

void TestList::setListLength(int n) {
    delete [] scores;
    size = n;
    scores = new double[n];
}

void TestList::promptTestScores() {
    double tempVal;
    for (int i = 0; i < size; i++) {
        std::cout <<  "Enter score " << (i + 1) << ": ";
        std::cin >> tempVal;
        while (tempVal < 0) {
            std::cout << "  Invalid score. Try again: ";
            std::cin >> tempVal;
        }
        *(scores + i) = tempVal;
    }
}

void TestList::sortTestScores() {
    double temp;
    bool hasSwaps;

    do {
        hasSwaps = false;
        for (int i = 0; i < size - 1; i++) {
            if (*(scores + i) > *(scores + i + 1)) {
                hasSwaps = true;
                temp = scores[i];
                *(scores + i) = *(scores + i + 1);
                *(scores + i + 1) = temp;
            }
        }
    } while (hasSwaps);
}

void TestList::printTestScores() {
    std::cout << "The test scores are: ";
    for (int i = 0; i < size - 1; i++) {
        std::cout << std::showpoint << std::fixed << std::setprecision(2);
        std::cout << *(scores + i) << ", ";
    }
    std::cout << *(scores + size - 1) << std::endl;
}

double TestList::getAverage() {
    double avg = 0.0;
    for (int i = 0; i < size; i++) {
        avg += *(scores + i);
    }
    return avg / size;
}

void TestList::printAverage() {
    std::cout << "The average is ";
    std::cout << std::showpoint << std::fixed << std::setprecision(2)
              << getAverage() << std::endl;
}




