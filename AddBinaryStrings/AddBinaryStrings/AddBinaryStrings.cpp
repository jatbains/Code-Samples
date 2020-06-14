// AddBinaryStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string addBinary(string a, string b);

int main()
{
    string  a = "11", b = "11";

    cout << addBinary(a, b) << endl;
   // std::cout << "Hello World!\n";
}

string addBinary(string a, string b) {
    int l1 = a.length();
    int l2 = b.length();
    string sum = "";
    bool carry = false;
    int i = 0;
    while (l1 != 0 && l2 != 0) {

        if (a[l1-1] == '1' && b[l2-1] == '1') {
            if (carry) {
                sum += "1";
                carry = true;
            }
            else {
                sum += "0";
                carry = true;
            }
            l1--;
            l2--;
            continue;
        }
        if ((a[l1-1] == '0' && b[l2-1] == '1') || (a[l1-1] == '1' && b[l2-1] == '0')) {
            if (carry) {
                sum += "0";
                carry = true;
            }
            else {
                sum += "1";
                carry = false;
            }
            l1--;
            l2--;
            continue;
        }
        else {
            // both zero
            if (carry) {
                sum += "1";
                carry = false;
            }
            else {
                sum += "0";
                carry = false;
            }
            l1--;
            l2--;
            continue;
        }
        i++;

    }
    if (l1 != 0) {  // add l1
        while (l1 != 0) {
            if (carry)
                if (a[l1-1] == '1') {
                    sum += "0";
                    carry = true;
                }
                else {
                    sum += "1";
                    carry = false;
                }
            l1--;
            i++;
        }

    }
 
    if (l2 != 0) {  // add l1
        while (l2 != 0) {
            if (carry)
                if (b[l2-1] == '1') {
                    sum += "0";
                    carry = true;
                }
                else {
                    sum += "1";
                    carry = false;
                }
            l2--;
            i++;
        }

    }

    if (carry) {
        sum += "1";
        carry = false;
    }

    return sum;
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
