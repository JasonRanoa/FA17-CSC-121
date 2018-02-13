#include "Circle.h"
#include <iostream>
#include <fstream>
using namespace std;

void TaskOne();
void TaskThree();
int getN(fstream &);
void getData(fstream &, double *, int);

int main() {
    TaskOne();

    // TASK THREE
    // Part I. Reading.
    fstream sourceFile("radius.dat", ios::binary | ios::in);
    if (!sourceFile) {
        cout << "Cannot open file. " << endl;
        return -1;
    }
    int n = getN(sourceFile);
    double *radiusCirclesIn = new double[n];
    getData(sourceFile, radiusCirclesIn, n);

    sourceFile.close();

    // Part II. Saving.
    fstream newFile("circleData.txt", ios::out);
    Circle c;
    if (!newFile) {
        cout << "Cannot create file. " << endl;
        return -1;
    }
    for (int i = 0; i < n; i++) {
        c.setRadius(radiusCirclesIn[i]);
        newFile << c.getRadius() << " ";
        newFile << c.getArea() << " ";
        newFile << c.getDiameter() << " ";
        newFile << c.getCircumference();
        newFile << endl;
    }
    newFile.close();

    cout << "Done." << endl;
    return 0;
}

void TaskOne() {
    double radiusCirclesOut[] = {
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    };
    fstream file("radius.dat", ios::binary | ios::out);
    if (!file) {
        cout << "Cannot create new file. " << endl;
        exit(0);
    }

    int size = sizeof(radiusCirclesOut) / sizeof(radiusCirclesOut[0]);
    for (int i = 0; i < size; i++) {
        file.write(
            reinterpret_cast<char *>(&(radiusCirclesOut[i])), sizeof(double)
        );
    }
    file.close();
}

int getN(fstream &sourceFile) {
    if (!sourceFile) return 0;
    int n = 0;
    double tempRadius;
    while (sourceFile.good()) {
        sourceFile.read(reinterpret_cast<char *>(&tempRadius), sizeof(tempRadius));
        n++;
    }
    n--; // The condition only turns false when the last loop (the first invalid) runs
         // So, this code is a workaround for that.

    // Reset.
    sourceFile.clear();
    sourceFile.seekg(0, ios::beg);

    return n;
}

void getData(fstream &sourceFile, double *radii, int n) {
    double tempRadius;
    if (!sourceFile) return;
    for (int i = 0; i < n && sourceFile.good(); i++) {
        sourceFile.read(reinterpret_cast<char *>(&tempRadius), sizeof(tempRadius));
        radii[i] = tempRadius;
    }
}