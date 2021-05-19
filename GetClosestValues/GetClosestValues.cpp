// GetClosestValues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> GetClosest(vector<int> arr, int tar, int n);

int SearchVect(vector<int> arr, int tar, int l, int r, int pre, int ind);

int main()
{
    vector<int> Array = { 0, 1, 100, 101, 102 };
    vector<int> Array2 = { 1,2,3,4,5 };
    int target = 3;
    int n = 3;
    vector<int> res = GetClosest(Array2, target, n);

    vector<int>::iterator it = res.begin();
    while (it != res.end()) {
        cout << *it << " ";
        it++;
    }
}

// Find the closes Values and generate a return vector
vector<int> GetClosest(vector<int> arr, int tar, int n) {

    int ind = SearchVect(arr, tar, 0, arr.size() - 1, 0, 0);
    cout << " Returned Index " << ind << endl;
    // Use this index to create a new vector
    vector<int> result;
    if (tar == arr[ind]) {
        // target in array
        // No need to adjust 
    }
    int leftVal = 0;
    int rightVal = 0;
    // Adjust left and right indexes
    if (ind > 0) {
        leftVal = arr[ind - 1];
    }
    if (ind < arr.size() - 1) {
        rightVal = arr[ind + 1];
    }

    // Create a new vector with n values that are close to target 
    int leftDiff = tar - leftVal;
    int rightDiff = rightVal - tar;
    // leftDiff == rightDif  // Evenly fill new vector
    // Fill from left or right of target

    if (leftDiff == rightDiff) {
        int stInd = ind - n / 2;
        int num = n;
        while (num > 0) {
            result.push_back(arr[stInd]);
            stInd++;
            num--;
        }
    }
    else if (leftDiff < rightDiff) {
        // left 
        int stInd = ind - n;
        int num = n;
        while (num > 0) {
            result.push_back(arr[stInd]);
            stInd++;
            num--;
        }
    }
    else {
        int stInd = ind;
        int num = n;
        while (num > 0) {
            result.push_back(arr[stInd]);
            stInd++;
            num--;
        }
    }


    return result;
}



// Find the closest index to the target
int SearchVect(vector<int> arr, int tar, int l, int r, int pre, int ind) {
    if (l > r)
        return ind; // Done search return  index

    int mid = (l + r) / 2;
    int diff = abs(tar - arr[mid]);  // THis is the difference between target and mid point value
    // cout << " New Diff " << diff << endl;
    if (diff <= pre) {
        ind = (l + r) / 2;
        // cout << " Index is " << ind << endl;
    }
    if (tar < arr[mid]) {
        return SearchVect(arr, tar, l, mid - 1, diff, ind);
    }
    else {
        return SearchVect(arr, tar, mid + 1, r, diff, ind);
    }

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
