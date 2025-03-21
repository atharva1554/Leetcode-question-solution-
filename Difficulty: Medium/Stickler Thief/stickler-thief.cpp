//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
  
  int solve(vector<int> &arr, int end, vector<int> &dp){
      
      if(end < 0){
          return 0;
      }
      
      if(dp[end] != -1){
          
          return dp[end];
          
      }
      // two calls for include and exclude
      // in include call if added then go for next of next
      
      int exclude = 0 + solve(arr, end - 1, dp);
      int include = arr[end] + solve(arr, end - 2, dp);
      
      return dp[end] = max(exclude, include);
     }
  
    int findMaxSum(vector<int>& arr) {
        // Your code here
        
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, n -1, dp);
        
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

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends