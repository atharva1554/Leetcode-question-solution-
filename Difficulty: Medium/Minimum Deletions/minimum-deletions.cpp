class Solution {
  public:
    int solve(int i,int j,string& s,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(i == j)return 1;
        
        if(dp[i][j]  !=-1)return dp[i][j];
        if(s[i] == s[j]){
            return dp[i][j]= solve(i+1,j-1,s,dp)+2;
        }
        return dp[i][j]=max(solve(i+1,j,s,dp),solve(i,j-1,s,dp));
    }
    int minDeletions(string s) {
        int n  = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return n- solve(0,n-1,s,dp);
        
    }
};