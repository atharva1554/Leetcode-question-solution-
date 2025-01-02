//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int countSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefixSumCount; // To store the frequency of prefix sums
        int currentSum = 0;  // Current prefix sum
        int cnt = 0;         // Count of subarrays with sum = k

        // Initialize with prefix sum = 0
        prefixSumCount[0] = 1;

        for (int num : arr) {
            currentSum += num;

            // Check if there is a prefix sum that satisfies the condition
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end()) {
                cnt += prefixSumCount[currentSum - k];
            }

            // Update the frequency of the current prefix sum
            prefixSumCount[currentSum]++;
        }

        return cnt;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends