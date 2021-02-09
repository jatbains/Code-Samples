// EmployeesFreeTime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<string> freeEmployees(void);

int main()
{
    cout << "Find when employees are all and mostly free" << endl;
 
    vector<string> names;
    names = freeEmployees();

    vector<string>::iterator it = names.begin();
    while (it != names.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

vector<string> freeEmployees(void)
{
    string e1 = "Dan";
    string e2 = "Dave";
    string e3 = "Jan";
    string e4 = "Joe";
    vector<int> t1 = { 1,0,1,1,1,0,1 };
    vector<int> t2 = { 0,0,1,1,0,1,1 };
    vector<int> t3 = { 1,1,1,0,0,0,0 };
    vector<int> t4 = { 1,0,0,0,1,1,1 };

    map<string, vector<int>> employeeSlots;
    employeeSlots[e1] = t1;
    employeeSlots[e2] = t2;
    employeeSlots[e3] = t3;
    employeeSlots[e4] = t4;

    vector<string> names;

    vector<int> free;
    // Go through the map and increment the free vector free is 0
   
    free.resize(8);
    vector<int>::iterator ite = free.begin();
 

    map<string, vector<int>>::iterator itm = employeeSlots.begin();

    while (itm != employeeSlots.end()) {

        vector<int>::iterator iti = itm->second.begin();
        while (iti != itm->second.end()) {

            if (*iti == 0) {
                (*ite)++;
            }
 
            ite++;
            iti++;
        }

        ite = free.begin();
        itm++;

    }

    // Check the freq vector
    ite = free.begin();
    int max = 0;
    while (ite != free.end())
    {
        if (max < *ite) {
            max = *ite;
        }
        ite++;
    }
  
    itm = employeeSlots.begin();
    if (max == employeeSlots.size()) {
        // All of employees
        while (itm != employeeSlots.end()) {
            names.push_back(itm->first);
            itm++;
        }
    }
    else {
        ite = free.begin();
        int index = 0;
        while (ite != free.end()) {
            if (max == *ite) {
                break;
            }
            index++;
            ite++;
        }
        // Get names for this index
        while (itm != employeeSlots.end()) {

            if (itm->second[index] == 0) {
                names.push_back(itm->first);
            }
            itm++;
        }
    }

    return names;
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
