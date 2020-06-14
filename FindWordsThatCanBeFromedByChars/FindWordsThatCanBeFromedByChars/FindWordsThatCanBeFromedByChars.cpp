// FindWordsThatCanBeFromedByChars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;
int countCharacters(vector<string>& words, string chars);
void createWords(map<string,bool>& words, string& chars, string cand, int len, int& number);

int main()
{
    vector<string> words = { "cat", "bt", "hat", "tree" } ;
    string chars = "cath";

    cout << "Number of words " << countCharacters(words,chars);
}

int countCharacters(vector<string>& words, string chars) {
    // Algorithm - create all possible combinations of characters
    // Compare with words in the vector.
    // Copy words from the vector to a hashtable of strings and then do a lookup
  
    map<string, bool> mapList;
    int len = chars.size();
    int number = 0;
    vector<string>::iterator it = words.begin();
    map<string, bool>::iterator mt;
    while (it != words.end())
    {    
        mapList[*it] = false;
        
        it++;
    }


    // Pass this to the backtracking function
    for (int i = 1; i <= len; i++)
    {
        // Try strings of different lengths
        createWords(mapList, chars, "", i, number);
    }

    return number;

}
// Backtrack function create combinations 
void createWords(map<string,bool>& list, string& chars, string cand, int len, int& number)
{
    if (cand.length() == len)
    {
        // check if it is in the set
        map<string, bool>::iterator it;
        // cout << "Word is " << cand << endl;
        it = list.find(cand);
        if (it != list.end())
        {
           // cout << "Word is " << cand << endl;
            number++;
            list[cand] = true;
        }

    }
    // else 
    else
    {
        // Choose try and unchoose
        for (int i = 0; i < len; i++)
        {
            char c = chars[i];
            chars.erase(chars.begin() + i);
            createWords(list , chars, cand + c, len, number);
            chars.insert(chars.begin() + i, c);
        }

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
