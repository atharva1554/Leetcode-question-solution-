//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        map<long long,int>a;
        long long sum=0;
        int maxlen=0;
        for(int i=0;i<N;i++)
        {
            sum=sum+A[i];
            if(sum==K)
            {
                maxlen=max(maxlen,i+1);
            }
            long long rem =sum-K;
            if(a.find(rem)!=a.end())
            {
                int len=i-a[rem];
                maxlen=max(maxlen,len);
            }
            if(a.find(sum)==a.end())
            {
                a[sum]=i;
            }
        
            }
            return maxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends