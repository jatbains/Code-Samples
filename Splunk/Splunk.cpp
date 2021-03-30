// Splunk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Merge {
private:
    vector<int> V1;
    vector<int> V2;
public:
    Merge(vector<int> v1, vector<int> v2);
    vector<int> Merged();
};

Merge::Merge(vector<int> v1, vector<int> v2) {
    V1 = v1;
    V2 = v2;
}

vector<int> Merge::Merged() {
    int i=0, j=0, k = 0;
    vector<int> res;
    int l1 = V1.size();
    int l2 = V2.size();
    res.resize(l1 + l2);
    // Check if either are empty
    if (l1 == 0)
        return V2;
    if (l2 == 0)
        return V1;

    // Merge into single array
    while (i != l1 && j != l2) {
        if (V1[i] < V2[j]) {
            res[k] = V1[i];
            k++;
            i++;
        }
        else {
            res[k] = V2[j];
            j++;
            k++;
        }
    }

    while (i != l1) {
        res[k] = V1[i];
        i++;
        k++;
    }
    while (j != l2) {
        res[k] = V2[j];
        k++;
        j++;
    }
    return res;
}
int main()
{
    vector<int> num1 = { 1,3,6,9,10 };
    vector<int> num2 = { 2,4,5,8,11,13,16 };
    vector<int> merged;

    Merge m1(num1, num2);

    merged = m1.Merged();
    for(int i : merged) {
        cout << i << " ";
    }
    cout << endl;
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
