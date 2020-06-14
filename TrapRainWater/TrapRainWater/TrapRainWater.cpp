// TrapRainWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}
int trap(vector<int>& height) {
    int result = 0;
    int left = 0, right = height.size() - 1;
    int left_max = 0, right_max = 0;

    while (left < right) {

        if (height[left] < height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            }
            else {
                result += left_max - height[left];
            }
            ++left;

        }
        else {
            if (height[right] >= right_max) {
                right_max = height[right];
            }
            else {
                result += right_max - height[right];
            }
            --right;

        }
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
