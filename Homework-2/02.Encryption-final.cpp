#include <iostream>
#include <limits>

using namespace std;

size_t strlen(const char* str)
{
    const char* pRead = str;
    while(*pRead != '\0') {
        pRead++;
    }

    return pRead - str;
}

void Encryption(char text[], size_t strLength, unsigned short int numberToIncrease, unsigned short int positionOffset)
{
    char encryptedString[100];
    // Check if characters in string are valid.
    bool isSymbolValid  = true;
    for (size_t i = 0; i < strLength; i++) {
        if (text[i] < 32 || text[i] > 126) {
            isSymbolValid  = false;
        }
    }

    // If characters in text are valid executed encrypt.
    if (isSymbolValid ) {
        unsigned short int newPosition = positionOffset;
        for (size_t i = 0; i < strLength; i++) {
            // If the new position of a character is greater than string length,
            // then the numbering of positions continues from the beginning of string.
            if (newPosition >= strLength) {
                newPosition %= strLength;
            }
        // Replacement of the original symbol:
        encryptedString[newPosition] = text[i] + numberToIncrease;
        newPosition++;
        }
        encryptedString[strLength] = '\0';
        cout << encryptedString;
    } else {
        cout << text;
    }
}

int main()
{
    char text[100];
    int numberToIncrease;
    unsigned short int positionOffset;

    cout << "Enter string to encryption (length <= 100):" << endl;
    cin.getline(text, 100);

    cout << "Enter number to increase ASCII code smaller or equal than 20:" << endl;
    cin >> numberToIncrease;
    //Checking the data input.
    while(cin.fail() || numberToIncrease < 0 || numberToIncrease > 20) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input" << endl;
        cin >> numberToIncrease;
    }
    cout << "Enter position offset smaller than string length:" << endl;
    cin >> positionOffset;

    size_t strLength = strlen(text);

    //Checking the data input.
    while(cin.fail() || positionOffset >= strLength) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input" << endl;
        cin >> positionOffset;
    }

    Encryption(text, strLength, numberToIncrease, positionOffset);

    return 0;
}
