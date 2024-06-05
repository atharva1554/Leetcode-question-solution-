class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>a;
        a=matrix;
        for(int i=0;i<n;i++)
        {
            for(int j=0,k=n-1;j<n,k>=0;j++,k--)
            {
                int x=matrix[i][j];
                matrix[i][j]=a[k][i];
                
            }
        }
    }
};