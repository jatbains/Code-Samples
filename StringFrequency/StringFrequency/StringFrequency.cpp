// StringFrequency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string frequencySort(string s);
typedef pair<int, int> alph;

int main()
{
    string s = "tree";
    cout << frequencySort(s) << endl;
}

string frequencySort(string s) {
    // create a map of chars and frequescy
    // ingest all chars
    // sort map based on frequency
    // Output to a string
    string out;
    
    map<int, int> mfreq;
    for (int i = 0; i < s.length(); i++) {
        
        mfreq[s[i] - 'a']++;
    }
    // Copy to vector
    vector<alph> freq;
    // copy(mfreq.begin(), mfreq.end(), back_inserter<vector<alph>>(freq));
    for (auto it = mfreq.begin(); it != mfreq.end(); ++it) {
        freq.push_back(*it);
    }
 
    sort(freq.begin(), freq.end(), [](const alph& a, const alph& b)
        {
            if (a.second != b.second)
                return a.second > b.second;
            return a.first > b.first;
        });
    for (alph v : freq) {
        // get number
        int n = v.second;
        while (n > 0) {
            out += v.first + 'a';
            n--;
        }
        
    }
    return out;
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
