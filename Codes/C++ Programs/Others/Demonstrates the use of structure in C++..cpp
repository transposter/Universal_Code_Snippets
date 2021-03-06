Demonstrates the use of structure in C++.
Stores some personal data in a structure, then prints the info out.

#include <iostream>
using namespace std;

int main()
{
        // Defining a structure
        struct PersonalData
        {
                char *FirstName;
                char *LastName;
                char *Birthday;  // in the format of 12/27/1978
                int  PhoneNum;
        }; // don't forget the ending ";"

        // Declaring a variable of type PersonalData
        PersonalData PersonOne;

        // Populate PersonOne with data
        PersonOne.FirstName = "Kyra";
        PersonOne.LastName = "Red";
        PersonOne.Birthday = "12/27/1978";
        PersonOne.PhoneNum = 5855555;

        // Print the data out
        cout << "PersonOne's First name is: " << PersonOne.FirstName << endl;
        cout << "PersonOne's Last name is: " << PersonOne.LastName<< endl;
        cout << "PersonOne's Birthday is: " << PersonOne.Birthday<< endl;
        cout << "PersonOne's Phone number is: " << PersonOne.PhoneNum<< endl;

        return 0;
}
