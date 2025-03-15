//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
            int INF = INT_MAX - 1; // Large value to avoid overflow
    vector<int> dp(sum + 1, INF);
    dp[0] = 0; // Base case: 0 coins needed to form sum 0

    for (int coin : coins) {
        for (int j = coin; j <= sum; j++) {
            if (dp[j - coin] != INF) {
                dp[j] = min(dp[j], 1 + dp[j - coin]);
            }
        }
    }
    return (dp[sum] == INF) ? -1 : dp[sum];
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends