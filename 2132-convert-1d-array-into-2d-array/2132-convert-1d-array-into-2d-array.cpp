class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
       vector<vector<int>>ans;
       vector<int>b;
        int k=0;
        if((m)*(n)!=original.size())
        {
            return ans;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                b.push_back(original[k]);
                k++;
            }
            ans.push_back(b);
            b.clear();
        }
        return ans;
    }
};