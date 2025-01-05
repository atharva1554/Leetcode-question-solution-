//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string maximumFrequency(string &str) {
        vector<string> words;
        string word;

        // Split words using stringstream
        stringstream ss(str);
        while (ss >> word) {
            words.push_back(word);
        }

        // Frequency map
        unordered_map<string, int> freqMap;
        int maxFrequency = 0;

        // Count frequencies and track maximum frequency
        for (const string &w : words) {
            freqMap[w]++;
            maxFrequency = max(maxFrequency, freqMap[w]);
        }

        // Find the first word with maximum frequency in input order
        for (const string &w : words) {
            if (freqMap[w] == maxFrequency) {
                return w + " " + to_string(maxFrequency);
            }
        }

        // Handle empty string case
        return "";
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);
        Solution ob;

        cout << ob.maximumFrequency(str) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends