// KeysandRooms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>

typedef struct Node {
    int room;
    Node* next;

    Node() :room(0), next(nullptr) {}
    Node(int x):room(x), next(nullptr) {}
}Node;

using namespace std;

bool canVisitAllRooms(vector<vector<int>>& rooms);
bool canStackVisitAllRooms(vector<vector<int>>& rooms);

int main()
{
    vector<vector<int>> rooms = { {1},{2},{3} };

    cout << canStackVisitAllRooms(rooms) << endl;
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {

    vector<bool> visited;
    // Create an adjaceny list of rooms and ones they can visit
    Node* Rooms;
    int N = 0;
    bool* seen = new bool[N];

    for (vector<int> v : rooms) {
        for (int i : v) {
            if (i > N)
                N = i;
        }
    }
    Rooms = new Node[N+1];  // Array of Rooms
    visited.resize(N+1);
    visited[0] = true;
    // Populate this list  Rooms[0] to Rooms[N-1]
    seen[0] = true;

    for (vector<int> v : rooms) {
        int index = v[0];
        // Set the zero'th to true
        Rooms[index].room = v[0];
        Node* p = Rooms[index].next;
        for (int i = 1; i < v.size(); i++) {
            p->next = new Node(v[i]);
            p = p->next;
        }

    }
    
    // Search through adjacency list mark visited
    for (int i = 0; i < N; i++) {
       Node *p = Rooms[i].next;
       while (p != nullptr) {
           // mark visited
           visited[p->room] = true;
           seen[p->room] = true;
       }
    }
    // Check visited
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == false)
            return false;
    }
    return true;
}

bool canStackVisitAllRooms(vector<vector<int>>& rooms) {

    bool* seen = new bool[rooms.size()];
    seen[0] = true;
    stack<int> todo;
    todo.push(0);

    while (!todo.empty()) {
        int node = todo.top();
        todo.pop();
        for (vector<int> v : rooms) {
            for (int nei : v) {
                if (!seen[nei]) {
                    seen[nei] = true;
                    todo.push(nei);
                }
            }
        }
    }
    for (int i = 0; i < rooms.size(); i++) {
        if (seen[i]== false)
            return false;
    }
    return true;
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
