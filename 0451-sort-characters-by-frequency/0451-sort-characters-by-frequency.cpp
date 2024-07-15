class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,long long int>mpp;
        long long  int n=s.size();
        for(long long int i=0;i<n;i++)
        {
            mpp[s[i]]++;
        }
        string a="";
    
    cout<<n<<endl;

         // Create a vector of pairs (frequency, character)
        vector<pair<int, char>> freqVec;
        for (auto it : mpp) {
            freqVec.push_back({it.second, it.first});
        }

        // Sort the vector by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first > b.first;
        });

        // Build the result string
        string result;
        for (auto it : freqVec) {
            result += string(it.first, it.second);
        }

        return result;
    }
};