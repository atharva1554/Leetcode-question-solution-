//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        unordered_set<int> prefixSums;
        int prefixSum = 0;
        
        // Traverse through the array
        for (int i = 0; i < arr.size(); i++) {
            // Add current element to the running prefix sum
            prefixSum += arr[i];
            
            // If prefixSum is 0 or already exists in the set, return true
            if (prefixSum == 0 || prefixSums.find(prefixSum) != prefixSums.end()) {
                return true;
            }
            
            // Add the current prefix sum to the set
            prefixSums.insert(prefixSum);
        }
        
        // No subarray with zero sum exists
        return false;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        if (obj.subArrayExists(arr))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends