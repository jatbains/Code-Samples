// FindDisappearedNum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> *findDisappearedNumbers(vector<int>& nums);

int main()
{
    vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
    vector<int>* missing;

    missing = findDisappearedNumbers(nums);

    for (int i : *missing)
    {
        cout << " " << i;
    }
    cout << endl;
   // std::cout << "Hello World!\n";
}
vector<int> *findDisappearedNumbers(vector<int>& nums) 
{
    int size = nums.size();
    int* freq = new int[size + 1];
    int max = 0;
    // Count frequency of digits
    memset(freq, 0, size+1);
    for (int i = 0; i <= size; i++)
        freq[i] = 0;

    for (int i = 0; i < size; ++i)
    {
        freq[nums[i]]++;   // Frequency of digits
       
    }
    // Missing will be between 1 to n
    vector<int>* result = new vector<int>();
    // check 0

    for (int i = 1; i <= size; i++)
    {
        if (freq[i] == 0)
            result->push_back(i);
    }

    return result;
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
