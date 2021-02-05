// CubeTraverseWays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void maxTraverse(int d, int x, int y);
void validPath(int d, int x, int y, int& path);

int main()
{
    int dim[] = { 2, 3 };
    int paths[] = { 2, 6 };
    
    maxTraverse(2, 0, 0);
    maxTraverse(3, 0, 0);
    maxTraverse(4, 0, 0);
}

void maxTraverse(int d, int x, int y)
{
    // Based on d sum up all valid traversals from top left to bottom right
    // Start at 0, end at d-1,1-d
    int path = 0;
    validPath(d, 0, 0, path);
    cout << path << endl;

    return;
}

// Recursively Find a valid path
void validPath(int d, int x, int y, int &path)
{
    // Base condition
    if (x == d - 1 && y == 1 - d)
    {
        path++;
        return;
    }
    // Go right and down
    if (x + 1 <= d - 1) {
        validPath(d, x + 1, y, path);
    }
    if (y - 1 >= 1 - d) {
        validPath(d, x, y - 1, path);
    }
    // return path if done
    return;
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
