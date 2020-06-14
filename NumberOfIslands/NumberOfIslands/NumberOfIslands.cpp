// NumberOfIslands.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& grid, int row, int col,
    vector<vector<bool>>& vis);
int numIslands(vector<vector<int>>& grid);
void DFS(vector<vector<int>>& grid, int row, int col,
    vector<vector<bool>>& visited, int& max);
vector<vector<int>> numIslands(vector<vector<string>>& grid);

int main()
{
    vector<vector<string>> grid = { {"1","1","0","0","0"},
        {"1","1","0","0","0"},
        {"0","0","1","0","0"},
        {"0","0","0","1","1"} };
    vector<vector<int>> matrix;
    matrix = numIslands(grid);
    for (vector<int> i : matrix) {
        for (int j : i) {
            cout << " " << j;
        }
        cout << endl;
    }

    int islands = numIslands(matrix);

    cout << "Islands " << islands << endl;
}

vector<vector<int>> numIslands(vector<vector<string>>& grid) {
    int R = grid.size();
    int C = grid[0].size();
    vector<vector<int>> matrix(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == "1") {
                matrix[i][j] = 1;
            }
            else {
                matrix[i][j] = 0;
            }

        }
    }
    return matrix;
}
int numIslands(vector<vector<int>>& grid) {
    // Using DFS

    int dcur = 0;
    int dmax = 0;
    int islands = 0;
    int Rows = grid.size();
    int Cols = grid[0].size();

    vector<vector<bool>> dvisited(Rows, vector<bool>(Cols, false));  // initialize to false
    for (vector<bool> b : dvisited) {
        for (bool l : b) {
            cout << " " << l;
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < Rows; ++i) {
        for (int j = 0; j < Cols; ++j) {
            // Call DFS search
            if (grid[i][j] && !dvisited[i][j]) {
                DFS(grid, i, j, dvisited, dcur);
                if (dcur > dmax) {
                    dmax = dcur;
                }
                dcur = 0;
                ++islands;
            }
        }
    }
    cout << " D max " << dmax << endl;
    return islands;
}



void DFS(vector<vector<int>>& grid, int row, int col,
    vector<vector<bool>>& visited, int& max)
{
    // These arrays are used to get 
    // row and column numbers of 8 
    // neighbours of a given cell 
    // static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    // static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
    static int rowNbr[] = { -1,0,0,1 };
    static int colNbr[] = { 0,-1,1,0 };
    // Mark this cell as visited 
    visited[row][col] = true;
    max++;

    // Recur for all connected neighbours 
    for (int k = 0; k < 4; ++k)
        if (isSafe(grid, row + rowNbr[k], col + colNbr[k], visited))
            DFS(grid, row + rowNbr[k], col + colNbr[k], visited, max);
}

bool isSafe(vector<vector<int>>& grid, int row, int col,
    vector<vector<bool>>& vis)
{
    int R = grid.size();
    int C = grid[0].size();
    return (row >= 0) && (row < R) && (col >= 0) && (col < C) &&
        (grid[row][col] && !vis[row][col]);
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
