#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int days;
    int years = 0;
    int leapYearCounter = 0;

    cout << "Please input days in the range [0, 1000000]" << endl;
    cin >> days;

    //Checking the data input.
    while(cin.fail() || (days < 0) || (days > 1000000)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n" << endl;
        cin >> days;
    }

    for (int i = 1; i <= days; i += 365) {
        years++;
        leapYearCounter++;

//Check if the year is leap.
        if (leapYearCounter == 4) {
            i++;
            leapYearCounter = 0;
        }
    }

    if (years == 0) {
        cout << "Invalid year." << endl;
    } else {
        cout << "The year is: " << years << endl;
    }

    return 0;
}
