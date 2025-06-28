class Solution {
public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // Sort array b to perform binary search
        sort(b.begin(), b.end());
        
        vector<int> ans;
        
        // For each element in a, find how many elements in b are <= to a[i]
        for (int i = 0; i < a.size(); i++) {
            // lower_bound gives the first position where elements in b are >= a[i]
            int p = lower_bound(b.begin(), b.end(), a[i] + 1) - b.begin();
            ans.push_back(p); // p gives the count of elements <= a[i]
        }
        
        return ans;
    }
};