//
// Created by TheLoneWoof on 10/26/17.
//

#ifndef HOMEWORK_CH10_QN7_MOVIESTATS_H
#define HOMEWORK_CH10_QN7_MOVIESTATS_H

#include <string>

class MovieStats {
private:
    // std::string *nameList;
    int *nSeenList;
    int nRecords;

public:
    MovieStats();
    ~MovieStats();

    void setNumRecords(int);
    void setRecordByIndex(int, int);
    int getNSeenByIndex(int);
    void sortRecordsByNSeen();

    int getLength();
    double printMean();
    double printMedian();
    int printMode();
};


#endif //HOMEWORK_CH10_QN7_MOVIESTATS_H
