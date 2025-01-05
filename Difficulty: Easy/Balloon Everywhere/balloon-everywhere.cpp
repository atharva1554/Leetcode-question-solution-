//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int maxInstance(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Calculate the maximum number of "balloon" instances
        int b = freq['b'];
        int a = freq['a'];
        int l = freq['l'] / 2;
        int o = freq['o'] / 2;
        int n = freq['n'];
        
        // Return the minimum of these values
        return min({b, a, l, o, n});
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends