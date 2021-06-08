#include <iostream>

using namespace std;

const unsigned short int MAX_LENGTH = 100;
const unsigned short int ASCII_CODE_CHAR_DASH = 45;
const unsigned short int ASCII_CODE_CHAR_A = 65;
const unsigned short int ASCII_CODE_CHAR_Z = 90;
const unsigned short int ASCII_CODE_CHAR_UNDERSCORE = 95;
const unsigned short int ASCII_CODE_CHAR_SMALL_A = 97;
const unsigned short int ASCII_CODE_CHAR_SMALL_Z = 122;

// Finding the length of a string
size_t strlen(const char* str)
{
    const char* pRead = str;
    while(*pRead != '\0') {
        pRead++;
    }

    return pRead - str;
}

// Finding count of smallest words
int CountOfSmallestWords(char sentence[], size_t sentenceLength)
{
    int symbolsInWord = 0;
    int symbolsInSmallestWord = MAX_LENGTH;
    int countOfSmallestWords = 0;
    int index = 0;
    bool isWordValid = true;

    for (size_t i = 0; i < sentenceLength; i++) {
        // Separation of words:
        while(sentence[index] != ' ' && sentence[index] != '\t' && sentence[index] != '\0') {
            // Check that the word are valid.
            if (!((sentence[index] >= ASCII_CODE_CHAR_A && sentence[index] <= ASCII_CODE_CHAR_Z) ||
                  (sentence[index] >= ASCII_CODE_CHAR_SMALL_A && sentence[index] <= ASCII_CODE_CHAR_SMALL_Z) ||
                  (sentence[index] == ASCII_CODE_CHAR_DASH) ||
                  (sentence[index] == ASCII_CODE_CHAR_UNDERSCORE))) {
                isWordValid = false;
            }
            symbolsInWord++;
            index++;
        }
        i = ++index;

        if (isWordValid == false || symbolsInWord < 2) {
            continue;
        } else if (symbolsInWord == symbolsInSmallestWord) {
            countOfSmallestWords++;
        } else if (symbolsInWord < symbolsInSmallestWord && symbolsInWord > 1) {
            symbolsInSmallestWord = symbolsInWord;
            countOfSmallestWords = 1;
        }

        symbolsInWord = 0;
        isWordValid =  true;
    }

    return countOfSmallestWords;
}

int main()
{
    char sentence[MAX_LENGTH];
    cout << "Insert sentence: ";
    cin.getline(sentence, MAX_LENGTH);
    size_t sentenceLength = strlen(sentence);

    cout << "The count of smallest words is: "<< CountOfSmallestWords(sentence, sentenceLength) << endl;

    return 0;
}
