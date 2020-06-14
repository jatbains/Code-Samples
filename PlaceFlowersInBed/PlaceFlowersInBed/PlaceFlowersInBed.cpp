// PlaceFlowersInBed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n);
int PlaceFlowers(vector<int> flowerbed);

int main()
{
    std::cout << "Hello World!\n";
}

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    // Loop through array and attempt to place flowers
    // If number that can be placed is equal or greater then n then true
    // start at n=1, for n = 0 and n = size only one adjacent bed
    int plant = 0;  // How many can be planted
    plant = PlaceFlowers(flowerbed);
    if (plant >= n)
        return true;
    else
        return false;
}

// Can we solve by recursion??  Basecase n = 1 if n-1 ==0 and n+1 ==0 true else false
int PlaceFlowers(vector<int> flowerbed)
{
    int count = 0;
    int length = flowerbed.size();
    int i = 0;

    while (i < length) {

        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) &&
            (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
        {
            flowerbed[i] = 1;
            count++;
        }
        i++;
    }


    return count;
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
