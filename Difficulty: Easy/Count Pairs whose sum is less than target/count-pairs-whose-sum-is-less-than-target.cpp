//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int ans=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++)
        {   
            if(arr[i]>target)
            {
                break;
            }
            for(int j=0;j<arr.size();j++)
            {
                if(i!=j)
                {
                    if(arr[i]+arr[j]<target)
                    {
                        ans++;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return ans/2;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends