// PallindromicSubstrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
int countSubstrings(string s);
void findAllPalins(string s, string sub, int& count, int len,int index);
bool isPalin(string s);

int main()
{
    string s = "aaa";

    cout << countSubstrings(s);
    //std::cout << "Hello World!\n";
}

int countSubstrings(string s) {
    // Recursive backtrakking solution

    // go through string create substrings and chec to see if they are palindromes
    // If palindromes then increment counter
    int count = 0;
    for (int i = 1; i <= s.length(); i++) {
        findAllPalins(s, "", count, i,0);
   }

    return count;

}

void findAllPalins(string s, string sub, int& count, int len,int index) {

    if (sub.length() == len) {
        // test for palin
        if (isPalin(sub)) {
            cout << sub << " ";
            count++;
        }
        return;
    }
    for (int i = index; i < s.length(); i++) {
        char c = s[i];
        s.erase(s.begin() + i);
        findAllPalins(s, sub + c, count, len,i);
        s.insert(s.begin() + i, c);
    }

}
bool isPalin(string s) {
    int i = 0;
    int j = s.length() - 1;

    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
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
