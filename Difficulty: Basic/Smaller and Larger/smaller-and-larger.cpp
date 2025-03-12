//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    vector<int> getMoreAndLess(vector<int> &arr, int target) {
        // code here
        int mini=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++)
        {
            if(target>arr[i])
            {
                maxi++;
            }
            else if(target<arr[i])
            {
                mini++;
            }
            else
            {
                mini++;
                maxi++;
            }
        }
        return{maxi,mini};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        Solution ob;
        vector<int> ans = ob.getMoreAndLess(arr, x);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends