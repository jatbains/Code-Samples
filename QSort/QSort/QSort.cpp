// QSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void qSort(vector<int>& nums, int low, int high);
int Partition(vector<int>& nums, int low, int high);

int main()
{
    vector<int>  nums = { 5, 3, 1, 2, 7, 4 };
    qSort(nums, 0, nums.size() - 1);

    for (int i : nums)
        cout << " " << i;
}
// Quicksort
void qSort(vector<int>& nums, int low, int high) {

    if (low > high)
        return;

    // Get pivot 
    int pivot = Partition(nums, low, high);

    // qsort left
    if (low < pivot-1 )
        qSort(nums, low, pivot-1);
    // qsort right
    if (pivot < high)
        qSort(nums, pivot, high);

}

int Partition(vector<int>& nums, int low, int high) {

    int pivot = nums[low + (high - low) / 2];

    while (low <= high) {
        while (nums[low] < pivot)
            low++;
        while (nums[high] > pivot)
            high--;

        if (low <= high) {
            int temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            low++;
            high--;
        }
    }
    return low;
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
