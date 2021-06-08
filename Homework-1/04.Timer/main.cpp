/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Anita Razpopova
* @idnumber 62495
* @task 4
* @compiler GCC
*
*/

#include <iostream>
#include <stdlib.h>
#include <limits>
using namespace std;

//Function slow down.
void slowDownProcess() {
    int operation;
    for (int b = 0; b < 20000000; b++){
        operation = b * b;
    }
}

int main()
{
    int num;

    cout << "Please input days in the range [1, 65535]" << endl;
    cin >> num;

//Checking the data input.
    while(cin.fail() || (num < 1) || (num > 65535)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n" << endl;
        cin >> num;
    }

    for (int i = num; i >= 0; i--){
        system("cls");
        cout << i;
        slowDownProcess();
    }

    return 0;
}

