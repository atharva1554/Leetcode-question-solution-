//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++



class Solution {
public:
    int longestKSubstr(string &s, int k) {
        // Initialize variables
        unordered_map<char, int> mpp;  // To store character frequencies
        int left = 0, ans = -1;  // left pointer and answer variable

        // Iterate through the string with the right pointer
        for (int right = 0; right < s.size(); right++) {
            // Add the current character to the map
            mpp[s[right]]++;

            // If the number of distinct characters exceeds k, shrink the window from the left
            while (mpp.size() > k) {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) {
                    mpp.erase(s[left]);  // Remove character from map if its frequency becomes zero
                }
                left++;  // Move the left pointer
            }

            // If we have exactly k distinct characters, calculate the window size
            if (mpp.size() == k) {
                ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends