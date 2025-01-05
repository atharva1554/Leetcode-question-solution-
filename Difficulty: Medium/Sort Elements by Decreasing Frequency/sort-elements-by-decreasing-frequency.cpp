//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
   vector<int> sortByFreq(vector<int>& arr) {
    // Step 1: Count frequency of each element
    unordered_map<int, int> freq_map;
    for (int num : arr) {
        freq_map[num]++;
    }

    // Step 2: Create a vector of pairs (frequency, element)
    vector<pair<int, int>> freq_vector;
    for (auto& entry : freq_map) {
        freq_vector.push_back({entry.second, entry.first});
    }

    // Step 3: Sort the vector of pairs
    // Sort by frequency in descending order, and by element in ascending order in case of a tie
    sort(freq_vector.begin(), freq_vector.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;  // If frequencies are the same, sort by element value (ascending)
        }
        return a.first > b.first;  // Sort by frequency (descending)
    });

    // Step 4: Build the result array
    vector<int> result;
    for (auto& entry : freq_vector) {
        int frequency = entry.first;
        int element = entry.second;
        // Add the element to the result array based on its frequency
        for (int i = 0; i < frequency; i++) {
            result.push_back(element);
        }
    }

    return result;
}
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends