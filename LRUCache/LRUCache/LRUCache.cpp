// LRUCache.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

typedef pair<int, int> val;

class LRUCache {
private:
    int csize;
    list<val> cache;
    unordered_map<int, list<val>::iterator> look;
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
};

LRUCache::LRUCache(int capacity) : csize(capacity) {}
  

int LRUCache::get(int key) {
    // Check if key < capacity
    // if found i.e. value is not -1 move it to front of array
    // else return -1
  
    if (look.find(key) == look.end()) {
        // not in list
        return -1;
    }
    // else erase old entry get value
    int nVal = look[key]->second;
    // Erase value and push to front
   // val node = cache.back();
    cache.erase(look[key]);
    val insert = make_pair(key, nVal);
    cache.push_front(insert);
    look[key] = cache.begin();

    // Not found
    return nVal;
 
}
void LRUCache::put(int key, int value) {
    // Check if we exceed size
    // If exceeded then delete last and add to front
    // else 
   // Check if in cache  Update if in cache move to front
    // 
    val newVal = make_pair(key, value);
    // Check if already there
    if (look.find(key) == look.end()) {  // Not in list
        // See if full

        if (cache.size() == csize) {
            // delete least recently used element 
            val last = cache.back();

            // Pops the last elmeent 
            cache.pop_back();

            // Erase the last 
            look.erase(last.first);
        }

    }
    else {
        cache.erase(look[key]);
    }
 
    cache.push_front(newVal);
    look[key] = cache.begin();
}

int main()
{
    LRUCache myCache(10);

    myCache.put(2, 25);
    myCache.put(5, 12);
    myCache.put(0, 19);
    myCache.put(4, 100);

    cout << myCache.get(0) << endl;
    cout << myCache.get(9) << endl;
    
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
