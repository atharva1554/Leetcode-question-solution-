//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        visited[0] = true;
        int sum = 0;

        // Add all edges from node 0
        for (int i = 1; i < n; i++) {
            int dis = abs(houses[i][0] - houses[0][0]) + abs(houses[i][1] - houses[0][1]);
            pq.push({dis, i});
        }

        while (!pq.empty()) {
            
            auto it = pq.top();
            int cost=it.first;
            int node=it.second;
            pq.pop();

            if (visited[node]) continue;

            visited[node] = true;
            sum += cost;

            // Add all edges from current node to unvisited nodes
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    int dis = abs(houses[i][0] - houses[node][0]) + abs(houses[i][1] - houses[node][1]);
                    pq.push({dis, i});
                }
            }
        }

        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends