//
// Created by TheLoneWoof on 4/10/18.
//

#ifndef CH10_PR2_TEST_SCORES_RECORDS_H
#define CH10_PR2_TEST_SCORES_RECORDS_H

#include <string>

struct SingleRecord {
    int score;
    std::string name;
};

class Records {

private:
    SingleRecord * head = nullptr;
    int SIZE;

public:
    Records(int size) {
        head = new SingleRecord[size];
        SIZE = size;
    }
    ~Records() {
        delete [] head;
    }

    void getAllData();
    void printAllData();

};


#endif //CH10_PR2_TEST_SCORES_RECORDS_H
