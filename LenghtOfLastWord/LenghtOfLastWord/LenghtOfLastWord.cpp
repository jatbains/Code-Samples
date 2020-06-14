// LenghtOfLastWord.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

int lengthOfLastWord(string s) {
    int count = 0;
    int word = 0;
    bool wordFound = false;
    if (s.length() == 0)
        return 0;
    int index = 0;


    // Just count isalpha from end until you see space
    for (int i = s.length() - 1; i >= 0; i--) {

        if (s[i] == ' ') {
            if (!wordFound)
                continue;
            else
                break;
        }
        // Done counting
        if (isalpha(s[i])) {
            count++;
            wordFound = true;
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
