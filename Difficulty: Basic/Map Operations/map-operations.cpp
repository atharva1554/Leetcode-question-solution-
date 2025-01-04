//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

map<int, int> mapInsert(vector<int>& arr) {
    map<int, int> mp;
    // Insert arr[i] as key and i as value
     for(int i=0;i<arr.size();i++)
     {
         mp[arr[i]]=i;
     }
    return mp;
}

void mapDisplay(map<int, int>& mp) {
    
    for(auto it:mp)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
}

void mapErase(map<int, int>& mp, int x) {
    // Check if the key exists
    if (mp.find(x) != mp.end()) {
        mp.erase(x);  // Erase the element if it exists
        cout << "erased " << x;
    } else {
        cout << "not found";
    }
    cout << endl;
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
        map<int, int> mp = mapInsert(arr); // map insert function that returns a
                                           // function
        mapDisplay(mp);                    // print the keys and values of the map
        int x;
        cin >> x; // element to be erased
        cin.ignore();
        mapErase(mp, x); // the erase function
        mapDisplay(mp);
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends