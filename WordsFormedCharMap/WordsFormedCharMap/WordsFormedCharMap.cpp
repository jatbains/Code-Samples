// WordsFormedCharMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

static const int ASC = 26;
using namespace std;
int countCharacters(vector<string>& words, string chars);
void CopyFreqMap(int* src, int*& dest);

int main()
{
    vector<string> words = { "cat", "bt", "hat", "tree" };

    string chars = "atach";
    
    cout << countCharacters(words, chars) << endl;
    //std::cout << "Hello World!\n";
}

int countCharacters(vector<string>& words, string chars) {
    // Find the number of words that are found and then count the 
    // length of these strings and return them
    // Use a trie or hash 
    int num = words.size();
    int N = chars.length();
    int total = 0;
    int curr = 0;
    // Create a CharD=FreqSet adn search the words
    int* charSet = new int[ASC]();

    for (int i = 0; i < N; i++)
    {
        charSet[chars[i] - 'a']++;
    }
    // Go through each words and see if they have enough chars
   // Create a copy and then process each string
    for (string s : words) {
        int len = s.length();
        int* map = nullptr;
        curr = 0;
        
        CopyFreqMap(charSet, map);
        for (int i = 0; i < len; i++) {
            if (map[s[i] - 'a'] > 0) {
                map[s[i] - 'a']--;
                curr++;
            }

        }
        delete map;
        if (curr == s.length())
           total += curr;

    }

    return total;
}

void CopyFreqMap(int* src, int*& dest)
{
    dest = new int[ASC];
    for (int j = 0; j < ASC; j++)
    {
        dest[j] = src[j];
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
