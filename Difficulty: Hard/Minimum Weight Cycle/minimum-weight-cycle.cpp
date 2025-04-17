//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
         vector<vector<pair<int, int>>> adj(V);
    for (auto& e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    int minCycle = INT_MAX;

    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];

        // Temporarily remove edge (u, v)
        auto it1 = remove_if(adj[u].begin(), adj[u].end(), [&](pair<int, int> p) { return p.first == v && p.second == w; });
        adj[u].erase(it1, adj[u].end());

        auto it2 = remove_if(adj[v].begin(), adj[v].end(), [&](pair<int, int> p) { return p.first == u && p.second == w; });
        adj[v].erase(it2, adj[v].end());

        // Dijkstra from u to v
        vector<int> dist(V, INT_MAX);
        dist[u] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, u});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (d > dist[node]) continue;
            for (auto it : adj[node]) {
                int nei = it.first;
                int wt = it.second;
                if (dist[nei] > d + wt) {
                    dist[nei] = d + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        if (dist[v] != INT_MAX)
            minCycle = min(minCycle, dist[v] + w);

        // Restore edge (u, v)
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    return (minCycle == INT_MAX ? -1 : minCycle);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends