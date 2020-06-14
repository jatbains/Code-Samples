// MaxLengthConCat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
void CharMap(vector<string> arr);
bool Unique(string s);
int MaxLen(vector<string> arr);
void FindMaxStr(vector<string> arr, string maxStr, int index, int& maxLen);
void FindMaxLen(vector<string> arr, string maxStr, int index,int count, int& maxLen);

int main()
{
    vector<string> arr = { "cha", "r", "act", "ers" };
    vector<string> vec2 = { "un", "iq", "ue" };
    vector<string> alph = { "abcdefghijklmnopqrstuvwxyz" };

    int unique = 0;
    // increment the frequency for all chars
    unique = MaxLen(alph);

    cout << unique;
}

int MaxLen(vector<string> arr) {
    // Create all the combinations add it to a string and see if there are duplicates chars
    // reject if duplicates
    string maxStr = "";
    int index = 0;
    int maxLen = 0;
    // Call a recursive function
   // FindMaxStr(arr, maxStr, 0, maxLen);
    // Special case

    for (int i = 0; i < arr.size(); i++) {
        FindMaxLen(arr, arr[i], 0, i, maxLen);
    }
    return maxLen;
}

void FindMaxLen(vector<string> arr, string maxStr, int index,int count, int& maxLen) {

    if (count == index) {
        
        if (Unique(maxStr)) {
            int len = maxStr.length();
            if (len > maxLen)
                maxLen = len;
            return;
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        string s = arr[i];
        arr.erase(arr.begin() + i);
        FindMaxLen(arr, maxStr + s, i + 1, count, maxLen);
        arr.insert(arr.begin() + i, s);
    }

}

void FindMaxStr(vector<string> arr, string maxStr, int index, int& maxLen) {

    if (index == arr.size() && Unique(maxStr)) {
        // Check maxStr
        int len = maxStr.length();
        if (len > maxLen)
            maxLen = len;
        return;
    }
    if (index == arr.size())
        return;

    // Recur
    // Unchoose
    FindMaxStr(arr, maxStr, index + 1, maxLen);
    FindMaxStr(arr, maxStr + arr[index], index + 1, maxLen);
  
}

bool Unique(string s) {
    char map[26] = { 0 };
    for (int i = 0; i < s.length(); i++) {
        if (map[s[i]-'a'])
            return false;
        map[s[i]-'a']++;
    }
    return true;
}

void CharMap(vector<string> arr) {
    int i = 0;
    int j = 0;
    vector<vector<int>> chars(arr.size(), vector<int>(26));
    while (i < arr.size()) {
        for (string s : arr) {
            chars[i][s[j] - 'a']++;
            j++;
        }
        i++;
        j = 0;
    }
    // Created a distribution for the chars
    // Find the longest combination
    i = 0;
    int maxsofar = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i; j < arr.size(); j++) {
            // Compare arr[i] and arr[j]
            maxsofar = arr[i].size() + arr[j].size();
            // Duplicates??

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
