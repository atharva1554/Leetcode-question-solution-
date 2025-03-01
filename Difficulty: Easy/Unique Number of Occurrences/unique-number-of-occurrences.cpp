//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        map<int,int>mpp;
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]]++;
        }
        map<int,int>b;
        for(auto it:mpp)
        {
            if(b[it.second]!=0)
            {
                return false;
            }
            b[it.second]++;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends