//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // Map to store the last position of each character
        map<char, int> mpp;
        int ans = 0, start = 0; // `start` is the beginning of the current substring
        
        for (int i = 0; i < s.size(); i++) {
            // If the character is found in the map and is within the current substring
            if (mpp.find(s[i]) != mpp.end() && mpp[s[i]] >= start) {
                start = mpp[s[i]] + 1; // Move `start` to avoid the repeating character
            }
            mpp[s[i]] = i; // Update the last position of the character
            ans = max(ans, i - start + 1); // Update the maximum length
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends