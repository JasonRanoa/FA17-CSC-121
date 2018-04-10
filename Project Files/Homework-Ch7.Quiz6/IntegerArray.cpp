#include "IntegerArray.h"
#include <iostream>

void IntegerArray::printNumbers(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Item " << (i + 1) << ": "
                  << numbers[i] << std::endl;
    }
}
