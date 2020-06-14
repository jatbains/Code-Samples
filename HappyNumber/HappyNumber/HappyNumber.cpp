// HappyNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int n);
int SumofSquares(int n);

int main()
{
    int happNum = 0;
    cout << "Enter a number " << endl;
    cin >> happNum;

    cout << "Number is " << (isHappy(happNum) ? "Happy" : "Not Happy") << endl;
   
    //std::cout << "Hello World!\n";
}


bool isHappy(int n) {
    // Divide a number by 10 repeatedly and use modulus as number
    unordered_set<int> numSet; // list of numbers
    int sum = n;
    // Infinite loop to be broken out of
    while (1) {
        // find the sum
        sum = SumofSquares(sum);

        // check if sum is 1
        if (sum == 1) {
            cout << "Found Happy Number" << endl;
            return true;
        }
        // Add to l
        // Check if already in list
        // If found break return false;
        if (numSet.find(sum) == numSet.end())
        {
            numSet.insert(sum);
        }
        else
        {
            // found
            return false;
        }

        // Insert in set

    }


}
// Function that breaks up number and sums up digits and checks if sum is 1

int SumofSquares(int n) {
    int dig = 0;
    int sum = 0;
    while (n > 0) {
        dig = n % 10;
        n /= 10;
        sum += dig * dig;
    }
    return sum;
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
