// QueueStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

class QueueStack {
private:
    stack<int> s1;
    stack<int> s2;
    stack<int>* active;
    stack<int>* backup;

public:
    QueueStack(void);
    void Enqueue(int i);
    int Dequeue(void);
    int Peek();
    bool Empty();
};

QueueStack::QueueStack(void) {
    active = &s1;
    backup = &s2;
}

bool QueueStack::Empty() {
    return active->empty();
}

int QueueStack::Peek(void) {
    if (!active->empty())
        return active->top();
    else
        return 0;
}
void QueueStack::Enqueue(int i) {
    while (!active->empty()) {
        backup->push(active->top());
        active->pop();
    }
    active->push(i);
    // Move back
    while (!backup->empty()) {
        active->push(backup->top());
        backup->pop();
    }

}
// Dequeue pop from active to secondary
int QueueStack::Dequeue(void)
{
    int val;
    if (active->empty())
        return 0;
 
    val = active->top();
    active->pop();
    return val;
   
}
int main()
{
    std::cout << "Hello World!\n";
    QueueStack qs;
    for (int i = 0; i < 2; i++) {
       
        int val = rand() % 101;
        cout << "Enqueue " << val << endl;
        qs.Enqueue(val);
        
    }
    cout << qs.Peek() << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Dequeue " << qs.Dequeue() << endl;
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
