/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Anita Razpopova
* @idnumber 62495
* @task 3
* @compiler GCC
*
*/

#include <iostream>
#include <limits>

using namespace std;

int HexadecimalToDecimal(char hexadecimal) {
    int decimal;
        switch (hexadecimal) {
        case '0':
            decimal = 0;
            break;
        case '1':
            decimal = 1;
            break;
        case '2':
            decimal = 2;
            break;
        case '3':
            decimal = 3;
            break;
        case '4':
            decimal = 4;
            break;
        case '5':
            decimal = 5;
            break;
        case '6':
            decimal = 6;
            break;
        case '7':
            decimal = 7;
            break;
        case '8':
            decimal = 8;
            break;
        case '9':
            decimal = 9;
            break;
        case 'A':
            decimal = 10;
            break;
        case 'B':
            decimal = 11;
            break;
        case 'C':
            decimal = 12;
            break;
        case 'D':
            decimal = 13;
            break;
        case 'E':
            decimal = 14;
            break;
        case 'F':
            decimal = 15;
            break;
    }

    return decimal;
}

char DecimalToHexadecimal(int decimal) {
    char hexChar;
        switch (decimal) {
        case 0 :
            hexChar = '0';
            break;
        case 1:
            hexChar = '1';
            break;
        case 2:
            hexChar = '2';
            break;
        case 3:
            hexChar = '3';
            break;
        case 4:
            hexChar = '4';
            break;
        case 5:
            hexChar = '5';
            break;
        case 6:
            hexChar = '6';
            break;
        case 7:
            hexChar = '7';
            break;
        case 8:
            hexChar = '8';
            break;
        case 9:
            hexChar = '9';
            break;
        case 10:
            hexChar = 'A';
            break;
        case 11:
            hexChar = 'B';
            break;
        case 12:
            hexChar = 'C';
            break;
        case 13:
            hexChar = 'D';
            break;
        case 14:
            hexChar = 'E';
            break;
        case 15:
            hexChar = 'F';
            break;
    }

    return hexChar;
}

int main()
{
    char arithmeticOperator;
    char hexNumber1;
    char hexNumber2;
    int decNumber1;
    int decNumber2;
    int decResult; //decimal result

    cout << "Input operator (+, -, *, /, %)" << endl;
    cin >> arithmeticOperator;
    //Checking the data input.
    while(cin.fail() || !((arithmeticOperator == '+') || (arithmeticOperator == '-') ||
                        (arithmeticOperator == '*') || (arithmeticOperator == '/') || (arithmeticOperator == '%'))) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n" << endl;
        cin >> arithmeticOperator;
    }

    cout << "Input heaxadecimal first number/char : \n";
    cin >> hexNumber1;
    //Checking the data input.
    while(cin.fail() || !((hexNumber1 == '0') || (hexNumber1 == '1') || (hexNumber1 == '2') || (hexNumber1 == '3') ||
                        (hexNumber1 == '4') || (hexNumber1 == '5') || (hexNumber1 == '6') || (hexNumber1 == '7') ||
                        (hexNumber1 == '8') || (hexNumber1 == '9') || (hexNumber1 == 'A') || (hexNumber1 == 'B') ||
                        (hexNumber1 == 'C') || (hexNumber1 == 'D') || (hexNumber1 == 'E') || (hexNumber1 == 'F'))) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n" << endl;
        cin >> hexNumber1;
    }

     cout << "Input heaxadecimal second number/char : \n";
    cin >> hexNumber2;
    //Checking the data input.
    while(cin.fail() || !((hexNumber2 == '0') || (hexNumber2 == '1') || (hexNumber2 == '2') || (hexNumber2 == '3') ||
                        (hexNumber2 == '4') || (hexNumber2 == '5') || (hexNumber2 == '6') || (hexNumber2 == '7') ||
                        (hexNumber2 == '8') || (hexNumber2 == '9') || (hexNumber2 == 'A') || (hexNumber2 == 'B') ||
                        (hexNumber2 == 'C') || (hexNumber2 == 'D') || (hexNumber2 == 'E') || (hexNumber2 == 'F'))) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n" << endl;
        cin >> hexNumber2;
    }




    decNumber1 = HexadecimalToDecimal(hexNumber1);
    decNumber2 = HexadecimalToDecimal(hexNumber2);
    switch (arithmeticOperator){
        case '+':
            decResult = decNumber1 + decNumber2;
            break;
        case '-':
            decResult = decNumber1 - decNumber2;
            break;
        case '*':
            decResult = decNumber1 * decNumber2;
            break;
        case '/':
            decResult = decNumber1 / decNumber2;
            break;
        case '%':
            decResult = decNumber1 % decNumber2;
            break;
    }

    int secondSymbol;
    int firstSymbol;
    // The result is always going to have two digits as it is written in the task.
    secondSymbol = decResult % 16;
    decResult = decResult / 16;
    firstSymbol = decResult % 16;
    //cout << firstSymbol << secondSymbol;
    cout << DecimalToHexadecimal(firstSymbol) << DecimalToHexadecimal(secondSymbol);

    return 0;
}
