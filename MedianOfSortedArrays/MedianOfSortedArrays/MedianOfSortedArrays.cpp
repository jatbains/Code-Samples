// MedianOfSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main()
{
    vector<int> nums1 = { 1,2 };
    vector<int> nums2 = { 3,4 };

    cout << "Median is " << findMedianSortedArrays(nums1, nums2);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    vector<int> merged;

    // Merge into single vector
    vector<int>::iterator n1 = nums1.begin();
    vector<int>::iterator n2 = nums2.begin();

    while (n1 != nums1.end() && n2 != nums2.end()) {
        if (*n1 < *n2) {
            merged.push_back(*n1);
            n1++;
        }
        else {
            merged.push_back(*n2);
            n2++;
        }
    }
    while (n1 != nums1.end()) {
        merged.push_back(*n1);
        n1++;
    }
    while (n2 != nums2.end()) {
        merged.push_back(*n2);
        n2++;
    }

    for (int i : merged) {
        cout << " " << i << endl;
    }

    double value = 0.0;
    int num = merged.size();
    if (num % 2 == 0) {
        int med1, med2;
        med1 = num / 2 - 1;
        med2 = num / 2;
        value = ((double)merged[med1] + (double)merged[med2]) / 2;

    }
    else {
        int med = floor(num / 2);
        value = (double)merged[med];
    }

    return value;
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
