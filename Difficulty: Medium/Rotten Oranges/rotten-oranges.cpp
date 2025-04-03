//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        int cntFresh = 0, cnt=0, maxTime=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 2){
                    q.push({0, {i,j}});
                    vis[i][j] = 2;
                }
                if(mat[i][j] == 1)
                    cntFresh++;
            }
        }
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int tm = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            maxTime = max(maxTime, tm);
            
            for(int i=0; i<4; i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol] == 1
                && vis[nrow][ncol] != 2){
                    vis[nrow][ncol] = 2;
                    q.push({tm+1, {nrow, ncol}});
                    cnt++;
                }
            }
        }
        
        if(cnt != cntFresh)
            return -1;
            
        return maxTime;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends