//
// Created by TheLoneWoof on 10/3/17.
//

#ifndef SANDBOX_WK7_VOWELCOUNTER_H
#define SANDBOX_WK7_VOWELCOUNTER_H

#include <string>

class VowelCounter {

private:
    std::string phrase;
    int vowelCount = 0;
    int consonantCount = 0;

public:
    void setPhrase(std::string s) {
        phrase = s;
    }

    int getPhraseLength() { return phrase.length(); }
    int getVowelCount() { return vowelCount; }
    int getConsonantCount() { return consonantCount; }

    void countStuff();
};


#endif //SANDBOX_WK7_VOWELCOUNTER_H
