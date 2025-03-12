//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string longest(vector<string>& arr) {
        // code here
        int maxi=0;
        string  maxival="";
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
           if(arr[i].size()>maxi)
           {
               maxi=arr[i].size();
               maxival=arr[i];
           }
        }
        return maxival;
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> names;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        string str;
        while (ss1 >> str) {
            names.push_back(str);
        }
        Solution obj;
        string res = obj.longest(names);
        cout << res << "\n~\n";
    }
}

// } Driver Code Ends