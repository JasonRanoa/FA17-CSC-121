#include "TaxCalculator.h"
#include <iostream>

void TaxCalculator::calculateTaxes(double p) {
	StateRate = .065;
	CountryRate = .02;

    PurchasePrice = p;
    StateTax += PurchasePrice * StateRate;
    CountryTax += PurchasePrice * CountryRate;
	Total = PurchasePrice + StateTax + CountryTax;
    
    return;
}

void TaxCalculator::printInfo() {
	std::cout << "Purchase Price : " << PurchasePrice << char(10);
	std::cout << "State Tax      : " << StateTax << char(10);
	std::cout << "Country Tax    : " << CountryTax << char(10);
	std::cout << "Total Tax      : " << StateTax + CountryTax << char(10);
	std::cout << "-----------------" << char(10);
	std::cout << "Total          : " << Total << char(10);
	
	return;
}
