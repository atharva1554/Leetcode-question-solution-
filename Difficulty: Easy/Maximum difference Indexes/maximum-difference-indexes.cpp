//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxGap(vector<int>& arr) {
        // code here
        int ans=0;
        map<int,int>mpp;
        for(int i=0;i<arr.size();i++)
        {
            if(mpp[arr[i]]==0)
            {
                mpp[arr[i]]=i+1;
            }
            else
            {
                ans=max(ans,i+1-mpp[arr[i]]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Consume the newline character

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution solution;
        cout << solution.maxGap(arr) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends