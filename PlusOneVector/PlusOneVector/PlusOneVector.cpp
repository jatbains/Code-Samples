// PlusOneVector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits);

int main()
{
    vector<int> digits = { 1,2,3 };
    
    for (int i : plusOne(digits))
    {
        cout << i << " ";
    }
    
    cout << endl;
    //std::cout << "Hello World!\n";
}

vector<int> plusOne(vector<int>& digits) {
    // Get length add one to end and check for carry
    // The vector may need to be resized of a new one created
    int len = digits.size();
    int dig = 0;
    int len2 = 0;
    // Count backwards
    int num = 0;
    int val = 0;
    int mult = 1;
    // Add up all the numbers
    for (int i = len-1; i >=0; i--)
    {
        val = mult *digits[i];
        mult *= 10;
        num += val;
        
    }
    // Add one
    num += 1;
    int i = 0;
  
    // Convert to a vector divide by 10 repeatedly until zero
    val = num;
    mult = 1;
    while (val > 0)
    {
        val /= 10;
        len2++;     // Number of digits
        mult *= 10;
    }
    // resize
    digits.resize(len2);
    // multiplier
 
    i = len2 - 1;
    while (num > 0)
    {
        dig = num % 10;
        num /= 10;
        digits[i] = dig;
        
        i--;
    }

    return digits;
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
