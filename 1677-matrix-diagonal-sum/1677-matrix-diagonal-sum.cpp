class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int a=0;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0,j=0;i<n,j<m;i++,j++)
        {
              a=a+mat[i][j];
        }
         for(int i=0,j=m-1;i<n,j>=0;i++,j--)
        {
              if(i==j)
              {
                continue;
              }
              else
              {
                  a=a+mat[i][j];
              }
        }
        return a;
    }
};