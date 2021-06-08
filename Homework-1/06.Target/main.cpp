/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Anita Razpopova
* @idnumber 62495
* @task 6
* @compiler GCC
*
*/

#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

int main()
{
    const double CENTER_X = 0.0;
    const double CENTER_Y = 0.0;
    const double TOP_RIGHT_X = 1.0;
    const double BOTTOM_LEFT_X = -1.0;
    const double TOP_RIGHT_Y = 1.0;
    const double BOTTOM_LEFT_Y = -1.0;
    const double BIG_RADIUS = 3.0;
    const double SMALL_RADIUS = 2.0;

    double x;
    double y;
    double distance;

    cout << "Input x\n";
    cin >> x;
     //Checking the data input for x.
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n" << endl;
        cin >> x;
    }

    cout << "Input y\n";
    cin >> y;
     //Checking the data input for y.
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n" << endl;
        cin >> y;
    }

    distance = sqrt((x - CENTER_X) * (x - CENTER_X) + (y - CENTER_Y) * (y - CENTER_Y));
    //cout << "the distance is: " << distance << "\n";

    if (distance > BIG_RADIUS){
        cout << "Outside";
    } else if ((distance == BIG_RADIUS) || (distance == SMALL_RADIUS)){
        cout << "Undefined";
    } else if (((distance < BIG_RADIUS) && (distance > SMALL_RADIUS)) ||
            ((x < TOP_RIGHT_X) && (x > BOTTOM_LEFT_X) && (y < TOP_RIGHT_Y) && (y > BOTTOM_LEFT_Y))){
        cout << "Black";
    } else if ((x == TOP_RIGHT_X) && ((y <= TOP_RIGHT_Y) || (y >= BOTTOM_LEFT_Y))){
        cout << "Undefined";
    } else if ((x == BOTTOM_LEFT_X) && ((y <= TOP_RIGHT_Y) || (y >= BOTTOM_LEFT_Y))){
        cout << "Undefined";
    } else if ((y == TOP_RIGHT_Y) && ((x <= TOP_RIGHT_X) || (x >= BOTTOM_LEFT_X))){
        cout << "Undefined";
    } else if ((y == BOTTOM_LEFT_Y) && ((x <= TOP_RIGHT_X) || (x >= BOTTOM_LEFT_X))){
        cout << "Undefined";
    } else if ((distance<SMALL_RADIUS) &&
               (((x > TOP_RIGHT_X) || (y > TOP_RIGHT_Y)) || ((x < BOTTOM_LEFT_X) || (y < BOTTOM_LEFT_Y)))){
        cout << "White";
    }
}

