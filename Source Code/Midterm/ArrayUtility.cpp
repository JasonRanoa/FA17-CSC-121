#include "ArrayUtility.h"
#include <iostream>
#include <fstream>
using namespace std;

bool ArrayUtility::readNumbers(int nlist[], int size) {
    ifstream file;

    file.open("unsorted.txt");
    if (file) {
        for (int i = 0; i < size && file.good(); i++) {
            file >> nlist[i];
        }
        file.close();
    } else return false;

    return true;
}

void ArrayUtility::displayNumbers(int nlist[], int size) {
    for (int i = 0; i < size; i++) {
        cout << nlist[i] << " ";
    }
}

void ArrayUtility::selectionSort(int nlist[], int size) {
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

bool ArrayUtility::writeNumbers(int nlist[], int size) {
    ofstream file;

    file.open("sorted.txt");
    if (file) {
        for (int i = 0; i < size; i++) {
            file << nlist[i] << " ";
        }
        file.close();
    } else return false;

    return true;
}

double ArrayUtility::calcAvg(int nlist[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nlist[i];
    }
    return static_cast<double>(sum) / size;
}