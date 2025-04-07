//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> findTopo(int V, vector<int> &inDeg, vector<int> adj[]){
        queue<int> q;
        vector<int> res;
        
        for(int i=0; i<V; i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        
        while(q.size()>0){
            int node = q.front(); q.pop();
            res.push_back(node);
            
            for(int &adjNode:adj[node]){
                inDeg[adjNode] -= 1;
                if(inDeg[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }
        
        return res;
    }
    
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        vector<int> inDeg(V, 0);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            inDeg[v] += 1;
        }
        
        if(findTopo(V, inDeg, adj).size() == V){
            return false;
        }
        
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends