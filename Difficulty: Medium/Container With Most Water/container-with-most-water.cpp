//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        int ans=0;
        int low=0,high=n-1;
        while(low<high){
            int res=min(arr[low],arr[high])*(high-low);
            ans=max(ans,res);
            if(arr[low]<arr[high])
            low++;
            else
            high--;
        }
        return ans;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends