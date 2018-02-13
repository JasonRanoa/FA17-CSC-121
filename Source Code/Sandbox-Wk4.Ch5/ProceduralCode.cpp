#include <iostream>
#include <iomanip>
#include <fstream>
#include "ProceduralCode.h"
using namespace std;

int ProceduralCode::ClubFees() {
    // Constants for membership rates
    const double ADULT_RATE  = 120.0;
    const double CHILD_RATE  = 60.0;
    const double SENIOR_RATE = 100.0;

    char raw_choice;
    int choice;           // Menu choice
    int months;           // Number of months
    double charges;       // Monthly charges

    do
    {
        choice = 0;

        // Display the menu and get the user's choice
        cout << "\n   Health Club Membership Menu\n\n";
        cout << "1. Standard Adult Membership\n";
        cout << "2. Child Membership\n";
        cout << "3. Senior Citizen Membership\n";
        cout << "4. Quit the Program\n\n";
        cout << "Enter your choice: ";
        cin  >> raw_choice;

        if (isnumber(raw_choice)) {
            choice = static_cast<int>(raw_choice) - '0';
        }

        // Validate the menu selection
        while ((choice < 1) || (choice > 4))
        {
            choice = 0;
            cout << "Please enter 1, 2, 3, or 4: ";
            cin  >> raw_choice;

            if (isnumber(raw_choice)) {
                choice = static_cast<int>(raw_choice) - '0';
            }
        }
        // Process the user's choice
        if (choice != 4)
        {	cout << "For how many months? ";
            cin  >> months;

            // Compute charges based on user input
            switch (choice)
            {
                case 1: charges = months * ADULT_RATE;
                    break;
                case 2: charges = months * CHILD_RATE;
                    break;
                case 3: charges = months * SENIOR_RATE;
            }
            // Display the monthly charges
            cout << fixed << showpoint << setprecision(2);
            cout << "The total charges are $" << charges << endl;
        }
    } while (choice != 4); // Loop again if the user did not
    // select choice 4 to quit
    return 0;
}

int ProceduralCode::DVDCost() {
    int numDVDs;         // Number of DVDs being rented
    double total = 0.0;  // Accumulates total charges for all DVDs
    char current;        // Current release? (Y/N)

    // Get number of DVDs rented
    cout << "How many DVDs are being rented? ";
    cin  >> numDVDs;

    // Determine the charges
    for (int dvdCount = 1; dvdCount <= numDVDs; dvdCount++)
    {	if (dvdCount % 3 == 0)   // If it's a 3rd DVD it's free
        {
            cout << "DVD #" << dvdCount << " is free!\n";
            continue;
        }
        cout << "Is DVD #" << dvdCount << " a current release (Y/N)? ";
        cin  >> current;
        if ((current == 'Y') || (current == 'y'))
            total += 3.50;
        else
            total += 2.50;
    }
    // Display the total charges
    cout << fixed << showpoint << setprecision(2);
    cout << "The total is $" << total << endl;
    return 0;
}

int ProceduralCode::MusicIO() {
    ofstream outputFile;

    // Open the output file
    outputFile.open("demofile.txt");

    cout << "Now writing data to the file.\n";

    // Write four names to the file
    outputFile << "Bach\n";
    outputFile << "Beethoven\n";
    outputFile << "Mozart\n";
    outputFile << "Schubert\n";

    // Close the file
    outputFile.close();

    cout << "Done.\n";
    return 0;
}

int ProceduralCode::InFile() {
    ifstream inputFile;
    string name;

    // Open the input file
    inputFile.open("demofile.txt");

    cout << "Here are the names stored in the demofile.txt file.\n";

    for (int count = 1; count <= 10; count++)
    {
        inputFile >> name;      // Read the next name from the file
        cout << name << endl;   // and display it
    }

    inputFile.close();          // Close the file
    return 0;
}