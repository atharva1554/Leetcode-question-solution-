//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int fun(string s);

int main() {
    int tt;
    string s;
    cin >> tt;
    while (tt--) {
        cin >> s;
        cout<<fun(s)<<endl;
        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends




int fun(string s) {
    // Map to track substrings
    map<string, int> mpp;
    int ans = 0;

    // Traverse the string to extract substrings of size 2
    for (int i = 1; i < s.size(); i++) {
        string a = s.substr(i - 1, 2); // Extract substring of size 2
        if (mpp[a] == 0) { // Count distinct substrings
            ans++;
        }
        mpp[a]++;
    }

    return ans;
}
