//
//  main.cpp
//  DesignHashMap
//
//  Created by Kaleab Mekonen on 6/3/24.
//  Problem: https://leetcode.com/problems/design-hashmap/description/

#include <iostream>
#include <cassert>
#include <unordered_map>

class MyHashMap {
private:
    std::unordered_map<int, int> hashMap;

public:
    MyHashMap() {}

    void put(int key, int value) {
        hashMap[key] = value;
    }

    int get(int key) {
        if (hashMap.find(key) != hashMap.end()) {
            return hashMap[key];
        } else {
            return -1;
        }
    }

    void remove(int key) {
        if (hashMap.find(key) != hashMap.end()) {
            hashMap.erase(key);
        }
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
