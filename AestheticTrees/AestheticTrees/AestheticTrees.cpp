// AestheticTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


using namespace std;
void makeAesthetic(vector<int>list, int d, vector<int>& tree, int& index);
bool checkAesth(vector<int> list);


int main()
{
    std::cout << "Hello World!\n";
    vector<int> trees = { 3,4,5,3,7 };
    int d = trees.size();
    vector<int> list;
    int index = 0;
    makeAesthetic(trees, d, list, index);

    vector<int>::iterator it = list.begin();
    while (it != list.end()) {
        cout << "Tree " << *it << endl;
        it++;
    }
}

// Remove one tree to make it aesthetic
// Increase/decrese precession
void makeAesthetic(vector<int>list,int d, vector<int>& tree, int& index)
{
    // Base
    if (list.size() == d - 1) {
        // Check aesthetic if true push back i
        if (checkAesth(list)) {
            tree.push_back(index);
        }
        return;
    }
    // remove a tree and check
    for (int i = index; i < d; i++) {
        int val = list[i];

        list.erase(list.begin() + i);
        makeAesthetic(list, d, tree, i);
        list.insert(list.begin() + i, val);

    }
    return;
}
bool checkAesth(vector<int> list)
{
    vector<int>::iterator it = list.begin();
    bool even = true;
    int prev = *it;
    it++;

    if (prev > *it) {
        while (it < list.end()) {
            if (even) {
                if (prev < *it)
                    return false;
                even = false;
            }
            else {
                if (prev > *it)
                    return false;
                even = true;
            }
            prev = *it;
            it++;
        }
    }
    else {
        while (it < list.end()) {
            if (even) {
                if (prev > *it)
                    return false;
                even = false;
            }
            else {
                if (prev < *it)
                    return false;
                even = true;
            }
            prev = *it;
            it++;
        }
    }

    return true;

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
