// FindLargestIslandInMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::vector;
using std::queue;
int GetLargestIsland(vector<vector<int>>& grid);
void BFS_search(vector<vector<int>>& grid, vector<vector<bool>>& visited,int si, int sj, int& max);
bool isSafe(vector<vector<int>>& grid, int i, int j,
    vector<vector<bool>>& vis);
void DFS(vector<vector<int>>& grid, int row, int col,
    vector<vector<int>>& visited, int& max);
using namespace std;

int main()
{
    vector<vector<int>> matrix = { { 1, 1, 0, 0, 0 },
                                   { 0, 1, 0, 0, 1 },
                                   { 1, 0, 0, 1, 1 },
                                   { 0, 0, 0, 0, 0 },
                                   { 1, 0, 1, 0, 1 } };

    vector<vector<string>> grid = {{"1", "1", "1", "1", "0"} ,
        {"1", "1", "0", "1", "0"},
        {"1", "1", "0", "0", "0"},
        {"0", "0", "0", "0", "0"}};

    int maxI = GetLargestIsland(matrix);

    // cout << "BFS Max is " << maxI << endl;
   
}

void DFS(vector<vector<int>>& grid, int row, int col,
         vector<vector<bool>>& visited, int& max)
{
    // These arrays are used to get 
    // row and column numbers of 8 
    // neighbours of a given cell 
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    // Mark this cell as visited 
    visited[row][col] = true;
    max++;

    // Recur for all connected neighbours 
    for (int k = 0; k < 8; ++k)
        if (isSafe(grid, row + rowNbr[k], col + colNbr[k], visited))
            DFS(grid, row + rowNbr[k], col + colNbr[k], visited, max);
}


void BFS_search(vector<vector<int>>& grid, vector<vector<bool>>& visited,int si, int sj,int& max) {
    int cur = 0;  // current max

    // arrays to find neighbors

    int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    queue<pair<int, int>> islq;

    islq.push(make_pair(si, sj));
    visited[si][sj] = true;
    max++;
    // Next step of BFS. We take out 
    // items one by one from queue and 
    // enqueue their univisited adjacent 
    while (!islq.empty()) {

        int i = islq.front().first;
        int j = islq.front().second;
        islq.pop();

        // Go through all 8 adjacent 
        for (int k = 0; k < 8; k++) {
            if (isSafe(grid, i + row[k], j + col[k], visited)) 
            {
                max++;
                visited[i + row[k]][j + col[k]] = true;
                islq.push(make_pair(i + row[k], j + col[k]));
            }
        }
    }

}
bool isSafe(vector<vector<int>>& grid, int row, int col,
    vector<vector<bool>>& vis)
{
    int R = grid.size();
    int C = grid[0].size();
    return (row >= 0) && (row < R) && (col >= 0) && (col < C) &&
        (grid[row][col] && !vis[row][col]);
}


int GetLargestIsland(vector<vector<int>>& grid)
{
    // Create a isVisited grid
    int Rows = grid.size();
    int Cols = grid[0].size();
    
    vector<vector<bool>> bvisited(Rows,vector<bool>(Cols,false));  // initialize to false

    int bmax = 0;
    int bcur = 0;
    int dcur = 0;
    int dmax = 0;
    int islands = 0;

    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            // Call BFS search
            if (grid[i][j] && !bvisited[i][j]) {
                BFS_search(grid, bvisited, i, j, bcur);
                if (bcur > bmax) {
                    bmax = bcur;
                }
                bcur = 0;
            }
        }
    }
    vector<vector<bool>> dvisited(Rows, vector<bool>(Cols, false));  // initialize to false
 
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
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

    cout << "DFS max is " << dmax << endl;
    cout << "BFS max is " << bmax << endl;
    cout << "Number of islands " << islands << endl;
    return bmax;
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
