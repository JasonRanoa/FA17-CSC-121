#include <string>

class InventoryItem {

private:
    int partNum;
    std::string description;
    int onHand;
    double price;

public:
    void storeInfo(int p, std::string d, int oH, double cost);

    int getPartNum() const {
        return partNum;
    }

    std::string getDescription() const {
        return description;
    }

    int getOnHand() const {
        return onHand;
    }

    double getPrice() const {
        return price;
    }
};