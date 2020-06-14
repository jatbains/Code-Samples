// GroupAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Process the vector of strings and look for strings with the same character set
    //  How to make it efficient?
    // Charmap for each string?  O(n) only one pass
    // Add up the characters to give a number and length is the same
    vector<vector<string>> groups;

    map<string, vector<string>> agMap;
    vector<string> group;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        // Add into map
        agMap[key].push_back(s);
    }

    for (auto x : agMap) {
        group.clear();
        for (auto i = 0; i < x.second.size(); i++) {
            cout << i << " " << endl;
            group.push_back(x.second[i]);
        }
            
        groups.push_back(group);
    }


    return groups;
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
