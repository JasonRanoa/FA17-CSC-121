#include "IntegerArray.h"

int main() {
    int items[] {234, 534, 764, 543, 765};
    int size = sizeof(items) / sizeof(items[0]);

    IntegerArray ia;
    ia.printNumbers( items, size );
    return 0;
}