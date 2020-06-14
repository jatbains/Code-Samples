// MaxINcreaseSkyline.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

    int R = grid.size();
    int C = grid[0].size();
    vector<int> rowMaxes(R);
    vector<int> colMaxes(C);

    int N = R;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            rowMaxes[r] = max(rowMaxes[r], grid[r][c]);
            colMaxes[c] = max(colMaxes[c], grid[r][c]);
        }
    }

    int ans = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            ans += min(rowMaxes[r], colMaxes[c]) - grid[r][c];
        }
    }

    return ans;
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
