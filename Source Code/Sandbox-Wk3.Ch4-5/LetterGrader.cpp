#include <iostream>
#include "LetterGrader.h"
using namespace std;

void LetterGrader::getTestScore() {
    cout << "Enter your numeric test score and I will " << endl;
    cout << "tell you the letter grade you earned. " << endl << endl;

    cout << "What is your test score? ";
    cin  >> testScore;

    cout << endl;
    return;
}

void LetterGrader::assignGrade() {
    if (testScore >= MIN_A_SCORE ) {
        letterGrade = 'A';
    } else if (testScore >= MIN_B_SCORE) {
        letterGrade = 'B';
    } else if (testScore >= MIN_C_SCORE) {
        letterGrade = 'C';
    } else if (testScore >= MIN_D_SCORE) {
        letterGrade = 'D';
    } else {
        letterGrade = 'F';
    }

    return;
}

void LetterGrader::printGrade() {
    cout << "Your letter grade is " << letterGrade << "." << endl;
    switch (letterGrade) {
        case 'A':
            cout << "Wow. You know the material well! Good job!" << endl;
            break;
        case 'B':
            cout << "It's still good! Keep it up!" << endl;
            break;
        case 'C':
            cout << "At least you passed! Hang on." << endl;
            break;
        case 'D':
            cout << "Well, you technically passed the exam..." << endl;
            break;
        case 'F':
            if (testScore == 0) {
                cout << "Wow. You suck. " << endl;
            } else if (testScore < 0) {
                cout << "Wow. You suck so bad, you got a negative test score. " << endl;
            } else {
                cout << "Awww. Better luck next time! Go study." << endl;
            }

            break;
        default:
            cout << "There's something wrong here. This isn't supposed to be displayed" << endl;
    }

    return;
}

void LetterGrader::executeMe() {
    getTestScore();
    assignGrade();
    printGrade();

    return;
}