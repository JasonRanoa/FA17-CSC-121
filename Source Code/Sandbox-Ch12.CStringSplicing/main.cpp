// This program uses the function nameSlice
// to "cut" off the last name of a string that
// contains the user's first and last names.
#include <iostream>
using namespace std;

void nameSlice(char []); // Function prototype
int countChar(char[], char, bool = false);

int main()
{

    // Define array of char to hold name
    const int NAME_LENGTH = 41;
    char name[NAME_LENGTH];

    // Get user's first and last names
    cout << "Enter your first and last names, separated ";
    cout << "by a space: ";
    cin.getline(name, NAME_LENGTH);

    // Slice off the last name and print what is left
    cout << "Your name, " << name << ", has " << countChar(name, 'a', true) << " a's on it." << endl;
    nameSlice(name);
    cout << "Your last name is: " << name << endl;
    return 0;
}

//*****************************************************
// Definition of function nameSlice. This function    *
// accepts a character array as its argument. It      *
// scans the array looking for a space. When it finds *
// one, it replaces it with a null terminator.        *
//*****************************************************
void nameSlice(char userName[])
{
    // Look for the end of the first name, indicated
    // by a space or a null terminator
    int k = 0;
    int spaceIdx = 0;
    while (userName[k] != '\0') {
        if (userName[k] == ' ') {
            spaceIdx = k;
        }
        k++;
    }
    spaceIdx++;

    int j = 0;
    while (userName[spaceIdx] != '\0') {
        userName[j++] = userName[spaceIdx++];
    }
    userName[j] = '\0';
}

/* Two Names
void nameSlice(char userName[])
{
    // Look for the end of the first name, indicated
    // by a space or a null terminator
    int k = 0;
    while (userName[k] != ' ' && userName[k] != '\0')
        k++;
    k++;

    int j = 0;
    while (userName[k] != '\0') {
        userName[j++] = userName[k++];
    }
    userName[j] = '\0';
}
 */

int countChar(char source[], char term, bool ignoreCase) {
    int count = 0;
    char temp;

    if (ignoreCase) term = toupper(term);
    for (int i = 0; source[i] != '\0'; i++) {
        temp = source[i];
        if (ignoreCase) temp = toupper(temp);
        if (temp == term) count++;
    }
    return count;
}