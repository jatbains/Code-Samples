// DayOfTheWeek.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
string dayOfTheWeek(int day, int month, int year);
string dayzOfTheWeek(int day, int month, int year);

int main()
{
   
     cout << dayzOfTheWeek(29, 2, 2016) << endl;
}


string dayOfTheWeek(int day, int month, int year) {
    // Zeller's Rule
    // F=k+ [(13*m-1)/5] +D+ [D/4] +[C/4]-2*C
    string Day;
    int k = day;
    int D = year % 100;
    int C = year / 100;
    int m = 0;
    int F = 0;
    // month Mrach is first if month is 8 m = 8-2 = 6
    // if month is = 12 m = 12 -2 = 10
    // if month is 1 m = 11, month is 2 m = 12
    if (month <= 2)
        m = month + 10;
    else
        m = month - 2;

    F = k + ((13 * m - 1) / 5) + D + (D / 4) + (C / 4) - 2 * C;
    F = F % 7;  // day
    if (F < 0) {
        F += 7;
    }
    switch (F) {
    case (0):
        Day = "Sunday";
        break;
    case (1):
        Day = "Monday";
        break;
    case (2):
        Day = "Tuesday";
        break;
    case (3):
        Day = "Wednesday";
        break;
    case (4):
        Day = "Thursday";
        break;
    case (5):
        Day = "Friday";
        break;
    case (6):
        Day = "Saturday";
        break;
    default:
        Day = "Unknown";
    }
    return Day;
}

string dayzOfTheWeek(int day, int month, int year) {
    // Zeller's Rule
    // F=k+ [(13*m-1)/5] +D+ [D/4] +[C/4]-2*C

    string Day;

    // month Mrach is first if month is 8 m = 8-2 = 6
    // if month is = 12 m = 12 -2 = 10
    // if month is 1 m = 11, month is 2 m = 12
    int y = year;
    int d = day;
    int m = month;
    static int t[] = { 0, 3, 2, 5, 0, 3,
                     5, 1, 4, 6, 2, 4 };
    y -= m < 3;

    int F = (y + y / 4 - y / 100 +
        y / 400 + t[m - 1] + d) % 7;


    switch (F) {
    case (0):
        Day = "Sunday";
        break;
    case (1):
        Day = "Monday";
        break;
    case (2):
        Day = "Tuesday";
        break;
    case (3):
        Day = "Wednesday";
        break;
    case (4):
        Day = "Thursday";
        break;
    case (5):
        Day = "Friday";
        break;
    case (6):
        Day = "Saturday";
        break;
    default:
        Day = "Unknown";
    }
    return Day;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
