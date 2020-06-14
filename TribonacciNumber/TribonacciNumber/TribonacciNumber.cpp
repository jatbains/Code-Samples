// TribonacciNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


int main()
{
    


}

int tribonacci(int n) {

    // Base cases  Recursive and iterative
#if 0
    int* mem = new int[n + 1];
    for (int i = 0; i <= n; i++)
        mem[i] = -1;

    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    return (tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3));

    return tribRecur(n, mem);

#endif;
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return tribIter(n);
}
int tribIter(int n)
{
    int a = 0;
    int b = 1;
    int c = 1;
    int trib = a + b + c;
    int index = 3;
    if (n < 4)
        return trib;

    while (index < n)
    {
        a = b;
        b = c;
        c = trib;
        trib = a + b + c;
        index++;
    }
    return trib;
}

int tribRecur(int n, int mem[])
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    if (mem[n] != -1)
        return mem[n];
    else
        mem[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);

    return mem[n];
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
