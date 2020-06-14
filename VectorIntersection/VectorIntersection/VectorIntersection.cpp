// VectorIntersection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2);

int main()
{
    vector<int> nums1 = { 4, 9, 5 };
    vector<int> nums2 = { 9, 4, 9, 8, 4 };

    vector<int> common;

    common = intersect(nums1, nums2);

    for (int i : common) {
        cout << " " << i;
   }
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    // Find all common elements
    // find size of 1st and second 
    // Use map with <val,freq>  for both then find min of freq.
    // 
    map<int, int> freq1;
    map<int, int> freq2;
    vector<int> common;
    int l1 = nums1.size();
    int l2 = nums2.size();

    for (int i = 0; i < l1; i++) {
        freq1[nums1[i]]++;
    }
    for (int i = 0; i < l2; i++) {
        freq2[nums2[i]]++;
    }
    map<int, int>::iterator it;
    if (l1 > l2) {
        it = freq2.begin();
        while (it != freq2.end()) {
            if (freq1[(*it).first]) {
                int count = min((*it).second, freq1[(*it).first]);
 
                while (count > 0) {
                    common.push_back((*it).first);
                    count--;
                }
            }
            it++;
        }
    }
    else {
        it = freq1.begin();
        while (it != freq1.end()) {
            if (freq2[(*it).first]) {
                int count = min((*it).second, freq2[(*it).first]);

                while (count > 0) {
                    common.push_back((*it).first);
                    count--;
                }
            }
            it++;
        }
    }
    return common;
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
