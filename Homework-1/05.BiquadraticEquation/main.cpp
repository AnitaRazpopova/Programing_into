/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Anita Razpopova
* @idnumber 62495
* @task 5
* @compiler GCC
*
*/

#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

int main()
{
    double a, b, c;
    double x1, x2, x3, x4;
    double y1, y2;
    double discriminant;

    cout << "Input a ";
    cin >> a;
    //Checking the data input for a.
    while(cin.fail() || (a == 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input a\n" << endl;
        cin >> a;
    }

    cout << "Input b ";
    cin >> b;
    //Checking the data input for b.
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input b\n" << endl;
        cin >> b;
    }

    cout << "Input c ";
    cin >> c;
    //Checking the data input for c.
    while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input c\n" << endl;
        cin >> c;
    }

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0){
        y1 = ((-1 * b) + sqrt(discriminant)) / (2 * a);
        y2 = ((-1 * b) - sqrt(discriminant)) / (2 * a);
        cout << "y1 and y2 are real and different. \n";
        cout << "y1= " << y1 << "\n";
        cout << "y2= " << y2 << "\n";
    } else if (discriminant == 0){
        y1 = y2 = -1 * (b / (2 * a));
        cout << "y1 = y2 and are the same. \n";
        cout << "y1=y2= " << y1 << "\n";
    } else if (discriminant < 0){
        cout << "y1 and y2 are not real and there are no real roots";
        return 0;
    }

    if ((y1 < 0) && (y2 < 0)){
        cout << "There are no real roots.";
    } else if ((y1 >= 0) && (y2 >= 0)) {
        x1 = sqrt(y1);
        x2 = -1 * sqrt(y1);
        cout << "x1= " << x1 << "\n";
        cout << "x2= " << x2 << "\n";
        x3 = sqrt(y2);
        x4 = -1 * sqrt(y2);
        cout << "x3= " << x3 << "\n";
        cout << "x4= " << x4 << "\n";
    } else if ((y1 < 0) && (y2 >= 0)) {
        x1 = sqrt(y2);
        x2 = -1 * sqrt(y2);
        cout << "x1= " << x1 << "\n";
        cout << "x2= " << x2 << "\n";
    } else if ((y1 >= 0) && (y2 < 0)) {
        x1 = sqrt(y1);
        x2 = -1 * sqrt(y1);
        cout << "x1= " << x1 << "\n";
        cout << "x2= " << x2 << "\n";
    }

    return 0;
}
