//
// Created by TheLoneWoof on 10/26/17.
//

#include "MovieStats.h"
#include <iostream>

MovieStats::MovieStats() {
    nSeenList = nullptr;
    nRecords = false;
}

MovieStats::~MovieStats() {
    delete [] nSeenList;
    nSeenList = nullptr;
}

void MovieStats::setNumRecords(int size) {
    delete [] nSeenList;
    nSeenList = new int[size];
    nRecords = size;
}

int MovieStats::getNSeenByIndex(int idx) {
    if ( idx < 0 || idx >= nRecords ) return 0;
    else return *(nSeenList + idx);
}

void MovieStats::setRecordByIndex(int idx, int nSeen) {
    if ( idx < 0 || idx >= nRecords ) return;
    else {
        *(nSeenList + idx) = nSeen;
    }
}

void MovieStats::sortRecordsByNSeen() {
    // Selection Sort.
    int min_val, min_idx;

    for (int i = 0; i < nRecords; i++) {
        min_idx = i;
        min_val = *(nSeenList + i);
        for (int j = i + 1; j < nRecords; j++) {
            if ( *(nSeenList + j) < min_val ) {
                min_idx = j;
                min_val = *(nSeenList + j);
            }
        }
        if (min_idx != i) {
            *(nSeenList + min_idx) = *(nSeenList + i);
            *(nSeenList + i) = min_val;
        }
    }
}

int MovieStats::getLength() {
    return nRecords;
}

double MovieStats::printMean() {
    double total = 0.0, mean;
    for (int i = 0; i < nRecords; i++) {
        total += *(nSeenList + i);
    }
    mean = ( total / nRecords );

    std::cout << "Mean: " << mean << std::endl;
    return mean;
}

double MovieStats::printMedian() {
    sortRecordsByNSeen();

    double median = 0;
    int med_idx = (nRecords - 1) / 2;
    if (nRecords % 2 == 1) { // if odd
        median = *(nSeenList + med_idx);
    } else { // if even
        median = *(nSeenList + med_idx) + *(nSeenList + med_idx + 1);
        median /= 2;
    }

    std::cout << "Median: " << median << std::endl;
    return median;
}

int MovieStats::printMode() {
    sortRecordsByNSeen();

    int mode = *(nSeenList), modeCount = 1;
    int tempMode = mode, tempCount = 1;

    for (int i = 1; i < nRecords; i++) {
        if (tempMode == *(nSeenList + i)) {
            tempCount++;
            continue;
        } else {
            if (tempCount > modeCount) {
                mode = tempMode;
                modeCount = tempCount;
            }
            tempMode = *(nSeenList + i);
            tempCount = 1;
        }
    }

    if (tempCount > modeCount) {
        mode = tempMode;
        modeCount = tempCount;
    }

    std::cout << "Mode: " << mode
              << " (Frequency: " << modeCount << ") "
              << std::endl;
    return mode;
}

