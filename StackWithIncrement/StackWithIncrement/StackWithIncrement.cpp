// StackWithIncrement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class CustomStack {
public:
    int* stack;
    int capacity;
    int top;
    CustomStack(int maxSize):capacity(maxSize+1) {
        stack = new int[maxSize + 1];
        for (int i = 0; i <= capacity; i++) {
            stack[i] = 0;
        }
        top = capacity;
    }

    int pop() {
        if (top == capacity)
            return -1;
        int x = stack[top];
        top++;
        return x;
    }

    void push(int x) {
        if (top == 0)
            return;
        if (top == capacity) {
            stack[top] = x;
            top--;
        }
        else {
            top--;
            stack[top] = x;
        }
 
    }

    void increment(int k, int val) {
        int i = capacity - 1;

        while (k != 0 || i == 0) {
            stack[i] += val;
            cout << "Stack Val" << stack[i] << endl;
            k--;
            i--;
        }
  
    }
};

int main()
{
    // Create a Custom Stack
    CustomStack myStack(100);
   // Perform OPerations
    myStack.push(3);
    myStack.push(1);
    myStack.push(2);
    cout << myStack.pop() << endl;
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.increment(5, 100);
    myStack.increment(2, 100);
    cout << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;
    cout << myStack.pop() << endl;

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
