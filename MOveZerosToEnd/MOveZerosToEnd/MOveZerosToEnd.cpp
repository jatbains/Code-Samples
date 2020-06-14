// MOveZerosToEnd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums);

int main()
{
    vector<int> input = { 0, 1, 0, 3, 12 };
        
    moveZeroes(input);

    for (int num : input)
    {
        cout << " " << num;
    }
    cout << endl;
    //std::cout << "Hello World!\n";
}


void moveZeroes(vector<int>& nums) {
    int zeros = 0;
    int* slow = NULL, * fast = NULL;

    slow = fast = &nums[0];   // beginning
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (*fast == 0 )
        {
            zeros++;
            fast++;
            continue;
        }
        *slow = *fast;
        slow++;
        fast++;
      
    }
    // Put zeros at end
    while (zeros > 0)
    {
        *slow = 0;
        slow++;
        zeros--;
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
