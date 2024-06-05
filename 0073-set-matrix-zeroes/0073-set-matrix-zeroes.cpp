class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size();
    int n=matrix[0].size();
   vector<vector<int>>a;
   vector<int>b;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==0)
            {
              b.push_back(1);
            }
            else
            {
               b.push_back(0);
            }
        }
        a.push_back(b);
        b.clear();
    }


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
               for(int k=0;k<m;k++)
               {
                matrix[k][j]=0;
               }
               for(int k=0;k<n;k++)
               {
                matrix[i][k]=0;
               }
            }
           
        }
    }

     
    }
};