/**
*
* Solution to homework assignment 3
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

#include <algorithm>
#include <iostream>
#include <limits>
#include <time.h>

using namespace std;

const int NUMBER_OF_QUESTIONS = 10;
const int MAX_LENGTH = 100;

struct Question {
    char question[MAX_LENGTH];
    char answerA[MAX_LENGTH];
    char answerB[MAX_LENGTH];
    char answerC[MAX_LENGTH];
    char answerD[MAX_LENGTH];
    char trueAnswer;
};

struct Question50Percent {
    char answerA[MAX_LENGTH];
    char answerB[MAX_LENGTH];
    char answerC[MAX_LENGTH];
    char answerD[MAX_LENGTH];
};

// A simplified "database" with game questions.
Question listOfQuestions[NUMBER_OF_QUESTIONS] = {
    {"Which continent is Ghana located in?", "South America", "Africa", "North America", "Antarctica", 'b'},
    {"Which country has the largest population?", "Argentina", "USA", "Japan", "China", 'd'},
    {"What is the capital of Australia?", "Vienna", "Canberra", "Sydney", "Melbourne", 'b'},
    {"When was the Trojan war?", "1183 - 1193", "103 - 113", "193 - 183 BC", "1193 - 1183 BC", 'd'},
    {"Ballet originated in which country?", "South Africa", "China", "Brazil", "Italy", 'd'},
    {"Which zodiac sign is not represented by a horned animal?", "Capricorn", "Virgo", "Taurus", "Aries", 'b'},
    {"Which country hosted the 1992 Summer Olympics?", "Malaysia", "Iceland", "New Zealand", "Spain", 'd'},
    {"Which island go the animals from the New York Zoo from the movie of the same name?", "Madagascar", "Tasmania", "Hawaii", "Bermuda", 'a'},
    {"What people do on social media?", "silhouette", "full-face", "profile", "bas-relief", 'c'},
    {"Who is the lead actor in the movie Matrix?", "Keanu Reeves", "Jim Carrey", "Tom Hanks", "Will Smith", 'a'},
};

// A simplified "database" with reduced to 50/50 answers.
Question50Percent listOfQuestions50Percent[NUMBER_OF_QUESTIONS] = {
    {" ", "Africa", " ", "Antarctica"},
    {" ", "USA", " ", "China"},
    {" ", "Canberra", "Sydney", " "},
    {"1183 - 1193", " ", " ", "1193 - 1183 BC"},
    {" ", " ", "Brazil", "Italy"},
    {" ", "Virgo", " ", "Aries"},
    {"Malaysia", " ", " ", "Spain"},
    {"Madagascar", "Tasmania", " ", " "},
    {"silhouette", " ", "profile", " "},
    {"Keanu Reeves", "Jim Carrey", " ", " "},
};

// Generating array of unique random number in a range 0 - 9.
void generateNumberOfQuestion (int *questionsNumbers)
{
    int newNumberOfQuestion;
	bool isExist;
    srand (time(NULL));

    for (int i = 0; i < NUMBER_OF_QUESTIONS; i++) {
		do{
            isExist = true;
			newNumberOfQuestion = rand()%10;
			for(int j = 0; j < NUMBER_OF_QUESTIONS; j++ ){
				if( newNumberOfQuestion == questionsNumbers[j] ){
                    isExist = false;
				}
			}
		} while (!isExist);
        questionsNumbers[i] = newNumberOfQuestion;
    }
}

int main()
{
    int randomQuestionsNumbers[NUMBER_OF_QUESTIONS];
    int questionNumber = 0;
    char choice;
    char willYouPlay;

    generateNumberOfQuestion(randomQuestionsNumbers);

    do {
        cout << listOfQuestions[randomQuestionsNumbers[questionNumber]].question << endl;
        cout << "answer a: " << listOfQuestions[randomQuestionsNumbers[questionNumber]].answerA << endl;
        cout << "answer b: " << listOfQuestions[randomQuestionsNumbers[questionNumber]].answerB << endl;
        cout << "answer c: " << listOfQuestions[randomQuestionsNumbers[questionNumber]].answerC << endl;
        cout << "answer d: " << listOfQuestions[randomQuestionsNumbers[questionNumber]].answerD << endl;
        cout << endl;

        cout << "Enter your answer \"a\", \"b\", \"c\", \"d\" or if you want a 50/50 joker enter \"j\": ";
        cin >> choice;
        while (cin.fail() || !(choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd' || choice == 'j')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            cout << "Enter your answer \"a\", \"b\", \"c\", \"d\" or if you want a 50/50 joker enter \"j\": ";
            cin >> choice;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 'j') {
            cout << "answer a: " << listOfQuestions50Percent[randomQuestionsNumbers[questionNumber]].answerA << endl;
            cout << "answer b: " << listOfQuestions50Percent[randomQuestionsNumbers[questionNumber]].answerB << endl;
            cout << "answer c: " << listOfQuestions50Percent[randomQuestionsNumbers[questionNumber]].answerC << endl;
            cout << "answer d: " << listOfQuestions50Percent[randomQuestionsNumbers[questionNumber]].answerD << endl;
            cout << "Enter your answer: ";
            cin >> choice;
            while (cin.fail() || !(choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd')) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input.\n";
                cout << "Enter your answer: ";
                cin >> choice;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (choice == listOfQuestions[randomQuestionsNumbers[questionNumber]].trueAnswer) {
            cout << "YOU WIN!"  << endl;
        } else {
            cout << "YOU LOSE!"  << endl;
        }

        cout << "Will you play again? Enter \"y\" for Yes or \"e\" for Exit: ";
        cin >> willYouPlay;
        while (cin.fail() || !(willYouPlay == 'y' || willYouPlay == 'e')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            cout << "Will you play again? Enter \"y\" for Yes or \"e\" for Exit: ";
            cin >> willYouPlay;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        questionNumber++;

        if (questionNumber == NUMBER_OF_QUESTIONS){
            cout << "No mote questions!" << endl;
        }
    } while (questionNumber < NUMBER_OF_QUESTIONS && willYouPlay == 'y');

    return 0;
}
