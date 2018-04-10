#include <iostream>
#include "Records.h"

int main() {
    int size;

    std::cout << "Enter number of test scores: ";
    std::cin >> size;
    std::cout << "\n";

    Records r(size);

    r.getAllData();
    r.printAllData();



    return 0;
}