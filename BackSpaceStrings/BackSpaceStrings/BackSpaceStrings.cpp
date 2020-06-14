// BackSpaceStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <stack>
#include <deque>

using namespace std;

bool backspaceCompare(string S, string T);
bool backSpaceStrings(string S, string T);
bool backSpaceComparison(string S, string T);
string newString(string S);
bool backSpaceStringComp(string S, string T);

int main()
{
    // string S = "ab##", T = "c#d#";
    string S = "bbbextm";
    string T = "bbb#extm";

   // cout << backspaceCompare(S, T);
   // cout << backSpaceStrings(S, T);
    // cout << backSpaceComparison(S, T);
    cout << backSpaceStringComp(S, T);
    // std::cout << "Hello World!\n";
}
// Add check for underflow
bool backSpaceStringComp(string S, string T) {

    string s1 = newString(S);
    string s2 = newString(T);

    if (s1.length() != s2.length())
        return false;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}
bool backSpaceComparison(string S, string T) {
    int i = S.length() - 1, j = T.length() - 1;
    int skipS = 0, skipT = 0;

    while (i >= 0 && j >= 0) {
        while (i >= 0) {
            if (S[i] == '#') 
            { skipS++; i--; }
            else if (skipS > 0) 
            { skipS--; i--; }
            else break;
        }
        while (j >= 0) {
            if (T[j] == '#')
            { skipT++; j--; }
            else if (skipT > 0) 
            { skipT--; j--; }
            else break;
        }
        // Compare 
        if (i >= 0 && j >= 0 && (S[i] != T[j]))
            return false;
        if ((i >= 0) != (j >= 0))
            return false;
        i--;
        j--;
    }
    // last check
    if (i != j)
        return false;
    return true;
}

string newString(string S)
{
    deque<char> q;

    for (int i = 0; i < S.length(); ++i) {

        if (S[i] != '#')
            q.push_back(S[i]);
        else if (!q.empty())
            q.pop_back();
    }

    // build final string 
    string ans = "";

    while (!q.empty()) {
        ans += q.front();
        q.pop_front();
    }

    // return final string 
    return ans;
}

bool backSpaceStrings(string S, string T) {
    string r1, r2;
    int count = 0;
    for (int i = S.length() - 1; i >= 0; i--) {
        if (S[i] == '#') {
            count++;     // Number of backspaces
            continue;
        }
        // Check skip
        while (count > 0) {
            i--;
 
            count--;
        }
        if (i < 0)
            break;
        if (isalpha(S[i])) {
            r1 += S[i];
        }
    }
    count = 0;
    for (int i = T.length() - 1; i >= 0; i--) {
        if (T[i] == '#') {
            count++;     // Number of backspaces
            continue;
        }
        // Check skip
        while (count > 0) {
            i--;
            count--;
        }
        if (i < 0)
            break;
        if (isalpha(T[i])) {
            r2 += T[i];
        }
    }
    // compare r1 and r2
    //cout << "r1 " << r1 << endl;
    //cout << "r2 " << r2 << endl;
    if (r1.length() == 0 && r2.length() == 0)
        return true;
    if (r1.length() != r2.length())
        return false;
    for (int i = 0; i < r1.length(); i++) {
        if (r1[i] != r2[i])
            return false;
    }

    return true;
}

bool backspaceCompare(string S, string T) {
    // Put both into a stack
    // while popping off throw away backspace chars
    // put the remaining chars in two new arrays 
    // compare the two arrays
    stack<char> s1, s2;
    string r1, r2;
    for (int i = 0; i < S.length(); i++) {
        s1.push(S[i]);
    }
    for (int i = 0; i < T.length(); i++) {
        s2.push(T[i]);
    }
    // why not process backwards skipping over number of backspaces
    while (!s1.empty()) {
        char c = s1.top();
        if (c != '#') {
            r1 += s1.top();
            s1.pop(); 
        }
        else {
            int count = 0;
            while (c == '#') {
                count++;
                s1.pop();
                c = s1.top();
            }
            while (count > 0) {
                s1.pop();
                count--;
            }
        }
    }
    cout << r1 << " " << endl;
    // Repeat for string 2 
    while (!s2.empty()) {
        char c = s2.top();
        if (c != '#') {
            r2 += s2.top();
            s2.pop();
        }
        else {
            int count = 0;
            while (c == '#') {
                count++;
                s2.pop();
                c = s2.top();
            }
            while (count > 0) {
 
                s2.pop();
                count--;
            }
        }
    }
    cout << r2 << " " << endl;

    // compare strings
    if (r1.length() != r2.length())
        return false;
    for (int i = 0; i < r1.length(); i++) {
        if (r1[i] != r2[i])
            return false;
    }

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
