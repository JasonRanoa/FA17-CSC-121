#include <iostream>
#include <iomanip>
#include "InventoryItem.h"
using namespace std;

void InventoryItem::storeInfo(int p, std::string d, int oH, double cost) {
    partNum = p;
    description = d;
    onHand = oH;
    price = cost;
}

