// SortedRanges.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums);

int main()
{
    vector<int> nums = { 0, 2, 3, 4, 6, 8, 9 };

    vector<string> res = summaryRanges(nums);

    for (string i : res) {
        cout << i << endl;
    }
}

vector<string> summaryRanges(vector<int>& nums) {
    // Look for consecutive numbers and create a string

    vector<string> res;
    if (nums.size() == 0)
        return res;
    string range;
    int prev = 0;
    int start = 0;
    vector<int>::iterator it = nums.begin();

    // Note if *it == *it+1 then range increments
    // If *it != *it +1 then range terminates
    // If *it == *it then it terminates
    range = to_string(*it);
    prev = *it;
    start = prev;
    it++;
    while (it != nums.end()) {

        if (prev + 1 == *it) {
            prev = *it;
            it++;
            continue;
        }
 
        if (prev + 1 != *it) {
            if (start == prev) {
                res.push_back(range);
            }
            else {
                range += "->" + to_string(prev);
                res.push_back(range);
            }
            start = *it;
            prev = *it;
            range = to_string(*it);
            it++;
            continue;
        }
    }
    // Catch end
    if (start == prev) {
        res.push_back(range);
    }
    else {
        range += "->" + to_string(prev);
        res.push_back(range);
    }
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
