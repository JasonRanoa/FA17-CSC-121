//
// Created by TheLoneWoof on 11/14/17.
//

#include "Cereal.h"

void Cereal::serializeTwoObjects() {
    // This program demonstrates object serialization.
    // Array of objects to store in file
    Person people[ ] =
            { Person("Joseph", 'X', "Puff", 32),
              Person("Louise", 'Y', "Me", 28)
            };
    // Open a file and store the array of people
    ofstream outFile("MorePeople.dat", ios::binary);
    if(!outFile)
    {
        cout << "The output file cannot be opened";
        return;
    }

    // Store the people data in the file
    people[0].store(outFile);
    people[1].store(outFile);
    cout << "Data has been written to the file "
         << " 'Morepeople.dat'";

    // Close file
    outFile.close();
    return;
}

void Cereal::deserializeTwoObjects() {
    const int NUM_PEOPLE = 2;
    Person people[NUM_PEOPLE];
    // Open a file and load the array of people
    ifstream inFile("MorePeople.dat", ios::binary);
    if(!inFile)
    {
        cout << "The input file cannot be opened";
        return;
    }

    // Read the data from the file
    for (int k = 0; k < NUM_PEOPLE; k++)
        people[k].load(inFile);

    // Display the data
    for (int k = 0; k < NUM_PEOPLE; k++)
        people[k].display();

    // Close the file
    inFile.close();
    return;
}