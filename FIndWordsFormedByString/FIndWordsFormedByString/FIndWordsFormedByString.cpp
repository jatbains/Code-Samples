// FIndWordsFormedByString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int countCharacters(vector<string>& words, string chars);
void countCharsHelper(vector<string>& words, string chars, string perm, unordered_set<string>& permSet, int& count, int word_len);

int main()
{
    vector<string> words = {"hello", "world", "leetcode"};
       
    string chars = "welldonehoneyr";
 

    cout << endl;
    cout << "Count of matches is " << countCharacters(words, chars) << endl;
}


int countCharacters(vector<string>& words, string chars) 
{
    int count = 0;
    int word_len = 0;
    string perm = "";
    unordered_set<string> permSet;
    // The approach is to create all different combinations of characters in the
    //  string and compare them against the vector and increment count when a valid
    //  word is found

    for (word_len = 1; word_len <= chars.length(); word_len++)
    {
        cout << " Word Length " << word_len << endl;
        countCharsHelper(words, chars, perm, permSet, count, word_len);
    }
   
    return count;
}

void countCharsHelper(vector<string>& words, string chars, string perm, unordered_set<string>& permSet, int& count, int word_len)
{
    if (perm.length() == word_len) {
        // all combos tried check and return
        // The string perm should be unique
        if (permSet.find(perm) == permSet.end())
        {
            // Insert into set
            permSet.insert(perm);
            for (string s : words) {
                if (s.compare(perm) == 0) {
                    cout << "Matched " << perm << endl;
                    count += perm.length();
                }
            }
        }
 
        return;
    }

    for (int i = 0; i < chars.length(); i++)
    {
        // Choose  try and un choose
        char c = chars[i];
        chars.erase(chars.begin() + i);
        countCharsHelper(words, chars, perm + c, permSet, count, word_len);
        chars.insert(chars.begin() + i, c);
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
