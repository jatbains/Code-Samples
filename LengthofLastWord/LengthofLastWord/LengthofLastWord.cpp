// LengthofLastWord.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s);

int main()
{
    string s = "Hello World ";

    cout << lengthOfLastWord(s);
   // std::cout << "Hello World!\n";
}

int lengthOfLastWord(string s) {
    int count = 0;
    int word = 0;
    bool isSpace = false;
    if (s.length() == 0)
        return 0;
    int index = 0;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == ' ') {
            // Get count of last word
           // count = wordCount(s, index, i); // i - index
            count = i - index;
            isSpace = true;
            index = i;
        }

    }
    // Count length from index +1 to end
    if (!isSpace) {
        count = s.length();
    }
    else {
        if (index+1 != s.length()) {
            count = 0;
            for (int i = index + 1; i < s.length(); i++)
                count++;
        }
    }

    return count;
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
