//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        long long ans=0;long long t=0;
        sort(bt.begin(),bt.end());
        for(int i=0;i<n;i++)
        {
            t=t+bt[i];
            ans=ans+t;
        }
      // cout<<ans-t<<endl;
        return ceil((ans-t)/n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends