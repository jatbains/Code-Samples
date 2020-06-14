// TopKFrequent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct compare
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        // if frequencies of two elements are same 
        // then the larger number should come first 
        if (p1.second == p2.second)
            return p1.first < p2.first;

        // insert elements in the priority queue on the basis of 
        // decreasing order of frequencies     
        return p1.second < p2.second;
    }
};
int main()
{
    vector<int> nums = { 4, 1, -1, 2, -1, 2, 3 };
     
    int k = 2;
    unordered_map<int, int> kFreq;  // key is num and val is frequency
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        kFreq[nums[i]]++;
    }

    // Put elements into a priority queue Max Heap
    vector<pair<int, int>> freq_arr(kFreq.begin(), kFreq.end());
    // Sort vector with respect to frequency?
    priority_queue < pair<int, int>, vector<pair<int, int>>, compare> pq(kFreq.begin(), kFreq.end());

    for (int i = 0; i < k; i++) {
        result.push_back(pq.top().first);
        pq.pop();
    }

    for (int i : result) {
        cout << i << " ";
    }
   // std::cout << "Hello World!\n";
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
