// SplitStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int findCount(string s);

int main()
{
	string s = "RLLLLRRRLR";
	cout << findCount(s) << endl;
}

int findCount(string s) {
	int x = 0;
	int y = 0;
	int count = 0;
	int i = 0;
	int len = s.size();
	while (i < len) {
		if (s[i] == 'L')
			x++;
		if (s[i] == 'R')
			y++;
		if (x == y) {
			x = 0;
			y = 0;
			count++;
		}
		i++;
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
