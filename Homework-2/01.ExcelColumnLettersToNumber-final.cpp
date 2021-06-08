#include <iostream>
#include <limits>

using namespace std;

const unsigned short int NUMBER_OF_SYMBOLS = 3;
const unsigned short int NUMBER_OF_LETTERS = 26;
const unsigned short int DECIMAL_VALUE_CHAR_A = 65;
const unsigned short int DECIMAL_VALUE_CHAR_Z = 90;

// Finding the length of a string
size_t strlen(const char* str)
{
    const char* pRead = str;
    while(*pRead != '\0') {
        pRead++;
    }

    return pRead - str;
}

// Check that the characters are valid.
bool IsSymbolValid(char columnName[], size_t nameLength)
{
    bool isInputValid = true;
    for (unsigned short int i = 0; i < nameLength; i++) {
        if (columnName[i] < DECIMAL_VALUE_CHAR_A || columnName[i] > DECIMAL_VALUE_CHAR_Z) {
            isInputValid  = false;
        }
    }
    return isInputValid;
}

// Conv ert column name to number.
 void ConvertColumnNameToNumber(char columnName[], size_t nameLength) {
    int number = 0;
    int power = 1;

    for (int i = nameLength - 1; i >= 0; i--) {
        number = number + (columnName[i] - 'A' + 1) * power;
        power *= NUMBER_OF_LETTERS;
    }

    cout << number;
}

int main()
{
    char columnName[NUMBER_OF_SYMBOLS + 1];
    size_t nameLength;

    cout << "Insert Excel column name: ";
    cin.getline(columnName, numeric_limits<streamsize>::max());
    nameLength = strlen(columnName);

    //Verification of input data.
    while (nameLength > NUMBER_OF_SYMBOLS || !IsSymbolValid(columnName, nameLength)) {
        cin.clear();
        cout << "Invalid input" << endl;
        cin.getline(columnName, numeric_limits<streamsize>::max());
        nameLength = strlen(columnName);
    }

    ConvertColumnNameToNumber(columnName, nameLength);

    return 0;
}
