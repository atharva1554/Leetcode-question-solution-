//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   long subarrayXor(vector<int>& arr, int k) {
    unordered_map<int, int> prefixXorCount;
    int currentXor = 0;
    long count = 0;

    for (int num : arr) {
        currentXor ^= num;

        // If the current XOR is equal to k, it forms a valid subarray
        if (currentXor == k) {
            count++;
        }

        // Check if there exists a prefix with XOR `currentXor ^ k`
        int targetXor = currentXor ^ k;
        if (prefixXorCount.find(targetXor) != prefixXorCount.end()) {
            count += prefixXorCount[targetXor];
        }

        // Store the current XOR in the map
        prefixXorCount[currentXor]++;
    }

    return count;
}
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends