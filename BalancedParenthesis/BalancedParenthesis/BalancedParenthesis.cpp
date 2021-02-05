// BalancedParenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

bool isBalanced(string s);

int main()
{
    string bracs = "(((())))()(())";
    cout << (isBalanced(bracs) ? "Balanced" : "Unbalanced");
}

bool isBalanced(string s) {
    int len = s.length();
    stack<char> pairs;
    // Push ( onto stack and pop ) off stack
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            pairs.push(s[i]);
        }
        if (s[i] == ')') {
            if (pairs.empty()) {
                // unbalanced
                return false;
            }
            if (pairs.top() != '(') {
                return false;
            }
            // pop off the top
            pairs.pop();

        }

    }
    if (!pairs.empty())
        return false;
    return true;
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
