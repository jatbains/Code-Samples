// FindAmountOwed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Structure used to keep track of amounts
typedef struct Amount {
    int time;
    int dollars;
    Amount():time(0),dollars(0) {}
    Amount(int t, int monies) :time(t), dollars(monies) {}
}Amount;

// Main class that is used to keep track of money owed
class GetMoneyOwed {
private:
    map<string, Amount> Owed;
    map<string, Amount>::iterator it;
    // If reading from file
    string infile;  
public:
    void readOwedMoney(void);
    // Constructor if reading from file
    GetMoneyOwed(string file):infile(file){}
    int get_outstanding_amount(string p1, string p2);
};

// The main program will call method to read in values from a "file" and
// use those to populate a map containing the money owed by person A to Person B
//void readOwedMoney(map<string, Amount>& Owed);
//int get_outstanding_amount(string p1, string p2, map<string, Amount>& Owed);

int main()
{
    // Create monies class

    GetMoneyOwed monies("Hello.txt");
    // Read in the Data
    monies.readOwedMoney();
    
    // How much is owed from Person 1 to Person 2
    string s1 = "Dave";
    string s2 = "John";
    string key = s1 + s2;
    
    int money_owed = monies.get_outstanding_amount(s1, s2);
    if (money_owed > 0) {
        cout << "Amount owed by " << s1 << " to " << s2 << " is " << money_owed << endl;
    }
    else {
        money_owed *= -1;
        cout << "Amount " << s2 << " will pay to " << s1 << " is " << money_owed << endl;
    }

}

// Method to determine how much payee is owed
int GetMoneyOwed::get_outstanding_amount(string p1, string p2) {

    // Create a new key payor to payee
    string key1 = p1 + p2;
    // This key is the opposite if it exists in map
    string key2 = p2 + p1;
    int owed = 0;
    int receivable = 0;

    it = Owed.find(key1);
    if (it != Owed.end()) {
        // Money Owed to payee
        owed = Owed[key1].dollars;
    }
    it = Owed.find(key2);
    if (it != Owed.end()) {
        // Money payee owes
        receivable = Owed[key2].dollars;
    }
    // Net Money payee owed
    return owed - receivable;
}

// Method to read in data and add the amounts owed to a map
void GetMoneyOwed::readOwedMoney(void) {

    string payee, payor;
    int time = 0, money = 0;

    // If reading from a file then the code would read line by line and tokenize it
    vector<string> tokens;
    string token;
    char delimeter = ', ';
    fstream myfile;
 
    myfile.open(infile);  // Open input file
    myfile << "Hello World\n";
    myfile.close();
    
    myfile.open("sample.txt");
    string line;
    // Read one line at a time
    while(getline(myfile, line)) 
    {
       stringstream ss(line);
       while (getline(ss, token, delimeter)){
        tokens.push_back(token);
       }
       // Process tokens in vector as below and add to map
       


    }
    myfile.close();
   

    vector<vector<string>> monies = {{ "Dave, John, 1020040, 10"},
                                      { "John, Dave, 1020050, 30"},
                                      { "Mike, Paul, 1020900, 20"},
                                      {"Dave, John, 1020910, 10"},
                                      {"John, Dave, 1020950, 15"},
                                      {"John, Paul, 1030090, 20" }};
    string key = "";

    for (vector<string> v : monies) {
        // Process each line
        for (string s : v) {
            // Parse the string for payee, payor, timestamp and amount
            string delimeter = ", ";
            size_t pos = 0;
            string token;
            int i = 0;
            while ((pos = s.find(delimeter)) != string::npos) {
                token = s.substr(0, pos);
                switch (i) {
                case 0:
                    payor = token;
                    break;
                case 1:
                    payee = token;
                    break;
                case 2:
                    // time
                    time = stoi(token);
                    break;
                }
                s.erase(0, pos + delimeter.length());
                i++;
            }
            // Last word in line in string
            money = stoi(s);
           
            // Create Key
            string key = payor + payee;
            it = Owed.find(key);
            if (it != Owed.end()) {
                Owed[key].dollars += money;
            }
            else
            {
                Owed[key] = Amount(time, money);
            }
 
        }
    }

}
