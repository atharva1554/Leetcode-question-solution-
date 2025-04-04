//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool helper(int node,int parent,vector<bool>& visited,vector<int> adj[])
    {
        visited[node] = true;
        
        for(auto neighbour : adj[node])
        {
            if(visited[neighbour] == false)
            {
                if(helper(neighbour,node,visited,adj))
                    return true;
            }
            else
            {
                if(neighbour != parent)
                    return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<bool> visited(V,false);
        vector<int> adj[V];
        for(auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;++i)
        {
            if(visited[i] == true)
                continue;
            
            if(helper(i,-1,visited,adj))
                return true;
        }
        return false;
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends