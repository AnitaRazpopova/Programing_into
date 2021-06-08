/**
*
* Solution to homework assignment 3
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

const short int MAX_LENGTH = 255;
const short int MAX_WORDS = 10;

// Finding the length of a string
size_t strlen(const char* str)
{
    const char* pRead = str;
    while(*pRead != '\0') {
        pRead++;
    }

    return pRead - str;
}

// Function which receives a string as a parameter and checks that it is a word from the language.
int isWord(char * wordForCheck) {
    char newWord[MAX_LENGTH];
    size_t wordLength = strlen(wordForCheck);
    bool emptyWord = false;
    bool wordBeforeC = false;
    bool wordAAB = false;
    bool wordC = false;
    bool wordD = false;
    size_t centerPosition = wordLength / 2;

    if (wordLength == 0) {
        emptyWord = true;
    }

    if (wordLength == 1 && wordForCheck[0] == 'C') {
        wordC = true;
    }

    if (wordLength == 1 && wordForCheck[0] == 'D') {
        wordD = true;
    }

    if (wordLength == 2 || wordLength > 64) {
        return 0;
    }

    if (wordLength == 3 && wordForCheck[0] == 'A' && wordForCheck[1] == 'A' && wordForCheck[2] == 'B') {
        wordAAB = true;
    }

    if (wordLength > 3) {
        size_t i = 0;
        for (; i < wordLength; i++) {
            newWord[i] = wordForCheck[i];
            if (wordForCheck[i] == 'C') {
                newWord[i] = '\0';
                if (isWord(newWord) == 1) {
                    wordBeforeC = true;
                    break;
                }
            }
        }

        if(wordBeforeC) {
            newWord[i] = '\0';
            i++;
            int j = 0;
            if (i < wordLength) {
                for (; i < wordLength; i++) {
                    newWord[j++] = wordForCheck[i];
                }
                newWord[j] = '\0';
                if (isWord(newWord) == 1) {
                    return 1;
                }
            }
        }
    }

    if (wordLength >= 3 && (wordLength % 2 != 0) && (wordForCheck[centerPosition] == 'C' || wordForCheck[centerPosition] == 'D')) {
        bool isEqual = true;
        for (size_t i = 0; i < centerPosition; i++) {
            if (wordForCheck[i] != wordForCheck[centerPosition + i + 1]) {
                isEqual = false;
                return 0;
            }
            newWord[i] = wordForCheck[i];
        }
        newWord[centerPosition] = '\0';

        if (isEqual) {
            if (isWord(newWord) == 1) {
                return 1;
            }
        }
    }

    if (wordLength > 3 && wordForCheck[0] == 'A' && wordForCheck[1] == 'A' && wordForCheck[wordLength - 1] == 'B') {
        for (size_t i = 2; i < wordLength - 1; i++) {
            newWord[i - 2] = wordForCheck[i];
        }
        newWord[wordLength - 3] = '\0';

        if (isWord(newWord) == 1) {
            return 1;
        }
    }

    if (wordLength > 3 && wordForCheck[0] == 'C') {
        for (size_t i = 1; i < wordLength; i++) {
            newWord[i - 1] = wordForCheck[i];
        }
        newWord[wordLength - 1] = '\0';

        if (isWord(newWord) == 1) {
            return 1;
        }
    }

    if (wordLength > 3 && wordForCheck[wordLength - 1] == 'C') {
        for (size_t i = 0; i < wordLength - 1; i++) {
            newWord[i] = wordForCheck[i];
        }
        newWord[wordLength - 1] = '\0';

        if (isWord(newWord) == 1) {
            return 1;
        }
    }

    if (emptyWord || wordAAB || wordC || wordD) {
        return 1;
    }

    return 0;
}

int main()
{
    char inputWord[MAX_LENGTH + 1];
    int numberOfStrings;

    cout << "Enter the number of strings: ";
    cin >> numberOfStrings;
    int result[numberOfStrings];

    //Checking the data input.
    while(cin.fail() || numberOfStrings < 0 || numberOfStrings > MAX_WORDS) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input.\nEnter the number of strings: ";
        cin >> numberOfStrings;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter string up to 255 characters" << endl;
    for (int i = 0; i < numberOfStrings; i++) {
        cin.getline(inputWord, MAX_LENGTH + 1);
        result[i] =  isWord(inputWord);
    }

    cout << "\nResult:\n";
    for (int i = 0; i < numberOfStrings; i++) {
        cout << result[i] << endl;
    }

    return 0;
}
