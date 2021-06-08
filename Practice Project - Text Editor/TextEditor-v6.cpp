#include <iostream>
#include <limits>

using namespace std;

const short int MAX_LENGTH = 1000;
const short int FIRST_VARIANT = 1;
const short int LAST_VARIANT_EXIT = 7;

size_t strlen(const char* str)
{
    const char* pRead = str;
    while(*pRead != '\0') {
        pRead++;
    }

    return pRead - str;
}

char* strcpy(char* dest, const char* src)
{
    do {
        *dest++ = *src;
    } while(*src++ != '\0');

    return dest;
}

void toUppercase(char* text)
{
    size_t textLength = strlen(text);
    for (unsigned int i = 0; i < textLength; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - ('a' - 'A');
        }
    }
}

void toLowercase(char* text)
{
    size_t textLength = strlen(text);
    for (unsigned int i = 0; i < textLength; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] + ('a' - 'A');
        }
    }
}

int findWord(char* word, const char* text)
{
    int index = -1;
    size_t wordLength = strlen(word);
    size_t textLength = strlen(text);

    if (wordLength > textLength) {
        return index;
    }

    for (unsigned int i = 0; i <= textLength - wordLength; i++) {
        index = i;
        for (unsigned int j = 0; j < wordLength; j ++) {
            if (text[j + i] != word[j]) {
                index = -1;
                break;
            }
        }
        if (index != -1) {
            return index;
        }
    }

    return index;
}

void deleteWord(char* word, char* text)
{
    size_t textLength = strlen(text);
    size_t wordLength = strlen(word);

    int index = findWord(word, text);
    int newIndex = 0;

    if (index != -1) {
        for (unsigned int i = 0; i < textLength; i++) {
            if ((int)i == index) {
                i += wordLength;
            }
            text[newIndex] = text[i];
            newIndex++;
        }
        text[textLength - wordLength] = '\0';

        deleteWord(word, text);
    }
}

void replaceWord(char* word, char* newWord, char* text, char* newText)
{
    size_t textLength = strlen(text);
    size_t wordLength = strlen(word);
    size_t newWordLength = strlen(newWord);

    int differnce = newWordLength - wordLength;
    int index = findWord(word, text);
    int newIndex = 0;

    if (index != -1) {
        for (unsigned int i = 0; i < textLength; i++) {
            if ((int)i == index) {
                for (unsigned int j = 0; j < newWordLength; j++) {
                    newText[newIndex++] = newWord[j];
                }
                index = - 1;
                i += wordLength;
            }
            newText[newIndex++] = text[i];
        }
        newText[textLength + differnce] = '\0';
    }
}

void addSentence(int position, char* sentence, char* text, char* newText)
{
    size_t textLength = strlen(text);
    size_t sentenceLength = strlen(sentence);
    int newIndex = 0;

    for (unsigned int i = 0; i <= textLength; i++) {
        if ((int)i == position) {
            for (unsigned int j = 0; j < sentenceLength; j++) {
                newText[newIndex++] = sentence[j];
            }
        }
        newText[newIndex++] = text[i];
    }
    newText[textLength + sentenceLength] = '\0';
}

int main()
{
    char text[MAX_LENGTH + 1];
    char word[MAX_LENGTH + 1];
    char newWord[MAX_LENGTH + 1];
    char newText[MAX_LENGTH * 2 + 1];
    char sentence[MAX_LENGTH + 1];

    unsigned short int action;
    int index;
    unsigned int position;

    cout << "Enter text to work with:" << endl;
    cin.getline(text, MAX_LENGTH);

    cout << "\nWhat would you like to do?\n1 = uppercase, 2 = lowercase, 3 = search, 4 = delete, 5 = replace, 6 = add or 7 = exit" << endl;
    cin >> action;

    //Checking the data input.
    while(cin.fail() || action < FIRST_VARIANT || action > LAST_VARIANT_EXIT) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        /*The cin.clear() clears the error flag on cin (so that future I/O operations will work correctly),
        and then cin.ignore(10000, '\n') skips to the next newline (to ignore anything else on the same line
        as the non-number so that it does not cause another parse failure).
        It will only skip up to 10000 characters, so the code is assuming the user will not put in a very long,
        invalid line.
        numeric_limits<streamsize>::max() sets the maximum number of characters to ignore. Since this is the
        upper limit on the size of a stream, you are effectively telling cin that there is no limit to the
        number of characters to ignore.*/
        cout << "Invalid input." << endl;
        cout << "\nWhat would you like to do?\n1 = uppercase, 2 = lowercase, 3 = search, 4 = delete, 5 = replace, 6 = add or 7 = exit" << endl;
        cin >> action;
    }

    while (cin.fail() || action != LAST_VARIANT_EXIT) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(action) {
            case 1:
                toUppercase(text);
                cout << text << endl;
                break;
            case 2:
                toLowercase(text);
                cout << text << endl;
                break;
            case 3:
                cout << "Enter word to search for:" << endl;
                cin.getline(word, MAX_LENGTH);
                index = findWord(word, text);
                if (index != -1) {
                    cout << "The text contains: " << word << "\nThe index where the found word begins is: " << index << endl;
                } else {
                    cout << "The text does not contain: " << word << endl;
                }
                break;
            case 4:
                cout << "Enter word to delete:" << endl;
                cin.getline(word, MAX_LENGTH);
                deleteWord(word, text);
                cout << text << endl;
                break;
            case 5:
                cout << "Enter word to find and to replace with separated by a space:" << endl;
                cin >> word >> newWord;
                replaceWord(word, newWord, text, newText);
                cout << newText << endl;
                strcpy(text, newText);
                break;
            case 6:
                cout << "Enter position and sentence to add:" << endl;
                cin >> position;
                cin.ignore(1, '\n');
                cin.getline(sentence, MAX_LENGTH);
                while(cin.fail() || position < 0 || position > strlen(text)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input." << endl;
                    cout << "Enter position and sentence to add:" << endl;
                    cin >> position;
                    cin.ignore(1, '\n');
                    cin.getline(sentence, MAX_LENGTH);
                }
                addSentence(position, sentence, text, newText);
                cout << newText << endl;
                strcpy(text, newText);
                break;
            default:
                cout << "Invalid input" << endl;
        }

        cout << "\nWhat would you like to do?\n1 = uppercase, 2 = lowercase, 3 = search, 4 = delete, 5 = replace, 6 = add or 7 = exit" << endl;
        cin >> action;
    }
}
