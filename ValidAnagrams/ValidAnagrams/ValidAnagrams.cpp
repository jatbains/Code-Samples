// ValidAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t);

int main()
{
    string s1 = "a";
    string s2 = "b";

    cout << "Anagram " << (isAnagram(s1, s2) ? "Yes" : "No") << endl;
    
    
    //std::cout << "Hello World!\n";
}

bool isAnagram(string s, string t) {

    char s1[256] = { 0 };
    char t1[256] = { 0 };


    if (s.length() != t.length())
        return false;

    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        s1[s[i]]++;
        t1[t[i]]++;

    }

    // Compare the two
    for (int i = 0; i < 256; i++)
    {
        if (s1[i] != t1[i])
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
