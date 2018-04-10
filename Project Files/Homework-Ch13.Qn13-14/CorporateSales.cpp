//
// Created by TheLoneWoof on 11/14/17.
//

#include "CorporateSales.h"
#include <iostream>
using namespace std;

void CorporateSales::serialize(ofstream &outFile) {
    // Order of Serialization: Quarter > Sales > Name

    outFile.write(reinterpret_cast<char *>(&quarter), sizeof(quarter));
    outFile.write(reinterpret_cast<char *>(&sales), sizeof(sales));

    int l = divisionName.length();
    outFile.write(reinterpret_cast<char *>(&l), sizeof(l));
    outFile.write(divisionName.data(), l);
}


void CorporateSales::deserialize(ifstream &inFile) {
    const int BUFFER_SIZE = 256;
    static char buffer[256];

    inFile.read(reinterpret_cast<char *>(&quarter), sizeof(quarter));
    inFile.read(reinterpret_cast<char *>(&sales), sizeof(sales));

    int l = 0;
    inFile.read(reinterpret_cast<char *>(&l), sizeof(l));
    inFile.read(buffer, l);
    buffer[l] = '\0';

    divisionName = buffer;
}
