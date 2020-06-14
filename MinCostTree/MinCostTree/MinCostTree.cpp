// MinCostTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int MinCostTree(vector<int> arr, int n);
int mctFromLeafValues(vector<int>& arr);

int main()
{
   
    vector<int> arr = { 6, 2, 4 };

    cout << MinCostTree(arr, arr.size() - 1) << endl;
    cout <<  mctFromLeafValues(arr) << endl;
}

int MinCostTree(vector<int> arr, int n)
{
    int ans = 0;

    // Stack 
    vector<int> st = { INT_MAX };

    // Loop to traverse the array elements 
    for (int i = 0; i < n; i++) {

        // Keep array elements  
        // in decreasing order by poping out 
        // the elements from stack till the top 
        // element is less than current element 
        while (st.back() <= arr[i]) {

            // Get top element 
            int x = st.back();

            // Remove it 
            st.pop_back();

            // Get the minimum cost to remove x 
            ans += x * min(st.back(), arr[i]);
        }

        // Push current element 
        st.push_back(arr[i]);
    }

    // Find cost for all remaining elements 
    for (int i = 2; i < st.size(); i++)
        ans += st[i] * st[i - 1];

    return ans;
}

int mctFromLeafValues(vector<int>& arr) {
    stack<int> st;
    st.push(INT_MAX);

    int res = 0;

    for (int i : arr) {
        while (st.top() <= i) {
            int temp = st.top();
            st.pop();
            res = res + (temp * min(st.top(), i));
        }
        st.push(i);
    }

    while (st.size() > 2) {
        int temp = st.top();
        st.pop();
        res = res + (temp * st.top());
    }
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
