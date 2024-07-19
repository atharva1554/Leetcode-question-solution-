#include<bits/stdc++.h>
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>r;
        vector<int>c;
        int m=matrix.size();
        int n=matrix[0].size();
        for (int i=0;i<m;i++)
        {   int x=INT_MAX;
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<=x)
                {
                    x=matrix[i][j];
                }
               
            }
             r.push_back(x);
        }
        for(int j=0;j<n;j++)
        {
              int x=0;
              for(int i=0;i<m;i++)
              {
                if(matrix[i][j]>=x)
                {
                    x=matrix[i][j];
                }
              }
              c.push_back(x);
        }
        vector<int>ans;
        for(int i=0;i<c.size();i++)
        {
            for(int j=0;j<r.size();j++)
            {
                if(c[i]==r[j])
                {
                    ans.push_back(c[i]);
                }
            }
        }
        return ans;
        return r;
    }
};