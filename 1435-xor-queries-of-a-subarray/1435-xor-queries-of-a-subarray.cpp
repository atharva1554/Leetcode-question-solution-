class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {   long long int x=0;
            for(int j=queries[i][0];j<=queries[i][1];j++)
            {
                x=x^arr[j];
            }
            ans.push_back(x);
        }
        return ans;
    }
};