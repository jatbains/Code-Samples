// HuffmanTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>

using namespace std;

using uchar = unsigned char;

typedef struct Node {
    char symbol;
    int frequency;
    Node* left = nullptr;
    Node* right = nullptr;
    Node():symbol('0'),frequency(0),left(nullptr),right(nullptr) {}
    Node(char c, int f) :symbol(c), frequency(f), left(nullptr), right(nullptr) {}

}Node;

void count_frequency(Node* terminals, std::basic_string<uchar> const& input) {
    // ...
    int len = input.size();

    for (int i = 0; i < 256; i++) {
        terminals[i].symbol = i;
        terminals[i].frequency = 0;
    }

    for (int i = 0; i < len; i++) {
        auto const c = input[i];

        terminals[c].symbol = c;
        terminals[c].frequency++;

    }
}

int main() {
    Node terminals[256];

    std::basic_string<uchar> input{ (uchar const*)"ddededdedrdabcaba\xff\xfe" };

    count_frequency(terminals, input);

    for (int i = 0; i < 256; i++) {
        if (terminals[i].frequency != 0) {
            cout << "Symbol: " << terminals[i].symbol << endl;
            cout << "  Frequency: " << terminals[i].frequency << endl;
        }
    }

    auto const comparer = [](Node const* lhs, Node const* rhs) {
        bool greater = lhs->symbol < rhs->symbol; // lhs smaller character
        bool value = lhs->frequency > rhs->frequency;  // Smaller value on lhs
        if (value) {
            return value;
        }
        if (lhs->frequency == rhs->frequency) {
            return greater;
        }
        return false;
    };

    priority_queue<Node*, std::vector<Node*>, decltype(comparer)> list{ comparer };
    // INsert nodes that have a frequency > 0
    for (int i = 0; i < 256; i++) {
        if (terminals[i].frequency > 0) {
            list.push(&terminals[i]);
        }
    }

    /*while (!list.empty()){
        // Print smallest and pop it
        struct node *p = list.top();
                cout << p->symbol << endl;
        cout <<  "   " << p->frequency << endl;
        // remove
        list.pop();
    }*/

    Node non_terminals[256];
    size_t nt_count = 0;
    // Go through priority queue 
    // Get two smallest nodes -- add frequencies pop
    // Insert them back as left anf right pointers for that summed node
    Node* a = nullptr;
    Node* b = nullptr;

    while (list.size() > 1) {
        a = list.top();
        list.pop();
        b = list.top();
        list.pop();
        non_terminals[nt_count].frequency = a->frequency + b->frequency;
        non_terminals[nt_count].left = a;
        non_terminals[nt_count].right = b;
        list.push(&non_terminals[nt_count]);
        nt_count++;
    }

}

/*
    a: 3
    b: 2
    c: 1

        *
       / \
      A   *
         / \
        B   C


        a: 0
        b: 10
        c: 11
*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
