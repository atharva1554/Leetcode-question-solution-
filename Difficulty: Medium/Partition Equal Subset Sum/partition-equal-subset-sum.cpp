//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int rec(int i,vector<int> &a,int k,int s,vector<vector<int>> &dp){
        if(s==k) return dp[i][s]=1;
        if(i>=a.size() || s>k) return dp[i][k]=0;
        if(dp[i][s]!=-1) return dp[i][s];
        return dp[i][s]=rec(i+1,a,k,s+a[i],dp) || rec(i+1,a,k,s,dp);
    }
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int s=accumulate(arr.begin(),arr.end(),0);
        if(s&1) return 0;
        int target=s/2;
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        bool ans=rec(0,arr,target,0,dp);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends