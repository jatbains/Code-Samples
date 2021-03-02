// FindMedianOfTwoSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int findMedian(vector<int> v1, vector<int> v2);
int medianVector(vector<int> v1, vector<int> v2);

int main()
{
    vector<int> v1 = { 1,2,3,4 };
    vector<int> v2 = { 10,20,30,40,50 };
    
    cout << "The Median of two vectors is " << findMedian(v1, v2) << endl;

    cout << "The Median Vector " << medianVector(v1, v2) << endl;
}

int findMedian(vector<int> v1, vector<int> v2) {
    // Algorithm
    // Use two pointers to increment through two sorted lists
    // Keep track of element count and return the (N + M)/2 element
    int l1 = v1.size();
    int l2 = v2.size();
    int i = 0, j = 0;  // Individual indexes into arrays
    int m1 = -1, m2 = -1;     // Return value medians
    int count = 0; // Here count keeps track of elements checked


    // Odd or even  for even element is (l1+l2) /2
    if ((l1 + l2) % 2 == 1) {
        for (count = 0; count <= (l1 + l2) / 2; count++) {
            if (i != l1 && j != l2) {
                m1 = (v1[i] > v2[j]) ? v2[j++] : v1[i++];
            }
            else if (i < l1) {
                m1 = v1[i++];
            }
            else {
                m1 = v2[j++];
            }

        }
        return m1;
    }
    else {   // Even Median is the average of elements at (l1+l2)/2 -1 and (l1+l2)/2 +1
        for (count = 0; count <= (l1 + l2) / 2; count++) {
            m2 = m1; // save previous value
            if (i != l1 && j != l2)
            {
                m1 = (v1[i] > v2[j]) ? v2[j++] : v1[i++];
            }
            else if (i < l1)
            {
                m1 = v1[i++];
            }
            // for case when j<m, 
            else
            {
                m1 = v2[j++];
            }
        }
        return (m1 + m2) / 2;
    }
}

int medianVector(vector<int> v1, vector<int> v2) {
    vector<int> merge;

    int i = 0, j = 0;
    int l1 = v1.size();
    int l2 = v2.size();
    int count = 0;
    int val = 0;
    

    while (count < l1 + l2) {
        if (i != l1 && j != l2) {
            val = v1[i] < v2[j] ? v1[i++] : v2[j++];
            merge.push_back(val);
        }
        else if (i < l1) {
            val = v1[i++];
            merge.push_back(val);
        }
        else {
            val = v2[j++];
            merge.push_back(val);
        }
        count++;
    }
    int len = merge.size();
    if (len % 2 == 1) {
        return (merge[len / 2]);
    }
    else {
        return (merge[len / 2] + merge[len / 2 + 1] / 2);
    }
}