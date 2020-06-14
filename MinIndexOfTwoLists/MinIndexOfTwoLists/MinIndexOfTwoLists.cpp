// MinIndexOfTwoLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2);

int main()
{
    vector<string> s1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
    vector<string> s2 = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };

    vector<string> common;
    common = findRestaurant(s1, s2);
    for (string s : common) {
        cout << s << endl;
    }
}

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    // map with string as key and index as value for longer list
    // check with second list until first match found
    // Brute force is O(n^2) search both lists until find first common string
    int l1 = list1.size();
    int l2 = list2.size();
    vector<string> common;
    int minSum = INT_MAX;
    int sum = 0;
    map<string, int> m1;
    map<string, int>::iterator it;
    for (int i = 0; i < list1.size(); i++) {
        m1[list1[i]] = i;
    }
 
    for (int i = 0; i < list2.size(); i++) {
        it = m1.find(list2[i]);
        if (it != m1.end()) {
            sum = i + m1[list2[i]];
            if (sum < minSum) {
                common.clear();
                common.push_back(list2[i]);
                minSum = sum;
            }
            else if (sum == minSum)
                common.push_back(list2[i]);
        }
    }
    // Find common between them
    return common;
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
