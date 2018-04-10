//
// Created by TheLoneWoof on 10/19/17.
//

#ifndef SANDBOX_CH10_POINTERS_TESTLIST_H
#define SANDBOX_CH10_POINTERS_TESTLIST_H


class TestList {

private:
    int size = 0;
    double* scores = nullptr;

public:
    TestList();
    TestList(int);
    ~TestList();

    int getSize();
    void setListLength(int);
    void promptTestScores();
    void printTestScores();
    void sortTestScores();
    double getAverage();
    void printAverage();

};


#endif //SANDBOX_CH10_POINTERS_TESTLIST_H
