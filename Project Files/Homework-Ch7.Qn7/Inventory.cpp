//
// Created by TheLoneWoof on 10/8/17.
//

#include "Inventory.h"

// Private Methods
void Inventory::setTotalCost() {
    totalCost = quantity * cost;
}

// Constructors
Inventory::Inventory() {
    itemNumber = quantity = 0;
    cost = 0;
}

Inventory::Inventory(int n, int qty, double cst) {
    itemNumber = n;
    quantity = qty;
    cost = cst;
}

// Mutator Methods
void Inventory::setItemNumber(int n) {
    itemNumber = n;
}

void Inventory::setQuantity(int qty) {
    quantity = qty;
    setTotalCost();
}

void Inventory::setCost(double itemCost) {
    cost = itemCost;
    setTotalCost();
}

// Accessor Methods
int Inventory::getItemNumber() {
    return itemNumber;
}

int Inventory::getQuantity() {
    return quantity;
}

double Inventory::getCost() {
    return cost;
}

double Inventory::getTotalCost() {
    return totalCost;
}


