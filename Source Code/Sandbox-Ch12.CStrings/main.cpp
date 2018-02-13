#include <iostream>
using namespace std;

int main() {
    const int size = 7;
    char h1[7] = "Hello";
    char h2[] = ", World!";
    char h3[] = "";
    strcat( h3, h1 );

    cout << h3 << endl;
    for (int i = 0; i < sizeof(h3)/sizeof(h3[0]); i++) {
        cout << h3[i];
    }
}