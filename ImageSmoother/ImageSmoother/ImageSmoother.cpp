// ImageSmoother.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
bool isValid(int row, int col, int R, int C, vector<vector<bool>>& isVisited);
void DFSSearch(vector<vector<int>>& grid, int ri, int cj, int R, int C, vector<vector<bool>>& isVisited, int& count, int& val);
void SmoothImage(vector<vector<int>>& grid);

int main()
{
    vector<vector<int>> grid = { {1,1,1},
                                 {1,0,1},
                                 {1,1,1} };

    SmoothImage(grid);
}

void SmoothImage(vector<vector<int>>& grid) {

    int R = grid.size();
    int C = grid[0].size();
    vector<vector<bool>> isVisited(R, vector<bool>(C, false));
    int count = 0, val = 0;
    // Check the matrx
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            val = 0;
            count = 0;
            if (!isVisited[i][j]) {
                DFSSearch(grid, i, j, R, C, isVisited, count, val);
                cout << " Val " << val << " Count " << count << endl;
                if (count != 0)
                    grid[i][j] = val / count;
            }
            // Apply value
 
        }
    }
    

}

void DFSSearch(vector<vector<int>>& grid,int ri, int cj, int R, int C,vector<vector<bool>>& isVisited, int& count, int& val) {

    static vector<int> Ri = { -1,-1,-1,0,0,1,1,1 };
    static vector<int> Cj = { -1,0,1,-1,1,-1,0,1 }; 

    // Recursively find valid elements
    isVisited[ri][cj] = true;
    count++;
    val += grid[ri][cj];
 
    for (int i = 0; i < 8; ++i) {
        if (isValid(ri + Ri[i], cj + Cj[i], R, C, isVisited)) {
            DFSSearch(grid, ri + Ri[i], cj + Cj[i], R, C, isVisited, count, val);
        }
    }
}


bool isValid(int row, int col,int R,int C,vector<vector<bool>>& isVisited) {

    return (row >= 0 && row < R&& col >= 0 && col < C && (!isVisited[row][col]));
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
