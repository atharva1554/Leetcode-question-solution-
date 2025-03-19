//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i, int k, int& n, vector<int>& prices, vector<vector<int>>& dp) {
        // base case
        if(k == 0) {
            return 0;
        }
        if(i == n) {
            return 0;
        }
        if(dp[i][k] != -1) {
            return dp[i][k];
        }
        int ans = 0;
        if(k % 2) { // sell
            ans = ans + prices[i] + solve(i + 1, k - 1, n, prices, dp);
        }
        else { // buy
            ans = ans - prices[i] + solve(i + 1, k - 1, n, prices, dp);
        }
        // skip
        ans = max(ans, solve(i + 1, k, n, prices, dp));
        return dp[i][k] = ans;
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2 * k + 1, -1));
        return solve(0, 2 * k, n, prices, dp);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends