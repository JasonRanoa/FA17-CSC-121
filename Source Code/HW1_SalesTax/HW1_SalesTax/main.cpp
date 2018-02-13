/*
 CSC 121 001 Computer Science II
 Fall 2017

 Julius Ranoa
 Homework 1 Part II
 Chapter 2 Page 74
 
 Purpose:	Computes tax on purchase price.
 Input:		PurchasePrice.
			Currently hardcoded.
 

*/

#include <iostream>
#include "TaxCalculator.h"
using namespace std;

int main() {
    double TaxMe = 95.0;
	TaxCalculator tx;

	tx.calculateTaxes(TaxMe);
	tx.printInfo();

    cin.ignore();
    return 0;
}
