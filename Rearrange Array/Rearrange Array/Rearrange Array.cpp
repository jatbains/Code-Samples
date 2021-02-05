// Rearrange Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void reArranged(int data[], int d,int n);

int main()
{
    int n = 3;
    int num[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
    cout << sizeof(num) / sizeof(int) << endl;
    int d = sizeof(num) / sizeof(int);
    reArranged(num, d, n);
}

void reArranged(int data[], int d, int n) {
    
    int *reDat = new int[d];
    int pass = 0;

    int count = d;
    int j = 0;
    int i = 0;
    while (count > 0) {

        for (int i = pass; i < d; i += n, j++) {
            reDat[j] = data[i];
            // decrement for each copied letter
            count--;
        }
        pass++;
    }
    cout << endl;
    for (int i = 0; i < d; i++) {
        cout << reDat[i] << " ";
    }
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
