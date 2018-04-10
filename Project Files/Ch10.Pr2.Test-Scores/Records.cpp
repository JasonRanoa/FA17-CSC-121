//
// Created by TheLoneWoof on 4/10/18.
//

#include <iostream>
#include <iomanip>
#include "Records.h"

void Records::getAllData() {
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Enter data for Record " << (i+1) << ": \n";
        std::cout << "   Name: ";
        std::cin >> (head + i)->name;
        std::cout << "   Score: ";
        std::cin >> (head + i)->score;
    }
    std::cout << "\n";
}

void Records::printAllData() {
    std::cout << "NAME       SCORE \n";
    std::cout << "---------- ----- \n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << std::setw(10) << std::left << (head + i)->name << " ";
        std::cout << (head + i)->score;
        std::cout << "\n";
    }
    std::cout << "\n";
}
