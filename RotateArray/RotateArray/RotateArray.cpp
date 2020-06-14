// RotateArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void Rotate(vector<int>& nums, int k);
void rotate(vector<int>& nums, int k);
void Reverse(vector<int>& num, int start, int end);

int main()
{
    vector<int> list = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 3;

    // Call Rotate

    Rotate(list, k);

    for (int i : list)
    {
        cout << i << " " ;
    }
    cout << endl;
    cout << "Rotate again " << endl;
    rotate(list, list.size()-k);

    for (int i : list) {
        cout << " " << i << "";
    }
    cout << endl;
    //std::cout << "Hello World!\n";
}

void Rotate(vector<int>& nums, int k) {
    // Solve it with two pointers into the arrray and a temporary variable
    int val = 0;
    int rem = k;
    queue<int> rot;
    int len = nums.size();
    int* l, * r;
    l = r = &nums[0];
    // Rotate k to right  move r to right k digits
    if (k == 0 || k == len)
        return;
  
    rem = len;
    // Move right to end
 
    // Do the rotation
    // Push all digits upto 0 to len - k into  queue
    for (int i = k+1 ; i < len ; i++)
    {
        rot.push(nums[i]);
    }
    // Move the array that many spaces
    // COpy to a second array?

    // Copy down 
    for (int i = len-1; i >= k; i--)
    {
        nums[i] = nums[i - k];
    }
 
   
    // Copy back from queue
    int j = 0;
    while (!rot.empty())
    {
        val = rot.front();
        nums[j] = val;
        j++;
        rot.pop();
    }

}

void rotate(vector<int>& nums, int k) {
    // Approach use a stack for elements falling off end of array
      // Rotate to the right  len is total length then arr[i] = arr[i+k] while K >0 k--
    int len = nums.size();
    if (len == 0 || len == 1)
        return;

    k %= len;


    // Reverse whole vector
    Reverse(nums, 0, len - 1);
    // Reverse first k
    Reverse(nums, 0, k - 1);

    // Reverse last len - k
    Reverse(nums, k, len - 1);


}

void Reverse(vector<int>& num, int start, int end) {
    int temp = 0;

    while (start < end) {
        temp = num[start];
        num[start] = num[end];
        num[end] = temp;

        start++;
        end--;
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
