// ToeplitzMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
}

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    // Toeplitz if diagonals are the same
    // Run two loops R,C and check values
    // 0,0 start 1,1 2,2 etc  i =0; i < M ; i++ ; j =0; j < N ; j++

    int R = matrix.size();      // Rows
    int C = matrix[0].size();    // Columns  for a square or rectangular matrix

    // Check Rows and Columns
    for (int i = 0; i < C; i++) {     // columns check from row 0
        if (!CheckDiag(matrix, 0, i))
            return false;
    }

    for (int j = 1; j < R; j++) {
        if (!CheckDiag(matrix, j, 0))   // Start at column 0
            return false;
    }

    // Must be toeplitz
    return true;
}

bool CheckDiag(vector<vector<int>>& matrix, int r, int c) {
    int res = matrix[r][c];
    int R = matrix.size();      // Rows
    int C = matrix[0].size();    // Columns  for a square or rectangular matrix

    while (++r < R && ++c < C) {
        if (res != matrix[r][c])
            return false;
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
