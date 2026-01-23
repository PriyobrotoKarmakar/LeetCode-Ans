class Solution {
public:
    void dfs(unordered_map<int, list<int>>& adj,int& v,vector<bool>& isVisited){
        isVisited[v] = true;

        for(auto u: adj[v]){
            if(!isVisited[u]){
                dfs(adj,u,isVisited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, list<int>> adj;
        int n = isConnected.size();
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < isConnected[u].size(); v++) {
                if (isConnected[u][v] == 1 && u!=v) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        vector<bool> isVisited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                dfs(adj, i, isVisited);
                ans++;
            }
        }
        return ans;
    }
};