// LongestPalindromeSub.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool isSubPalin(string s, int l, int r);
int longestPalin(string s);
int max_val(int x, int y);
int lps(string seq, int i, int j);
int lps_dyn(string str);

int main()
{
    string word = "bbbab";

    cout << "Longest palindrome is " << longestPalin(word) << endl;

    cout << "Longest palindromic subsequence is " << lps(word, 0, word.length() - 1) << endl;

    cout << "Longest palindromic dynamic is " << lps_dyn(word) << endl;
}

int longestPalin(string s) {
    int len = s.length();
    int max = 0;
    int start = 0;
    int low = 0, high = 0;
    
    for (int i = 1; i < len; i++) {
        // Check substrings

        // Check even
        low = i - 1;
        high = i;
        
        while (low >= 0 && high < len && s[low] == s[high]) {
            if (high - low + 1 > max) {
                start = low;
                max = high - low + 1;
            }
            --low;
            ++high;
        }

        // CHeck odd
        low = i - 1;
        high = i + 1;

        while (low >+ 0 && high < len && s[low]==s[high]) {
            if (high - low + 1 > max) {
                start = low;
                max = high - low + 1;
            }
            --low;
            ++high;

        }
    }
    return max;

}

bool isSubPalin(string s, int l, int r) {
   
    while (l < r ) {

        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int max_val(int x, int y) {
    return (x > y ? x : y);
}
// Returns the length of the longest palindromic subsequence in seq 
int lps(string seq, int i, int j)
{
    // Base Case 1: If there is only 1 character 
    if (i == j)
        return 1;

    // Base Case 2: If there are only 2  
    // characters and both are same 
    if (seq[i] == seq[j] && i + 1 == j)
        return 2;

    // If the first and last characters match 
    if (seq[i] == seq[j])
        return lps(seq, i + 1, j - 1) + 2;

    // If the first and last characters do not match 
    return max_val(lps(seq, i, j - 1), lps(seq, i + 1, j));
}

int lps_dyn(string str)
{
    int n = str.length();
    int i, j, cl;
     
    int** L = new int* [n];
    for (int i = 0; i < n; ++i) {
        L[i] = new int[n];
    }
    //new int[n][n];  // Create a table to store results of subproblems 


    // Strings of length 1 are palindrome of lentgh 1 
    for (i = 0; i < n; i++)
        L[i][i] = 1;

    // Build the table. Note that the lower diagonal values of table are 
    // useless and not filled in the process. The values are filled in a 
    // manner similar to Matrix Chain Multiplication DP solution (See 
    // https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of 
    // substring 
    for (cl = 2; cl <= n; cl++)
    {
        for (i = 0; i < n - cl + 1; i++)
        {
            j = i + cl - 1;
            if (str[i] == str[j] && cl == 2)
                L[i][j] = 2;
            else if (str[i] == str[j])
                L[i][j] = L[i + 1][j - 1] + 2;
            else
                L[i][j] = max_val(L[i][j - 1], L[i + 1][j]);
        }
    }

    return L[0][n - 1];
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
