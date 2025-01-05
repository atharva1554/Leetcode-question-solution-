//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#include <vector>
using namespace std;

class MyHashMap {
private:
    // We can use a vector of pairs or a linked list of pairs for separate chaining
    vector<pair<int, int>> hashMap[1000]; // Array of size 1000 for simplicity

    // A simple hash function to calculate the index
    int hash(int key) {
        return key % 1000; // Hash function based on modulo operator
    }

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        // The constructor doesn't need to do anything extra as the array is initialized
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = hash(key);
        // Check if key already exists and update its value
        for (auto &pair : hashMap[index]) {
            if (pair.first == key) {
                pair.second = value;  // Update the value
                return;
            }
        }
        // If key does not exist, add a new key-value pair
        hashMap[index].push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = hash(key);
        // Traverse the linked list at the index to find the key
        for (auto &pair : hashMap[index]) {
            if (pair.first == key) {
                return pair.second;  // Return the value
            }
        }
        return -1;  // If key is not found, return -1
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = hash(key);
        // Find the key and remove it from the list at the index
        for (auto it = hashMap[index].begin(); it != hashMap[index].end(); ++it) {
            if (it->first == key) {
                hashMap[index].erase(it);  // Remove the key-value pair
                return;
            }
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        MyHashMap obj;
        int q;
        cin >> q;
        while (q--) {
            string s;
            cin >> s;
            if (s == "put") {
                int key, val;
                cin >> key >> val;
                obj.put(key, val);
            }
            else if ( s == "remove") {
                int key;
                cin >> key;
                obj.remove(key);
            }
            else {
                int key;
                cin >> key;
                cout << obj.get(key) << endl;
            }
        }

cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends