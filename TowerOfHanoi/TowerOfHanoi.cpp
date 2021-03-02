// TowerOfHanoi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
void moveDisks(int disks, char from, char to, char via, int& moves);

int main()
{
    int disks = 0;
    int moves = 0;
    std::cout << "Enter number of Disks\n";
    cin >> disks;

    moveDisks(disks, 'A', 'C', 'B', moves);
    cout << "Number of moves is " << moves << endl;
}

void moveDisks(int disks, char from, char to, char aux, int& moves)
{
    if (disks == 1) {
        // Move last disk
        moves++;
        return;
    }
    // else moves disks first from source to via the to pole
    moveDisks(disks - 1, from, aux, to, moves);

    // move the disk from center to end via from
    moves++;
    moveDisks(disks - 1, aux, to, from, moves);
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
