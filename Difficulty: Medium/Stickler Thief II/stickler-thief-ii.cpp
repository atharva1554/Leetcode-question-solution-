//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int solve(int i, vector<int>& arr, vector<int>& dp){
        if(i>=arr.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int notpick=solve(i+1,arr,dp);
        int pick=arr[i]+solve(i+2,arr,dp);
        return dp[i]=max(pick,notpick);
    }
    int maxValue(vector<int>& arr) {
        // your code here
         int n=arr.size();
        vector<int> dp1(n,-1),dp2(n,-1);
        int ans1=solve(1,arr,dp1);
        arr.pop_back();
        int ans2=solve(0,arr,dp2);
        return max(ans1,ans2);
         
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends