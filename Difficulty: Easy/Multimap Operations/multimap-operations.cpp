//{ Driver Code Starts
// Initial Template for C++
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++



multimap<int, int> multimapInsert(vector<int>& arr) {
    multimap<int, int> mp;
    // Insert arr[i] as key and i as value in the multimap
    for(int i = 0; i < arr.size(); i++) {
        mp.insert({arr[i], i});  // Correct way to insert (allows multiple values for the same key)
    }
    return mp;
}

void multimapDisplay(multimap<int, int> mp) {
    // Print the keys and value pairs in a new line
    for(auto it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << " " << it->second << endl;  // Print key and value
    }
}

void multimapErase(multimap<int, int>& mp, int x) {
    // Erase elements with key x from the multimap
    auto range = mp.equal_range(x);  // Get the range of elements with key x
    if (range.first != range.second) {
        cout << "erased " << x << endl;
        mp.erase(x);  // Erase all elements with key x
    } else {
        cout << "not found" << endl;
    }
}




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        multimap<int, int> mp =
            multimapInsert(arr); // multimap insert function that returns a function
        multimapDisplay(mp);     // print the keys and values of the multimap
        int x;
        cin >> x; // element to be erased
        cin.ignore();
        multimapErase(mp, x); // the erase function
        multimapDisplay(mp);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends