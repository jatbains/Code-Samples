// LuckyNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> luckyNumbers(vector<vector<int>>& matrix);

int main()
{
    vector<vector<int>> matrix = { {1, 10, 4, 2},{9, 3, 8, 7},{15, 16, 17, 12} };

    vector<int> vals;

    vals = luckyNumbers(matrix);

    for (int i : vals)
        cout << " Num " << i;
}

vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int rowMin = INT_MAX;
    int colMax = INT_MIN;
 
    set<int> ans;
    set<int>::iterator it;
    int R = matrix.size();  // Rows
    int C = matrix[0].size();  // colums
    vector<int> res;

    for (int i = 0; i < R; i++) {
        rowMin = matrix[i][0];
 
        // Find min of each row and also max of each column
        for (int j = 0; j < C; j++) {
            if (matrix[i][j] < rowMin)
                rowMin = matrix[i][j];
        }
        ans.insert(rowMin);
    }
    
    for (int j = 0; j < C; j++) {
        colMax = matrix[0][j];
        for (int i = 0; i < R; i++) {
            if (matrix[i][j] > colMax)
                colMax = matrix[i][j];
        }
        it = ans.find(colMax);
        if (it != ans.end())
            res.push_back(*it);
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
