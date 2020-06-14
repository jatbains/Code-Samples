// MergeIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals);

int main()
{
    vector<vector<int>> intervals = { {1, 3},{2, 6},{8, 10},{5,11}, {15, 18} };

    intervals = merge(intervals);

    
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // sort the intervals first


    sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
        return v1[0] < v2[0] ? 1 : 0;
        });

    vector<vector<int>>::iterator it = intervals.begin();
    stack <vector<int>> intStack;
    // Push vector onto stack then go through all intervals and merge when required.
    // Pop after and pushback
    intStack.push(intervals.front());
    it++;
    while (it != intervals.end()) {
        vector<int> top = intStack.top();
        if (top.back() >= it->front()) {
            cout << " back " << it->back() << " Front " << top.front() << endl;
            top.back() = max(it->back(), top.back());
            intStack.pop();
            intStack.push(*it);
        }
        else {
            intStack.push(*it);
        }
        it++;

    }
        
    vector<vector<int>> result;
    while (!intStack.empty()) {
        result.push_back(intStack.top());
        intStack.pop();
    }

    for (vector<int> v : result) {
        // Merge intervals
        for (int i : v) {
            cout << " " << i;
        }
       
    }
    return result;
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
