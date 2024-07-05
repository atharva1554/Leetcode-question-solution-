//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    vector<int>a;
	    int maxi=INT_MIN;
	    for(int i=0;i<n;i++)
	    {   int ans=0;
	        for(int j=0;j<m;j++)
	        {
	            ans=ans+arr[i][j];
	        }
	        maxi=max(maxi,ans);
	        a.push_back(ans);
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(maxi==a[i]&&maxi>0)
	        {
	            return i;
	        }
	    }
	    return -1;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends