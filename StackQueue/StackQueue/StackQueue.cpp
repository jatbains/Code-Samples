// StackQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;

class StackQueue {
private:
    queue<int> primary;
    queue<int> secondary;
    queue<int>* act;
    queue<int>* bac;

public:
    StackQueue();
    void push(int x);
    int pop();
    int top();
    bool empty();

};

StackQueue::StackQueue() {
    act = &primary;
    bac = &secondary;
}

void StackQueue::push(int x) {
    // push into active queue
    act->push(x);
}
int StackQueue::pop() {
    // Move from active to standby
    // Get last save it 
    // switch pointers return last
    queue<int>* temp = NULL;
    int val = 0;

    while (!act->empty()) {
        val = act->front();
        act->pop();
        if (act->empty())
            break;
        bac->push(val);
    }

    temp = act;
    act = bac;
    bac = temp;
    return val;
}

int StackQueue::top() {
    // return top
    queue<int>* temp = NULL;
    int val = 0;

    while (!act->empty()) {
        val = act->front();
        act->pop();
  
        bac->push(val);
    }

    temp = act;
    act = bac;
    bac = temp;
    // val is topmost element
    return val;
}
bool StackQueue::empty() {
    return act->empty();
}

int main()
{
    std::cout << "Hello World!\n";
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
