//
//  main.cpp
//  DesignHashMap
//
//  Created by Kaleab Mekonen on 6/3/24.
//  Problem: https://leetcode.com/problems/design-hashmap/description/

#include <vector>
#include <iostream>
#include <cassert>

class MyHashMap {
private:
    // Max number of key value pair 10^4.
    //
    static const int SIZE = 10000;
    
    // Initialize multi dimensional vector [[key,value], [key,value]].
    //
    std::vector<std::pair<int, int>> HashMap[SIZE];
    
public:
    //  Constructor initializes the object with an empty map, the class has a map private property.
    //
    MyHashMap() {}

    //  inserts a (key, value) pair into the HashMap. If the key already exists in the map,
    // update the corresponding value
    //
    void put(int key, int value) {
        // Constraint
        //
        if (key < 0) return;
        
        // Search the key
        for (auto& keyValuePair : HashMap[key]) {
            // If it exists, update the value.
            //
            if (keyValuePair.first == key) {
                keyValuePair.second = value;
                return;
            }
        }
        
        // If key doesn't exist, create a key value pair and push it to the map.
        //
        HashMap[key].push_back({key, value});
    }
    
    int get(int key) {
        for (const auto& keyValuePair : HashMap[key]) {
            if (keyValuePair.first == key) {
                return keyValuePair.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        if (key < 0 || key >= SIZE) return; // Check if key is within valid range
        
        HashMap[key].clear(); // Clear the vector associated with the given key
    }
};


void testMyHashMap() {
    // ["MyHashMap","put","put","get","get","put","get","remove","get"]
    // [[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]
    
    int result = -1;
    
    // Create an instance of MyHashMap
    MyHashMap myHashMap;
    std::cout << "Hash map initialized."  << std::endl;
    
    // Insert key-value pairs into the HashMap
    myHashMap.put(1, 1);
    myHashMap.put(2, 1);

    // Verify insert
    result = myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
    assert(result == 1  && "Insert failed");
    result = myHashMap.get(2);
    assert(result == 1  && "Insert failed");
    result = myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    assert(result == -1 && "Insert failed");
    
    // Update
    myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    
    // Verify update
    result = myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
    assert(result == 1 && "Update failed");
    
    // Remove
    myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
    
    // Verify remove
    result = myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
    assert(result == -1 && "Remove failed");
}

int main() {
    testMyHashMap();
    return 0;
}
