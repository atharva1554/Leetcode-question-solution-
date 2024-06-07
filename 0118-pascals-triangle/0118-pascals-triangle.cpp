class Solution {
public:
    vector<int>getrow(int row)
    {
        long long ans=1;
        vector<int>ansrow;
        ansrow.push_back(ans);
        for(int i=1;i<row;i++)
        {
            ans=ans*(row-i);
            ans=ans/(i);
              ansrow.push_back(ans);
        }
      return ansrow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>a;
        for(int i=1;i<=numRows;i++)
        {
            a.push_back(getrow(i));
        }
        return a;
    }
};