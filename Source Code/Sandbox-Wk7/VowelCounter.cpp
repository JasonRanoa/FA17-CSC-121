//
// Created by TheLoneWoof on 10/3/17.
//

#include "VowelCounter.h"

void VowelCounter::countStuff() {
    char c;
    for (char raw_c : phrase) {
        c = toupper(raw_c);
        if (isalpha(c)) {
            switch (c) {
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    vowelCount++;
                    break;
                default:
                    consonantCount++;
            }
        }
    }
}
