//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool solve(string &s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++,j--;
        }
        return true;
    }
                string longestPalindrome(string &s) 
    {
    string ans="";
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
            if(s[i]==s[j]){
            string temp=s.substr(i,j-i+1);
            if(solve(temp))
            {
                if(ans.length()<temp.length())
                {
                    ans=temp;
                }
                break;
            }
            
            }
        }
        
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends