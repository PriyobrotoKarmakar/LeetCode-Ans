class Solution {
public:
    int ans = 0;
    void dfs(int u, unordered_map<int, list<pair<int, int>>>& adj,
             vector<bool>& visited) {
        visited[u] = true;
        for (auto pair : adj[u]) {
            int v = pair.first;
            int path = pair.second;
            if (!visited[v]) {
                if (path == 1)
                    ans++;
                dfs(v, adj, visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto edge : connections) {
            adj[edge[0]].push_back({edge[1], 1});
            adj[edge[1]].push_back({edge[0], 0});
        }
        vector<bool> visited(n);
        dfs(0, adj, visited);
        return ans;
    }
};