// PrimeNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;

int countPrimes(int n);
bool isPrime(int n);

int main()
{
    int num = 13;

    cout << "Prime count is " << countPrimes(num) << endl;
}
int countPrimes(int n) {
    int count = 0;

    if (n == 2)
        return 0;

    for (int i = 2; i < n; i++) {
        if (isPrime(i))
            count++;
    }
    return  count;
}

bool isPrime(int n)
{
    // Corner cases 
    if (n <= 1)
        return false;

    // This is checked so that we can skip 
    // middle five numbers in below loop 
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Function to print primes 
void printPrime(int n)
{
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
            cout << i << " ";
    }
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
