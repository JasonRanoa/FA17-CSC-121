#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Data Type Definition
const int DESC_SIZE = 31;
struct Inventory {
    char desc[31];
    int qty;
    double price;
};
const char* filename = "inventory.dat";

// Global variable.
Inventory items[10];

// Prototypes
void resetFile();
void readFile(int = 5);
void editRecord();
void printAllRecords(int = 5);
void addFiveRecords();

int main() {
    // resetFile();

    // (1) Populate
    readFile();
    cout << "Currently loaded records." << endl;
    printAllRecords();
    cout << endl;

    // (2) Edit Record
    editRecord();
    cout << "Here's the new information: " << endl;
    readFile();
    printAllRecords();
    cout << endl;

    // (3) Append and Read
    cout << "Now adding five records and re-reading stuff. " << endl;
    cout << "Here's the new-er information. " << endl;
    addFiveRecords();
    readFile(10);
    printAllRecords(10);
    cout << endl;

    cout << "Done. Bye.";
}

// Start with 5 Records again.
void resetFile() {
    // TEST DATA
    string descriptions[5] = {
        "Heka", "Atreus", "Enlil", "Ultak", "Muminah"
    };
    int quantities[5] = {
        10, 32, 54, 23, 65
    };
    double price[5] = {
        19.95, 24.95, 5.95, 10.00, 9.95
    };
    for (int i = 0; i < 5; i++) {
        strcpy(items[i].desc, descriptions[i].c_str());
        items[i].qty = quantities[i];
        items[i].price = price[i];
    }
    // END TEST DATA

    fstream file(filename, ios::out | ios::binary);
    file.write( reinterpret_cast<char *>(items), sizeof(Inventory) * 5 );
    file.close();
}

void readFile(int nRecords) {
    fstream bin(filename, ios::in | ios::out | ios::binary);

    if (!bin.good()) {
        cout << "Oops. Something went wrong." << endl;
        return;
    }

    bin.read(reinterpret_cast<char *>(items), sizeof(Inventory) * nRecords );
    bin.close();
}

void editRecord() {
    fstream bin(filename, ios::in | ios::out | ios::binary);
    int nEdit;
    string tempDesc;
    Inventory tempRecord;

    cout << "Enter N of record to edit. " << endl;
    cout << "N: ";
    cin >> nEdit;
    cout << endl;

    bin.seekg((nEdit - 1) * sizeof(Inventory), ios::beg);
    if (bin.good()) {
        cout << "Enter information as prompted." << endl;

        cout << "  NEW Description: ";
        cin.ignore();
        getline(cin, tempDesc);
        strcpy(tempRecord.desc, tempDesc.c_str());

        cout << "  NEW Quantity: ";
        cin >> tempRecord.qty;

        cout << "  NEW Price: ";
        cin >> tempRecord.price;

        bin.write( reinterpret_cast<char *>(&tempRecord), sizeof(Inventory));
        cout << endl;

    } else {
        cout << "Entered N not good. " << endl;
        bin.clear();
        bin.seekg(0L, ios::beg);
    }

    bin.close();
}

void printAllRecords(int nRecords) {
    // Header
    cout << "  ";
    cout << " N" << " ";                    // 2
    cout << "Description         " << " ";  // 20
    cout << "  Qty" << " ";                 // 5
    cout << "  Price" << " ";               // 7
    cout << endl;

    // Dashes
    cout << "  ";
    cout << "--" << " ";                    // 2
    cout << "--------------------" << " ";  // 20
    cout << "-----" << " ";                 // 5
    cout << "-------" << " ";               // 7
    cout << endl;

    // Body
    for (int i = 0; i < nRecords; i++) {
        cout << "  ";
        cout << setw(2) << right << (i + 1) << " ";
        cout << setw(20) << left << items[i].desc << " ";
        cout << setw(5) << right << items[i].qty << " ";
        cout << setw(7) << right << items[i].price << " ";
        cout << endl;
    }
}

void addFiveRecords() {
    fstream bin(filename, ios::out | ios::binary);

    // Raw Data.
    string descriptions[5] = {
        "Harry", "Karrin", "David", "Michael", "John"
    };
    int quantities[5] = {
        65, 23, 65, 89, 12
    };
    double price[5] = {
        9.95, 6.45, 3.90, 2.35, 4.05
    };
    for (int i = 5; i < 10; i++) {
        strcpy(items[i].desc, descriptions[i - 5].c_str());
        items[i].qty = quantities[i - 5];
        items[i].price = price[i - 5];
    }
    // End Raw Data

    bin.write( reinterpret_cast<char *>(items), sizeof(Inventory) * 10 );
    bin.close();
}