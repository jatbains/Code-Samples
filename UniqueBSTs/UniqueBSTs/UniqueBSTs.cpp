// UniqueBSTs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
unsigned long int countBST(unsigned int n);
unsigned long int catalan(unsigned int n, vector<unsigned long int>& memo);

int main()
{
    int num = 0;
    cout << "Enter a number" << endl;
    cin >> num;
    cout << "Number of BST " << countBST(num) << endl;
}
// Recursively find BST's values 1...n 
// Brute force find all trees and check for BST n! (not good)
// BST - root >left && root < right  
//  N = 1  -> 1 , N = 2  -> 2 , N = 3 -> 5 , 2 ^ N-1 , N = 4 , 2 ^ 3 + 
// Use Catalan numbers
unsigned long int catalan(unsigned int n, vector<unsigned long int>& memo) {
    if (n <= 1)
        return 1;
    unsigned long int res = 0;
    for (int i = 0; i < n; ++i) {
        unsigned long int cat1 = 0;
        if (memo[i] > 0) {
            cat1 = memo[i];
        }
        else {
            cat1 = catalan(i, memo);
            memo[i] = cat1;
        }
        unsigned long int cat2 = 0;
        if (memo[n - i - 1] > 0) {
            cat2 = memo[n - i - 1];
        } else{
            cat2 = catalan(n - i - 1, memo);
            memo[n - i - 1] = cat2;
        }
        res += cat1 * cat2;
    }
    return res;
}
unsigned long int countBST(unsigned int n) {
    //unsigned long int* memo = new unsigned long int[n];
    vector<unsigned long int> memo(n, 0);
    unsigned long int count = catalan(n,memo);
    //delete []memo;
    return count;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

