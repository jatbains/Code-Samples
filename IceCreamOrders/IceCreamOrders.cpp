// IceCreamOrders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Scoops {
private:
    string flavor;
    int num;
public:
    Scoops(string flavor, int num) :flavor(flavor), num(num) {}
    string GetScoops(void) { return flavor + " " + to_string(num); }
};

class Flavors {
private:
    vector<Scoops> flavors;
public:
    Flavors(vector<Scoops> flavors) :flavors(flavors) {}
    void AddFlavors(Scoops s) { flavors.push_back(s); }
    vector<Scoops> GetOrder(void) { return flavors; }
};

class Customer {
private:
    string name;
    string address;
public:
    Customer(string name, string address) :name(name), address(address) {}
    string GetCust(void) { return name + " " + address; }
};

class Order {
private:
    class Customer c;
    class Flavors f;
public:
    Order(Customer c, Flavors f) :c(c), f(f) {}
    void GetOrder(void) {
        cout << c.GetCust() << endl;
        vector<Scoops> s = f.GetOrder();
        for (Scoops s : s) {
            cout << s.GetScoops() << endl;
        }
    }
};

int main()
{
    Scoops scoop1("vanilla", 2);
    Scoops scoop2("chocolate", 1);
    vector<Scoops> list;
    list.push_back(scoop1);
    list.push_back(scoop2);
 
    Flavors flav(list);
   
    Customer jane("Jane", "23 White Road");
    Order order1(jane, flav);

    order1.GetOrder();
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
