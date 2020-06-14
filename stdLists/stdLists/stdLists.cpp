// stdLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>

using namespace std;

typedef struct Person {
    string name;
    int age;
    Person(string who, int old) :name(who), age(old) {}
}Person;

int main()
{
    list<Person> people;

    // Add people
    Person *temp = new Person("Jim", 18);
    people.push_back(*temp);
    temp = new Person("Joe", 23);
    people.push_back(*temp);
    temp = new Person("Jill", 27);
    people.push_back(*temp);
    temp = new Person("Dave", 29);
    people.push_back(*temp);

    list<Person>::iterator it;
    it = people.begin();
    while (it != people.end()) {
        cout << "Name " << it->name << " Age " << it->age << endl;
        it++;
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
