// AWSLRU.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>
#include <map>


/*
* Map<K,V> {
    put(K,V)
    V get(K)
    
    V getAverage(){
        
    }
}
*/
// Time TO Live - TTL  - put time stamp the entry
// Get needs to check the time stamp against current time > INsert Time + TTL  -- Remove Expired Values
// Get Average -- Go through the list of <K,V> check for expired add only unexpired -- get average return Avergage Value
// Binary Tree with K index  Value -- Search would disregard left side of tree -- K -- Time stamp
// Sorted and Hash  
using namespace std;

typedef struct MapEntry {
    time_t time;
    string K;
    int V;
    MapEntry* left;
    MapEntry* right;
    MapEntry(string KVal, int Val) :time(std::time(0)), K(KVal), V(Val), left(nullptr), right(nullptr) {}
}MapEntry;

class Map{
    public:
    int TTL;
    MapEntry* map;  // pointer to Node -> Root Node

    Map():map(nullptr),TTL(0) {}
    unordered_map<string,MapEntry *> hashMap;
    void Put(string K, int V);
    void PutIn(MapEntry*& map, string K, int V);
    int Get(string K);
    int GetVal(MapEntry*& map, string K);

    int GetAverage();
    int GetAverageVal(MapEntry*& map, int sum, int count);
};
// Methods for the Map
void Map::Put(string K, int V) {
    PutIn(map, K, V);
}

void Map::PutIn(MapEntry*& map, string K, int V) {
    // Look through the map and find values
    if (map == nullptr) {
        MapEntry *temp = new MapEntry(K, V);
        map = temp;
        hashMap[K] = map;
        return;
    }

    if (K < map->K) {
        PutIn(map->left, K, V);
    }
    else {
        PutIn(map->right, K, V);
    }
    return;
}

int Map::Get(string K) {
    return GetVal(map, K);
}
int Map::GetVal(MapEntry*& map, string K) {
    // Find the Key
    //int curTime = getTime();
    //int timeINterval = curTime + TTL;  // Total elapsed time 
    if (map == nullptr) {  // Not found
        return 0;
    }

    if (map->K == K) { // Found K 
            // Check it time 
        if (map->time + TTL > time(0)) {
            return map->V;
        }
        else
            return 0;
    }
    // Search the left and right sides of tree
    if (map->K < K) {
        return GetVal(map->left, K);
    }
    else {
        return GetVal(map->right, K);
    }
}

int Map::GetAverage() {
    return GetAverageVal(map, 0, 0);
}

int Map::GetAverageVal(MapEntry*& map, int sum, int count) {
    if (map == nullptr)
        return sum/count;

    if (map->time + TTL > 0) {
        sum += map->V;
        count++;
    }
    // Search left and right
    return GetAverageVal(map->left, sum, count) + GetAverageVal(map->right, sum, count);
    
}

int main()
{
    std::cout << "Hello World!\n";
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
