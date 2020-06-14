// MajorityElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
int majorityElement(vector<int>& nums);
int mapMajorityElement(vector<int>& nums);

int main()
{
    vector<int> list = { 3,2,3 };
    
    // cout << "Majority is " << majorityElement(list) << endl;
    
    cout << "Majority is " << mapMajorityElement(list) << endl;
    
   // std::cout << "Hello World!\n";
}

int mapMajorityElement(vector<int>& nums)
{
    map<int, int> freq;
    int len = nums.size();


    for (int i = 0; i < len; i++)
    {
        freq[nums[i]] += 1;
    }

    for (auto x : freq)
    {
        cout << x.first << " " << x.second << endl;
        if (x.second > len / 2)
            return x.first;
    }
    return 0;
}

// Modify to use a map
int majorityElement(vector<int>& nums) {
    int len = nums.size();
    int max = INT_MIN;
    for (int i = 0; i < len - 1; i++)
    {
        if (max < nums[i])
            max = nums[i];
    }
    int* freq = new int[max+1]();
    for (int i = 0; i < max - 1; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < len ; i++)
    {
        freq[nums[i]]++;
        cout << "Num is " << nums[i] <<  " Freq is " << freq[nums[i]] << endl;
        if (freq[nums[i]] > len / 2)
            return nums[i];
    }
    return 0;
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
