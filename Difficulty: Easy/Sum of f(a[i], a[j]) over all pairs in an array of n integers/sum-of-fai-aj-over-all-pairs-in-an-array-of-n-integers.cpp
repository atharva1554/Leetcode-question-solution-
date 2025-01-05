//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:

    long long sum(vector<int>& a) {
   
    unordered_map<int, int> cnt;
 
    long long ans = 0,pre_sum = 0;
    int n=a.size();
    for (int i = 0; i < n; i++) {
        ans += (i * a[i]) - pre_sum;
        pre_sum += a[i];
 
      
        if (cnt[a[i] - 1]) 
        
            ans -= cnt[a[i] - 1]; 
        
        if (cnt[a[i] + 1])
       
            ans += cnt[a[i] + 1]; 
        cnt[a[i]]++;
    }
    return ans;
    }
};


//{ Driver Code Starts.
//  Driver code
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
        Solution ob;
        cout << ob.sum(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends