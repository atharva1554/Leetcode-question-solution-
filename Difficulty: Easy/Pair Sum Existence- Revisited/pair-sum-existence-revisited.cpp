//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int sumExists(int arr[], int n, int sum) {
        // Map to track frequency of elements
        map<int, int> mpp;
        
        // Iterate through the array
        for (int i = 0; i < n; i++) {
            // If sum - arr[i] is already in the map, we found a pair
            if (mpp[sum - arr[i]] > 0) {
                return 1;
            }
            // Insert arr[i] into the map
            mpp[arr[i]]++;
        }

        return 0; // No such pair found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, sum;
        cin >> n ;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin>>sum;
        Solution ob;
        auto ans = ob.sumExists(arr, n, sum);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends