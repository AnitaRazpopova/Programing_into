/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Anita Razpopova
* @idnumber 62495
* @task 2
* @compiler GCC
*
*/

#include <iostream>
#include <limits>

using namespace std;

const int MAX_LENGTH = 10000;

// Finding the length of a string
size_t strlen(const char* str)
{
    const char* pRead = str;
    while(*pRead != '\0') {
        pRead++;
    }

    return pRead - str;
}

// Copy a string
char* strcpy(char* dest, const char* src)
{
    do {
        *dest++ = *src;
    } while(*src++ != '\0');

    return dest;
}

// Checking if first number is biggest.
bool isBiggest(char numAsStr1[], char numAsStr2[], size_t length)
{
    for (unsigned int i=0; i < length; i++) {
        if (numAsStr1[i] > numAsStr2[i])
            return true;
        else if (numAsStr1[i] < numAsStr2[i])
            return false;
    }

    return true;
}

// Calculate summing:
char* add(char numAsStr1[], size_t num1Length, char numAsStr2[], size_t num2Length, char* resultOfAdd)
{
    int carry = 0;
    int sum;
    int i;
    unsigned int j;
    unsigned int k;

    char shortNumAsString[MAX_LENGTH];
    char longNumAsString[MAX_LENGTH];
    char result[MAX_LENGTH];

    if (num1Length > num2Length) {
        strcpy(longNumAsString, numAsStr1);
        strcpy(shortNumAsString, numAsStr2);
    } else {
        strcpy(longNumAsString, numAsStr2);
        strcpy(shortNumAsString, numAsStr1);
    }

    size_t shortStrLength = strlen(shortNumAsString);
    size_t longStrLength = strlen(longNumAsString);

    j = longStrLength;
    result[j] = '\0';

    for (i = shortStrLength - 1; i >= 0; i--){
        sum = shortNumAsString[i] + longNumAsString[i + longStrLength - shortStrLength] + carry - 2*'0';
        carry = sum / 10;
        sum %= 10;
        result[--j] = (char)(sum + '0');
    }

    i = longStrLength - shortStrLength - 1;

    while (i >= 0){
        sum = longNumAsString[i] + carry - '0';
        carry = sum / 10;
        sum %= 10;
        result[--j] = (char)(sum + '0');
        i--;
    }

    size_t resultLength = strlen(result);
    if (carry != 0){
        resultOfAdd[0] = (char)(carry + '0');
        for (k = 1; k <= resultLength; k++) {
            resultOfAdd[k] = result[k - 1];
        }
        resultOfAdd[resultLength + 1] = '\0';
    } else {
        strcpy(resultOfAdd, result);
    }

    return resultOfAdd;
}

// Calculate subtraction:
char* subtraction(char numAsStr1[],
                  size_t num1Length,
                  char numAsStr2[],
                  size_t num2Length,
                  bool isStr1Negative,
                  bool isStr2Negative,
                  char* resultOfSubtraction)
{
    int carry = 0;
    int subtraction;
    int index = 0;
    int i;
    unsigned int j = 0;

    char shortNumAsString[MAX_LENGTH];
    char longNumAsString[MAX_LENGTH];
    char result[MAX_LENGTH];

    bool isResultMinus = false;

    if ((num1Length > num2Length && !isStr1Negative && !isStr2Negative) ||
        (num1Length > num2Length && !isStr1Negative && isStr2Negative) ||
        (num1Length == num2Length && isBiggest(numAsStr1, numAsStr2, num1Length) && !isStr1Negative && !isStr2Negative) ||
        (num1Length == num2Length && isBiggest(numAsStr1, numAsStr2, num1Length) && !isStr1Negative && isStr2Negative)){
        strcpy(longNumAsString, numAsStr1);
        strcpy(shortNumAsString, numAsStr2);
    } else if ((num1Length < num2Length && !isStr1Negative && !isStr2Negative) ||
               (num1Length < num2Length && !isStr1Negative && isStr2Negative) ||
               (num1Length == num2Length && !isBiggest(numAsStr1, numAsStr2, num1Length) && !isStr1Negative && !isStr2Negative)){
        strcpy(longNumAsString, numAsStr2);
        strcpy(shortNumAsString, numAsStr1);
        isResultMinus = true;
    } else if ((num1Length > num2Length && isStr1Negative && isStr2Negative) ||
               (num1Length > num2Length && isStr1Negative && !isStr2Negative) ||
               (num1Length == num2Length && isBiggest(numAsStr1, numAsStr2, num1Length) && isStr1Negative && !isStr2Negative)){
        strcpy(longNumAsString, numAsStr1);
        strcpy(shortNumAsString, numAsStr2);
        isResultMinus = true;
    } else if ((num1Length < num2Length && isStr1Negative && isStr2Negative) ||
               (num1Length < num2Length && isStr1Negative && !isStr2Negative) ||
               (num1Length == num2Length && !isBiggest(numAsStr1, numAsStr2, num1Length) && isStr1Negative && !isStr2Negative) ||
               (num1Length == num2Length && !isBiggest(numAsStr1, numAsStr2, num1Length) && isStr1Negative && isStr2Negative)) {
        strcpy(longNumAsString, numAsStr2);
        strcpy(shortNumAsString, numAsStr1);
    }

    size_t shortStrLength = strlen(shortNumAsString);
    size_t longStrLength = strlen(longNumAsString);
    size_t difference = longStrLength - shortStrLength;

    for (i = shortStrLength - 1; i >= 0; i--) {
        subtraction = ((longNumAsString[i + difference] - '0') - (shortNumAsString[i] - '0') - carry);
        if (subtraction < 0) {
            subtraction = subtraction + 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result[index++] = subtraction + '0';
    }

    for (i = difference - 1; i >= 0; i--) {
        if (longNumAsString[i] == '0' && carry) {
            result[index++] = '9';
            continue;
        }

        subtraction = ((longNumAsString[i] - '0') - carry);
        if (i > 0 || subtraction > 0) {
            result[index++] = subtraction + '0';
        }

        carry = 0;
    }

    if (isResultMinus) {
        resultOfSubtraction[j++] = '-';
    }

    bool isZero = true;
    size_t resultLength = strlen(result);
    for(i = resultLength - 1; i >= 0; i--){
        if (result[i] != '0') {
            isZero = false;
        }
        resultOfSubtraction[j++] = result[i];
    }

    resultOfSubtraction[j] = '\0';

    if (isZero) {
        resultOfSubtraction[0] = '0';
        resultOfSubtraction[1] = '\0';
    }

    return resultOfSubtraction;
}

// Calculate multiplying:
char* multiply(char numAsStr1[], char numAsStr2[], char* resultOfMultiply)
{
    char result[MAX_LENGTH * 2];
    char temp[MAX_LENGTH * 2];

    int i;
    int j;
    int k = 0;
    int m;
    int x = 0;
    int y;

    long int carry = 0;
    long sum = 0;

    int numAsStr1Length = strlen(numAsStr1);
    int numAsStr2Length = strlen(numAsStr2);

    for(i = 0; i < numAsStr1Length; i++){
        numAsStr1[i] = numAsStr1[i] - '0';
    }

    for(i = 0; i < numAsStr2Length; i++){
        numAsStr2[i] = numAsStr2[i] - '0';
    }

    for(i = numAsStr2Length - 1; i >= 0; i--){
        carry = 0;
        for(j = numAsStr1Length - 1; j >= 0; j--){
            temp[k++] = (numAsStr2[i] * numAsStr1[j] + carry)%10;
            carry = (numAsStr2[i]*numAsStr1[j] + carry)/10;
        }
        temp[k++] = carry;
        x++;
        for(y = 0; y < x; y++){
            temp[k++] = 0;
        }
    }

    k = 0;
    carry = 0;
    for(i = 0; i < numAsStr1Length + numAsStr2Length; i++){
        sum = 0;
        y = 0;
        for(j = 1; j <= numAsStr2Length; j++){
            if(i <= numAsStr1Length + j){
                sum = sum + temp[y + i];
            }
            y += j + numAsStr1Length;
        }
        result[k++] = (sum + carry) % 10;
        carry = (sum + carry) / 10;
    }

    result[k] = carry;
    j = 0;
    m = k - 1;
    if (result[m] == 0) {
        k--;
    }

    for(i = k - 1; i >= 0; i--){
        resultOfMultiply[j++] = result[i] + '0';
    }

    resultOfMultiply[j] = '\0';

    return resultOfMultiply;
}

int main()
{
    const int MAX_LENGTH_LIMIT = 100;
    const unsigned short int ASCII_VALUE_OF_0 = 48;
    const unsigned short int ASCII_VALUE_OF_9 = 57;

    char arithmeticOperator;
    char str1[MAX_LENGTH];
    char numAsStr1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char numAsStr2[MAX_LENGTH];
    char resultOfAdd[MAX_LENGTH];
    char resultOfSubtraction[MAX_LENGTH];
    char resultOfMultiply[MAX_LENGTH * 2];

    bool isStr1Negative = false;
    bool isStr2Negative = false;
    bool isNumAsStrValid;

    size_t num1Length;
    size_t num2Length;

    cout << "Insert arithmetic operator +, -, *: ";
    cin >> arithmeticOperator;
    while (cin.fail() || !(arithmeticOperator == '+' || arithmeticOperator == '-' || arithmeticOperator == '*')) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input." << endl;
        cout << "Insert arithmetic operator +, -, *: " << endl;
        cin >> arithmeticOperator;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Inputting and check first number.
    do {
        isNumAsStrValid = true;

        cout << "Insert first number /maximum size 100 digits/: ";
        cin >> str1;
        num1Length = strlen(str1);

        if (str1[0] == '-') {
            for (unsigned int i = 1; i < num1Length; i++) {
                if (str1[i] < ASCII_VALUE_OF_0 || str1[i] > ASCII_VALUE_OF_9) {
                    isNumAsStrValid = false;
                    cout << "Invalid first number" << endl;
                    break;
                }
                numAsStr1[i - 1] = str1[i];
            }
            numAsStr1[num1Length - 1] = '\0';
            num1Length--;
            isStr1Negative = true;
        } else {
            for (unsigned int i = 0; i < num1Length; i++) {
                if (str1[i] < ASCII_VALUE_OF_0 || str1[i] > ASCII_VALUE_OF_9) {
                    isNumAsStrValid = false;
                    cout << "Invalid first number" << endl;
                    break;
                }
                numAsStr1[i] = str1[i];
            }
            numAsStr1[num1Length] = '\0';
        }

        if (num1Length > MAX_LENGTH_LIMIT) {
            isNumAsStrValid = false;
            cout << "Invalid first number. Maximum size should be 100 digits." << endl;
        }

    } while (!isNumAsStrValid);

    do {
        isNumAsStrValid = true;

        cout << "Insert second number /maximum size 100 digits/: ";
        cin >> str2;
        num2Length = strlen(str2);

        if (str2[0] == '-') {
            for (unsigned int i = 1; i < num2Length; i++) {
                if (str2[i] < ASCII_VALUE_OF_0 || str2[i] > ASCII_VALUE_OF_9) {
                    isNumAsStrValid = false;
                    cout << "Invalid second number" << endl;
                    break;
                }
                numAsStr2[i - 1] = str2[i];
            }
            numAsStr2[num2Length - 1] = '\0';
            num2Length--;
            isStr2Negative = true;
        } else {
            for (unsigned int i = 0; i < num2Length; i++) {
                if (str2[i] < ASCII_VALUE_OF_0 || str2[i] > ASCII_VALUE_OF_9) {
                    isNumAsStrValid = false;
                    cout << "Invalid second number" << endl;
                    break;
                }
                numAsStr2[i] = str2[i];
            }
            numAsStr2[num2Length] = '\0';
        }

        if (num2Length > MAX_LENGTH_LIMIT) {
            isNumAsStrValid = false;
            cout << "Invalid second number. Maximum size should be 100 digits." << endl;
        }

    } while (!isNumAsStrValid);

    switch (arithmeticOperator){
        case '+':
            cout << "The result of summing is: ";
            if (!isStr1Negative && !isStr2Negative) {
                add(numAsStr1, num1Length, numAsStr2, num2Length, resultOfAdd);
                cout << resultOfAdd << endl;
            } else if (isStr1Negative && isStr2Negative) {
                add(numAsStr1, num1Length, numAsStr2, num2Length, resultOfAdd);
                cout << '-' << resultOfAdd << endl;
            } else if ((isStr1Negative && !isStr2Negative) || (!isStr1Negative && isStr2Negative)) {
                subtraction(numAsStr1,
                            num1Length,
                            numAsStr2,
                            num2Length,
                            isStr1Negative,
                            isStr2Negative,
                            resultOfSubtraction);

                cout << resultOfSubtraction << endl;
            }
            break;
        case '-':
            cout << "The result of subtraction is: ";
            if (isStr1Negative && !isStr2Negative) {
                add(numAsStr1, num1Length, numAsStr2, num2Length, resultOfAdd);
                cout << '-' << resultOfAdd << endl;
            } else if (!isStr1Negative && isStr2Negative) {
                add(numAsStr1, num1Length, numAsStr2, num2Length, resultOfAdd);
                cout << resultOfAdd << endl;
            } else {
                subtraction(numAsStr1,
                            num1Length,
                            numAsStr2,
                            num2Length,
                            isStr1Negative,
                            isStr2Negative,
                            resultOfSubtraction);

                cout << resultOfSubtraction << endl;
            }
            break;
        case '*':
            cout << "The result of multiplying is: ";
            multiply(numAsStr1, numAsStr2, resultOfMultiply);

            if ((isStr1Negative && isStr2Negative) || (!isStr1Negative && !isStr2Negative)) {
                cout << resultOfMultiply << endl;
            } else {
                cout << '-' << resultOfMultiply << endl;
            }
            break;
        default:
            break;
    }

    return 0;
}
