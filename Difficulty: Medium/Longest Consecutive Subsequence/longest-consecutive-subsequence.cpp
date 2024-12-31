//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        if (arr.empty()) return 0; // Handle edge case for empty array

    sort(arr.begin(), arr.end()); // Sort the array
    int n = arr.size();
    int x = 1; // Current sequence length
    int ans = 1; // Maximum sequence length

    for (int i = 1; i < n; i++) { // Start from the second element
        if (arr[i] == arr[i - 1]) {
            // Skip duplicate elements
            continue;
        }
        if (arr[i] == arr[i - 1] + 1) {
            // Increment sequence length for consecutive elements
            x++;
        } else {
            // Reset sequence length for non-consecutive elements
            x = 1;
        }
        ans = max(ans, x); // Update maximum sequence length
    }
    return ans;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends