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
    void bfs(unordered_map<int, list<int>>& adj,int& v,vector<bool>& isVisited){
        queue<int> q;
        q.push(v);
        isVisited[v] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto u: adj[node]){
                if(!isVisited[u]){
                    isVisited[u] = true;
                    q.push(u);
                }
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
                bfs(adj, i, isVisited);
                ans++;
            }
        }
        return ans;
    }
};