//
//  main.cpp
//  DesignHashMap
//
//  Created by Kaleab Mekonen on 6/3/24.
//

#include <vector>
#include <iostream>

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
           
    }
};


void testMyHashMap() {
    // ["MyHashMap","put","put","get","get","put","get","remove","get"]
    // [[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]
    
    
    // Create an instance of MyHashMap
    MyHashMap myHashMap;
    std::cout << "Actual: " << myHashMap.get(0) << "Expected: []"  << std::endl;
    
    // Insert key-value pairs into the HashMap
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    
    // Retrieve values from the HashMap
    
    std::cout << "Actual: " << myHashMap.get(0) << "Expected: []"  << std::endl;
    std::cout << "Value for key 1: " << myHashMap.get(1) << std::endl; // Output: 1
    std::cout << "Value for key 3: " << myHashMap.get(3) << std::endl; // Output: -1
    
    // Update an existing key-value pair
    myHashMap.put(2, 1);
    
    // Retrieve the updated value
    std::cout << "Updated value for key 2: " << myHashMap.get(2) << std::endl; // Output: 1
    
    // Remove a key-value pair
    myHashMap.remove(2);
    
    // Attempt to retrieve the removed key
    std::cout << "Value for key 2 after removal: " << myHashMap.get(2) << std::endl; // Output: -1
}

int main() {
    // testMyHashMap();
    return 0;
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
