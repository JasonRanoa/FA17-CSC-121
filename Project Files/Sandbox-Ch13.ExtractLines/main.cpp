#include <iostream>
#include "FileReader.h"

int main() {
    FileReader fr;
    fr.openFile("murphy.txt");
    fr.outputGetChar();
    fr.outputGetLine();
    return 0;
}