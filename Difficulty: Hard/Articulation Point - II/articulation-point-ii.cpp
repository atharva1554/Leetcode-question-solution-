//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    void dfs(int u, int parent, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<bool>& vis, vector<bool>& isAP, int& timer) {
        vis[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;

        for(auto v : adj[u]) {
            if(v == parent) continue; // Ignore the edge to parent

            if(!vis[v]) {
                children++;
                dfs(v, u, adj, disc, low, vis, isAP, timer);
                low[u] = min(low[u], low[v]);

                // Articulation Point Condition
                if(parent != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            }
            else {
                low[u] = min(low[u], disc[v]); // Back edge
            }
        }

        // Special case for root node
        if(parent == -1 && children > 1)
            isAP[u] = true;
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        
        // Build adjacency list
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(V, -1);   // Discovery time
        vector<int> low(V, -1);    // Lowest discovery time reachable
        vector<bool> vis(V, false);
        vector<bool> isAP(V, false); // To mark articulation points
        int timer = 0;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, -1, adj, disc, low, vis, isAP, timer);
            }
        }

        vector<int> result;
        for(int i = 0; i < V; i++) {
            if(isAP[i])
                result.push_back(i);
        }

        if(result.empty())
            return {-1};

        sort(result.begin(), result.end()); // As per problem requirement
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends