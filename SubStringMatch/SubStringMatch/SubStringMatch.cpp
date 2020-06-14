// SubStringMatch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
int isSubstring(string s2, string s1);

int main()
{
    std::cout << "Hello World!\n";
}

int strStr(string haystack, string needle) {


    // Look for substring in string
    return isSubstring(haystack, needle);
}

// Sliding window algorithm
int isSubstring(string s2, string s1)
{
    int M = s1.length(); // needle
    int N = s2.length();  // haystack

     /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}
int search(string haystack, string needle) {
    int index = -1;
    bool isFound = false;
    char* p = &haystack[0];
    int i = 0, j = 0;
    char* q = &needle[0];
    if (needle.length() == 0)
        return 0;
    if (haystack.length() == 0 && needle.length() == 0)
        return 0;

    while (i < haystack.length() && !isFound)
    {
        if ((haystack[i] == needle[j])) {
            index = i;
            while ((haystack[i] == needle[j]) && (i < haystack.length()))
            {
                if (j == needle.length() - 1) {
                    isFound = true;
                    break;
                }

                i++;
                j++;
            }

        }

        // increment i reset j
        i++;
        j = 0;
    }
    return index;
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
