//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int low=0;
	    int high=m;
	    int ans=-1;
	    while(low<=high)
	    {
	        int mid=(low+high)/2;
	        if(pow(mid,n)>m)
	        {
	            high=mid-1;
	        }
	        else
	        {
	            if(pow(mid,n)==m)
	            {
	                ans=max(ans,mid);
	                return ans;
	                break;
	            }
	            else
	            {
	               if(pow(mid,n)<m)
	               {
	                   ans=max(ans,mid);
	                    low=mid+1;
	               }
	            }
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends