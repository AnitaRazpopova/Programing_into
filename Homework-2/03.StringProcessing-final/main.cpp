/**
*
* Solution to homework assignment 2
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

using namespace std;

const unsigned short int MAX_LENGTH = 100;

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

void StringProcessing(char arr1[], size_t arr1Length, char arr2[], size_t arr2Length) {
    char shortString[MAX_LENGTH];
    char longString[MAX_LENGTH];
    char resultString[MAX_LENGTH];

    if (arr1Length > arr2Length) {
        strcpy(longString, arr1);
        strcpy(shortString, arr2);
    } else {
        strcpy(longString, arr2);
        strcpy(shortString, arr1);
    }

    size_t longStringLength = strlen(longString);
    size_t shortStringLength = strlen(shortString);

    // Repeating of the smaller string.
    strcpy(resultString, longString);
    size_t j = 0;
    for (size_t i = 0; i < longStringLength; i++) {
        if (j == shortStringLength) {
            j = 0;
        }

        resultString[i] = shortString[j];
        j++;
    }

    cout << "Result:\n" << resultString << endl;
}

int main()
{
    char arr1[MAX_LENGTH];
    char arr2[MAX_LENGTH];

    cout << "Input first string:" << endl;
    cin.getline(arr1, MAX_LENGTH);
    cout << "Input second string with different length:" << endl;
    cin.getline(arr2, MAX_LENGTH);

    size_t arr1Length = strlen(arr1);
    size_t arr2Length = strlen(arr2);

    // Check the first and second string are as equal length.
    while (arr1Length == arr2Length) {
        cout << "The first and second string are as equal length.\nPlease input strings with different lengths." << endl;
        cout << "Input first string:" << endl;
        cin.getline(arr1, MAX_LENGTH);
        cout << "Input second string with different length:" << endl;
        cin.getline(arr2, MAX_LENGTH);
        arr1Length = strlen(arr1);
        arr2Length = strlen(arr2);
    }

    StringProcessing(arr1, arr1Length, arr2, arr2Length);

    return 0;
}
