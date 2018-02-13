class TaxCalculator {

public:
    void calculateTaxes(double p);
	void printInfo();
	
	// Tax rates are saved in here.
    double StateRate;
    double CountryRate;
	
	// Totals and Subtotals in here.
    double PurchasePrice;
    double StateTax;
    double CountryTax;
    double Total;
	
};
