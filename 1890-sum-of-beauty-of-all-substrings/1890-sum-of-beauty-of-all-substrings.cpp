class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        // Iterate over each starting point of substrings
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0); // Frequency vector for characters
            // Iterate over each ending point of substrings
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++; // Update frequency of current character
                int minFreq = INT_MAX, maxFreq = INT_MIN;
                
                // Calculate min and max frequencies in the current substring
                for (int k = 0; k < 26; ++k) {
                    if (freq[k] > 0) {
                        minFreq = min(minFreq, freq[k]);
                        maxFreq = max(maxFreq, freq[k]);
                    }
                }
                
                ans += maxFreq - minFreq; // Add the beauty value of the current substring
            }
        }

        return ans;
    }
};