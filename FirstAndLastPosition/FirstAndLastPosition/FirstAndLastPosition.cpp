// FirstAndLastPosition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> out;

    int len = nums.size();
    // RecurSearch(nums, target, 0, nums.size(), out);

    out.push_back(first(nums, 0, len - 1, target, len));
    out.push_back(last(nums, 0, len - 1, target, len));

    return out;
}

int first(vector<int> arr, int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
}


/* if x is present in arr[] then returns the index of
   LAST occurrence of x in arr[0..n-1], otherwise
   returns -1 */
int last(vector<int> arr, int low, int high, int x, int n)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid - 1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
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
