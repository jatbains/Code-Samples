// TownJudge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

typedef struct Person
{
    int id;
    struct Person* next;
    Person() :id(0), next(nullptr) {}
}Person;

int findJudge(int N, vector<vector<int>>& trust);

int main()
{
    int pop = 3;
    vector<vector<int>> trust = { {1, 3},{2, 3},{3, 1} };

    cout << "The judge is " << findJudge(3, trust) << endl;
   // Create an adjacency list

}

int findJudge(int N, vector<vector<int>>& trust) {
    // Create ajacency list of size N
    // Populate it by going through trust vector
    // solve for the judge -- empty adjacency list and present in all other lists

    Person* people = new Person[N + 1];   // ignore 0
    // Populate the ids.
    for (int i = 1; i <= N; i++)
        people[i].id = i;

    for (vector<int> list : trust)
    {
        // Look in each vector
        vector<int>::iterator it = list.begin();
        // Check first for list
        int ind = *it;
        people[ind].id = ind;
        Person* folk = new Person();
        it++;
        int trusted = *it;
        folk->id = trusted;
        // Insert at head
        folk->next = people[ind].next;
        people[ind].next = folk;
    }

    // Search the graph
    // Find all candidate judges  
    for (int i = 1; i <= N; i++)
    {
        if (people[i].next == nullptr)
        {
            int cand = people[i].id;
            // Check to see if he is in all other lists
            // If found then break and return candidate id
            bool* isFound = new bool[N + 1];
            for (int i = 1; i <= N; i++)
            {
                if (cand == i)
                    continue;    // Skip candidates list
                Person* temp = nullptr;

                temp = people[i].next;
                while (temp != nullptr)
                {
                    // search for candidate
                    if (temp->id == cand)
                        isFound[i] = true;
                    temp = temp->next;
                }
            }
            // Check each Boolean array
            int trusted = 0;
            for (int i = 1; i <= N; i++)
            {
                if (i != cand)
                    if (isFound[i] == false)
                        break;
                    else
                        trusted++;
            }
            if (trusted == N - 1)
                return cand;
        }
    }
    // Not found
    return -1;
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
