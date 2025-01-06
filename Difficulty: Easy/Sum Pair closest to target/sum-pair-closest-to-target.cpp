//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int tgt) {
        if (arr.size() < 2) return {};
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() - 1, closest = INT_MAX;
        vector<int> res;

        while (l < r) {
            int sum = arr[l] + arr[r];
            int diff = abs(sum - tgt);
            int range = abs(arr[r] - arr[l]);

            if (diff < abs(closest - tgt) || 
                (diff == abs(closest - tgt) && 
                 (res.empty() || range > abs(res[1] - res[0])))) {
                closest = sum;
                res = {arr[l], arr[r]};
            }

            if (sum < tgt) l++;
            else r--;
        }

        return res;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends