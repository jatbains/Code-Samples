// GetSumNoOps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int getSum(int a, int b);
using namespace std;
int AddNum(int x, int y);
int SubNum(int x, int y);

int main()
{
    cout << getSum(-1, 1) << endl;
}
int getSum(int a, int b) {

    long int x = a;
    long int y = b;
    long int res;
    bool xNeg = false;
    bool yNeg = false;
    // If a number is negative then take it not
    if ((a == INT_MAX && b == INT_MIN) || (a == INT_MIN && b == INT_MAX))
        return -1;

    if (x < 0)
        xNeg = true;
    if (y < 0)
        yNeg = true;

    if (!xNeg && !yNeg)
        res = AddNum(x, y);
    if (xNeg && !yNeg) {
        x *= -1;
        res = SubNum(y, x);
    }
    if (!xNeg && yNeg) {
        y *= -1;
        res = SubNum(x, y);
    }
    if (xNeg && yNeg) {
        x *= -1;
        y *= -1;
        res = AddNum(x, y);
        res *= -1;
    }

    return res;
}
int AddNum(long int x, long int y) {

    while (y != 0) {
        long int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}
int SubNum(long int x, long int y) {

    while (y != 0) {
        long int borrow = (~x) & y;
        x = x ^ y;

        y = borrow << 1;
    }
    return x;
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
