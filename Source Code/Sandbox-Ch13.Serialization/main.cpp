#include "Cereal.h"
#include <iostream>
using namespace std;

int main() {
    Cereal c;
    c.serializeTwoObjects();
    cout << endl;
    c.deserializeTwoObjects();
    return 0;
}