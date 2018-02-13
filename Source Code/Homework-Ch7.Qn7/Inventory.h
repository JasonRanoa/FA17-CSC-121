//
// Created by TheLoneWoof on 10/8/17.
//

#ifndef HOMEWORK_CH7_QN7_INVENTORY_H
#define HOMEWORK_CH7_QN7_INVENTORY_H


class Inventory {

private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;
    void setTotalCost();

public:
    Inventory();
    Inventory(int, int, double);

    void setItemNumber(int);
    void setQuantity(int);
    void setCost(double);

    int getItemNumber();
    int getQuantity();
    double getCost();
    double getTotalCost();
};


#endif //HOMEWORK_CH7_QN7_INVENTORY_H
