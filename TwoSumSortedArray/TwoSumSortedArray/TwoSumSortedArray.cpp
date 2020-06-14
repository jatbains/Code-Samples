// TwoSumSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> twoSum(vector<int>& numbers, int target);

int main()
{
    vector<int> numbers = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> indexes;
    indexes = twoSum(numbers, target);

    for (int i : indexes) {
        cout << " Index " << i;
    }
}

vector<int> twoSum(vector<int>& numbers, int target) {

    map<int, int> sums;
    int* vals = new int[numbers.size()];
    vector<int> pair;
    // first value is number
    // second is the index
    // Sum - target = number
  
    map<int, int>::iterator it;
    for (int i = 0; i < numbers.size(); i++) {
        it = sums.find(target - numbers[i]);
        if (it != sums.end()) {
            pair.push_back(it->second);
            pair.push_back(i+1);
            break;
        }
        else {
            sums[numbers[i]] = i+1;
        }
    }
    return pair;
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
