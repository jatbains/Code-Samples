// LongestPrefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

string longestCommonPrefix(vector<string>& strs) {
    string prefix;

    if (strs.size() == 0)
        return prefix;
    // Loop through all the strings and add all characters that are the same to output string
    int minLen = minLength(strs);
    char current;

    for (int i = 0; i < minLen; i++) {

        current = strs[0][i];   // ith character of first string

        for (string s : strs) {
            if (s[i] != current)
                return prefix;

        }
        prefix.push_back(current);

    }
    return prefix;
}

int minLength(vector<string>& strs) {
    int min = INT_MAX;
    for (string s : strs)
    {
        if (min > s.length()) {
            min = s.length();
        }
    }
    return min;
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
