//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        int a[n+1]={0};
        for(int i=0;i<n;i++)
        {
            a[arr[i]]++;
        }
        int b=-1,c=-1;
        for(int i=0;i<=n;i++)
        {
            if(a[i]==2)
            {
                b=i;
            }
            if(a[i]==0)
            {
                c=i;
            }
        }
        // code here
        return {b,c};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends