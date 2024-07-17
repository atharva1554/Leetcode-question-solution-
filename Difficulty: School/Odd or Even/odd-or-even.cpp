//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string oddEven(int N){
        // code here 
        int n=N;
        string ans="";
        while(n>0)
        {
            if(n%2==0)
            {
                ans=ans+'0';
            }
            else
            {
                ans=ans+'1';
            }
            n=n/2;
        }
        if(ans[0]=='1')
        {
            return "odd";
        }
        else
        {
            return "even";
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.oddEven(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends