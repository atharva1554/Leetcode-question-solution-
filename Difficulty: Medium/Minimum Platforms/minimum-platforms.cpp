//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
         sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
 
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
    }
};


//{ Driver Code Starts.
//  Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        vector<int> dep(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++) {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends