// ThousandEye.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
// Class that implements a basic network test case


typedef union number {
    double dVal;
    long int lVal;
    int val;

}number;

class BaseNetworkTest {

private:
    string testName;
    string targetId;

public:
    BaseNetworkTest(string name, string Id) :testName(name), targetId(Id) {}
    string getTestDescription(void) { return testName + "-" + targetId; }
    virtual double computeValue(vector<long int> points);
};


double BaseNetworkTest::computeValue(vector<long int> points) {
    int num;
    num = points.size();
    return (double)num;

}


class NetworkTest: public BaseNetworkTest {

public:
    NetworkTest(string name, string Id) : BaseNetworkTest(name, Id) {}
    double computeValue(vector<long int> points);
};
// Abstract Class
class Metric {
private:
    string testName;
public:
    Metric(string test) :testName(test) {}
    virtual long int computeAggregation(vector<long int> points) = 0;
};

class ErrorMetric : public Metric {
public:
    ErrorMetric(string test) : Metric(test) {}
    long int computeAggregation(vector<long int> points);
};

class PacketLossMetric : public Metric {
public:
    PacketLossMetric(string test) : Metric(test) {}
    long int computeAggregation(vector<long int> points);
};


double NetworkTest::computeValue(vector<long int> points) {

    long int errors = 0;
    long int losses = 0;

    ErrorMetric errorMetric("error");
    PacketLossMetric packetMetric("packet");


    errors = errorMetric.computeAggregation(points);
    losses = packetMetric.computeAggregation(points);

    // Return the Errors / Packet loss  
    // If Packet loss in 0 don't divide!!
    if (losses == 0) {
        return DBL_MAX;
    }
    else {
        return (double)errors / losses;
    }
}




long int ErrorMetric::computeAggregation(vector<long int> points) {

    long int count = 0;

    vector<long int>::iterator it = points.begin();

    while (it != points.end()) {

        if (*it == -1)
            count++;
        it++;
    }
    return count;
}

long int PacketLossMetric::computeAggregation(vector<long int> points) {
    long int count = 0;

    vector<long int>::iterator it = points.begin();

    while (it != points.end()) {
        if (*it == 0)
            count++;
        it++;
    }
    return count;
}





int main() {

    vector<long int> vals = { 5L, 0L, 2L, 0L, -1L, 3L };

    NetworkTest nTest("Error Loss Metric", "thousandeyes.com");   // Instantiate network test

    cout << nTest.getTestDescription() << endl;
    cout << "Compute Value is " << nTest.computeValue(vals);


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
