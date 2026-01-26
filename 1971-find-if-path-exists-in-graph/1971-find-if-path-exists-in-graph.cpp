class Solution {
public:
    bool dfs(int source, int destination, unordered_map<int, list<int>>& adj,
             vector<bool>& visited) {
        if (source == destination)
            return true;
        else if (visited[source])
            return false;
        visited[source] = true;
        for (auto u : adj[source]) {
            if (dfs(u, destination, adj, visited))
                return true;
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, list<int>> adj;
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n);
        return dfs(source, destination, adj, visited);
    }
};