// NumberLines.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> numberOfLines(vector<int>& widths, string S);

int main()
{
    vector<int> widths = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
        10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
        string S = "bbbcccdddaaa";
        vector<int> res = numberOfLines(widths, S);

        for (int i : res)
            cout << " " << i;
}

vector<int> numberOfLines(vector<int>& widths, string S) {
    vector<int> res;
    int totCount = 0;
    int lines = 0;
   
    // Process string from left to right and add to the total count
    for (int i = 0; i < S.length(); i++) {
        int w = widths[S[i] - 'a'];
        totCount += w;  // 
        if (totCount > 100) {
            lines++;
            totCount = w;
        }
    }


    res.push_back(lines + 1);
    res.push_back(totCount);

    return res;
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
