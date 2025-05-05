//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++



class Solution {
  public:
    bool AllBigOnRight(vector<int>&arr, 
    int mid, int target, int &ans)
    {
        int a = arr[mid], b = INT_MAX;
        if(mid - 1 > -1)
        {
            if(arr[mid - 1] == target)
            {
                ans = mid - 1;
            }
        }
        if(mid + 1 < arr.size())
        {
            b = arr[mid + 1];
        }
        if(b == target)
        {
            ans = mid + 1;
            
        }
        return min(a, b) > target;
    }
    void CompareAndFind(vector<int>&arr, int target, 
    int &ans, int l, int r)
    {
        int mid = (l + r)/ 2;
        // cout<<"mid "<<mid;
        // cout<<" l "<<l<<" r "<<r<<endl;
        if(l > r)return;
        if(ans != -1)return;
        
        if(arr[mid] == target)
        {
            ans = mid;
            return;
        }
        if(AllBigOnRight(arr, mid, target, ans))
        {
            CompareAndFind(arr, target, ans, l, mid - 1);
        }
        else
        {
            CompareAndFind(arr, target, ans, mid + 1, r);
        }
    }
    int findTarget(vector<int>& arr, int target) {
        int ans = -1, n = arr.size();
        CompareAndFind(arr, target, ans, 0, n - 1);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends