// RemoveElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val);

int main()
{
    vector<int> nums = { 3, 2, 2, 3 };
    int target = 3;


    cout << removeElement(nums, target);
   // std::cout << "Hello World!\n";
}

int removeElement(vector<int>& nums, int val) {

    // Remove all instances of val and return the new length
    // also resize the vector to new length
    // Use two indices slow and fast move fast past val
    int count = 0;
    int i = 0, j = 0;

    while (j < nums.size()) {

        if (nums[j] == val) {
            j++;
            cout << count << " ";
            continue;
        }
        nums[i] = nums[j];
        // increment
        count++;
        i++;
        j++;
    }
    // resize
    nums.resize(count);

    return count;
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
