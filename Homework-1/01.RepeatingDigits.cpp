/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Anita Razpopova
* @idnumber 62495
* @task 1
* @compiler GCC
*
*/

#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

int main()
{
    int counter0 = 0;
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    int counter4 = 0;
    int counter5 = 0;
    int counter6 = 0;
    int counter7 = 0;
    int counter8 = 0;
    int counter9 = 0;
    int reminder;
    int number;

    cout << "Please input number in the range [-2147483648, 2147483647]" << endl;
    cin >> number;
    //Checking the data input.
    while(cin.fail() || (number < INT_MIN) || (number > INT_MAX)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n" << endl;
        cin >> number;
    }

    reminder = abs(number % 10);
    number = number / 10;
    while (number != 0) {
        switch (reminder) {
            case 0:
                counter0++;
                break;
            case 1:
                counter1++;
                break;
            case 2:
                counter2++;
                break;
            case 3:
                counter3++;
                break;
            case 4:
                counter4++;
                break;
            case 5:
                counter5++;
                break;
            case 6:
                counter6++;
                break;
            case 7:
                counter7++;
                break;
            case 8:
                counter8++;
                break;
            case 9:
                counter9++;
                break;
        }
        reminder = abs(number % 10);
        number = number / 10;
    }

    if ((counter0 >= 2) || (counter1 >= 2) || (counter2 >= 2) || (counter3 >= 2) ||
        (counter4 >= 2) || (counter5 >= 2) || (counter6 >= 2) || (counter7 >= 2) ||
        (counter8 >= 2) || (counter9 >= 2)) {
        cout << "There are repeating digits in the number.";
    } else {
        cout << "There are no repeating digits in the number.";
    }

    return 0;
}
