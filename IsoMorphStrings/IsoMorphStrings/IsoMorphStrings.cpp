// IsoMorphStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isIsomorphic(string s, string t);

int main()
{
    string s1 = "egg";
    string s2 = "boo";
    
    cout << "The strings are " << (isIsomorphic(s1, s2) ? "Isomorphic " : "Not Isomorphic") << endl;
    //std::cout << "Hello World!\n";
}

bool isIsomorphic(string s, string t) 
{
    // Create a map for two strings and then compare them
    // The same letter can only be mapped to a single chracter
    unordered_map<char, char> isoMap;
    unordered_map<char, char>::iterator it;
    unordered_set<char> charSet;
    if (s.length() != t.length())
        return false;

    for (int i = 0; i < s.size(); ++i)
    {
        if (isoMap.find(s[i]) == isoMap.end())    // Not found
        {
            if (charSet.count(t[i]))
            { // no two characters may map to the same character.  Already in set
                return false;
            }
            isoMap[s[i]] = t[i];     // Insert into map
            charSet.insert(t[i]);     // Update set
        }

        if (isoMap[s[i]] != t[i])   // Compare values for key and string 2
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
