// RunLengthEncoding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int compress(vector<char>& chars);

int main()
{
    vector<char> chars = { 'c','o','o' };
    //{ 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
   
    cout << "Length is " << compress(chars) << endl;
    
    for (char c : chars)
    {
        cout << c << " ";
    }
    //std::cout << "Hello World!\n";
}

int compress(vector<char>& chars) {
    int len = chars.size();

    // sanitize intput
    if (len == 1)
        return 1;


    // go through the list and count duplicates and keep a index
    // increment this index when not equal chars are found
    // if a single char is found then you must insert a space for 1

    int j = 0;   // New length of vector
    int count = 0;  // start at 1
    int i = 0;


    for (i = 0; i < len; i++)
    {
        count = 1;
        while (i < len - 1 && chars[i] == chars[i + 1])
        {
            count++;
            i++;
        }
        // check for resizing
 
        chars[j++] = chars[i];
        if (count > 9)
        {
            int num = count;

            stack<char> digs;
            while (num > 0)
            {
                digs.push((num % 10) + '0');
                num /= 10;
            }
            while (!digs.empty())
            {
                chars[j++] = digs.top();
                digs.pop();
            }
        }
        
        else if (count >1) {
            chars[j++] = count + '0'; // Need to handle >10 
        }
    }

    return j;
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
