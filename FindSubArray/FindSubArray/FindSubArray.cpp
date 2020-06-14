// FindSubArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findSubarray(vector<int>& list, int target);

int main()
{
    vector<int> arr = { 10, 2, -2, 20, 10 };
    int target = 18;

    findSubarray(arr, target);

    std::cout << "Hello World!\n";
}

// Find if subarray exists
void findSubarray(vector<int>& list, int target) {

    int curr_sum = 0;
    unordered_map<int, int> nums;
    // Process the vector
    for (int i = 0; i < list.size(); i++) {
        curr_sum += list[i];

        // Check if equal to target
        if (curr_sum == target) {
            // Found subarray
            cout << "Subarray between " << 0 << " " << i << endl;
            break;
        }

        // Check if num is in map
        if (nums.find(curr_sum - target) != nums.end()) {
            // found it between  
            cout << "Subarray between " << nums[curr_sum - target] + 1 << " " << i << endl;
        }
        nums[curr_sum] = i;
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
