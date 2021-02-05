// RemoveAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <set>
#include <vector>
#include <algorithm>


using namespace std;

vector<string> removeAnags(vector<string> list);

int main()
{
	vector<string> list = { "hello", "ball", "beat", "olleh", "llab" ,"cart","trac"};

	vector<string> out;

	out = removeAnags(list);
	vector<string>::iterator it;
	it = out.begin();
	while (it != out.end()) {
		cout << *it << endl;
		it++;
	}
}

vector<string> removeAnags(vector<string> list) {
	set<string> found;
	vector<string> res;
	int len = list.size();
	string word;

	for (int i = 0; i < len; i++) {
		word = list[i];
		// sort chars
		sort(word.begin(), word.end());
		// Check if in map
		if (found.find(word) == found.end()) {
			// Not in map
			res.push_back(list[i]);
			found.insert(word);
		}
	}
	sort(begin(res), end(res));

	return res;
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
